import tkinter as tk
import requests
import threading
import time
from datetime import datetime

# Replace 'YOUR_API_KEY' with your actual API key from weatherapi.com
API_KEY = 'd47ed1bd8562441d8c764521232907'
BASE_URL = 'http://api.weatherapi.com/v1/current.json'

class WeatherApp(tk.Tk):
    def __init__(self):
        super().__init__()
        self.title("Weather App")
        self.geometry("1440x720")
        self.configure(background='black')

        self.label = tk.Label(self, text="Weather", font=('Helvetica', 24, 'bold'), fg='white', bg='black')
        self.label.pack(pady=20)

        self.location_label = tk.Label(self, text="Enter your location:", font=('Helvetica', 18, 'bold'), fg='white', bg='black')
        self.location_label.pack()

        self.location_entry = tk.Entry(self, font=('Helvetica', 16))
        self.location_entry.pack(pady=10)

        self.enter_button = tk.Button(self, text="Enter", font=('Helvetica', 16, 'bold'), command=self.fetch_weather_data)
        self.enter_button.pack(pady=10)

        self.weather_data_label = tk.Label(self, text="", font=('Helvetica', 14), fg='white', bg='black')
        self.weather_data_label.pack(pady=20)

    def fetch_weather_data(self):
        location = self.location_entry.get()
        if location:
            url = f"{BASE_URL}?key={API_KEY}&q={location}"
            response = requests.get(url)
            data = response.json()
            self.update_weather_data(data)

    def update_weather_data(self, data):
        try:
            current_time = datetime.now().strftime(" %I:%M:%S %p %d-%m-%y ")
            lat = data['location']['lat']
            lon = data['location']['lon']
            country = data['location']['country']
            temperature = data['current']['temp_c']
            weather_condition = data['current']['condition']['text']
            cloud_coverage = data['current']['cloud']
            uv_index = data['current']['uv']
            wind_speed = data['current']['wind_kph']

            weather_info = f"Time: {current_time}\nLatitude: {lat}, Longitude: {lon}\nCountry: {country}\nTemperature: {temperature}°C\nWeather Condition: {weather_condition}\nCloud Coverage: {cloud_coverage}%\nUV Index: {uv_index}\nWind Speed: {wind_speed} kph"
            self.weather_data_label.config(text=weather_info)

        except KeyError:
            self.weather_data_label.config(text="Invalid location or API key")

    def update_data_continuously(self):
        self.fetch_weather_data()
        self.after(1000, self.update_data_continuously)

if __name__ == "__main__":
    app = WeatherApp()

    # Run the weather data update continuously for 1 hour
    threading.Thread(target=app.update_data_continuously).start()

    app.mainloop()
