import psutil
import socket
import requests
import os

IPINFO_API_KEY = "84bfca15b8c268"  

def get_wifi_interface():
  
    for interface, stats in psutil.net_if_stats().items():
        if stats.isup and 'Wi-Fi' in interface:
            return interface
    return None

def get_wifi_speed():
    wifi_interface = get_wifi_interface()
    if wifi_interface:
        net_io = psutil.net_io_counters(pernic=True)
        wifi_stats = net_io.get(wifi_interface, None)
        return wifi_stats
    return None

def get_speed_in_megabytes(speed_in_bytes, interval):
    return speed_in_bytes / (interval * 1_000_000)

def get_remote_receiver(connections, local_address):
    for conn in connections:
        if conn.laddr.ip == local_address and conn.raddr:
            return conn.raddr.ip
    return None

def get_company_name(ip_address):
    url = f"https://ipinfo.io/{ip_address}?token={IPINFO_API_KEY}"
    response = requests.get(url)
    if response.status_code == 200:
        data = response.json()
        return data.get("org", "Unknown Company")
    return "Unknown Company"

def show_wifi_info(duration_hours=1, interval=0.01):
    print(f"Scanning every {interval:.2f} second(s) for {duration_hours} hour(s)...\n")
    start_time = time.time()
    try:
        prev_wifi_stats = get_wifi_speed()
        while True:
            current_wifi_stats = get_wifi_speed()
            if current_wifi_stats:
                upload_speed = get_speed_in_megabytes(current_wifi_stats.bytes_sent - prev_wifi_stats.bytes_sent, interval)
                download_speed = get_speed_in_megabytes(current_wifi_stats.bytes_recv - prev_wifi_stats.bytes_recv, interval)
                connections = psutil.net_connections(kind='inet')
                local_address = socket.gethostbyname(socket.gethostname())
                remote_receiver = get_remote_receiver(connections, local_address)
                company_name = get_company_name(remote_receiver)
                print("\r" + " " * 100, end='')  # Clear the line before printing new data
                print(f"\rWi-Fi Interface: {get_wifi_interface()} | Remote Receiver: {remote_receiver} ({company_name})")
                print(f"Upload Speed: {upload_speed:.2f} MB/s | Download Speed: {download_speed:.2f} MB/s", end='')
            prev_wifi_stats = current_wifi_stats
            time.sleep(interval)
            elapsed_time = time.time() - start_time
            if elapsed_time >= duration_hours * 3600:
                break
    except KeyboardInterrupt:
        print("\nMonitoring stopped.")

if __name__ == "__main__":
    import time
    show_wifi_info(duration_hours=2) 
