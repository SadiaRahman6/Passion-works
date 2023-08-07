#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <taia.h>

void display12HourFormat(int hour, int min, int sec) {
    char *meridian = (hour >= 12) ? "PM" : "AM";
    if (hour > 12) {
        hour -= 12;
    } else if (hour == 0) {
        hour = 12;
    }
    printf("Current Local Time: %02d:%02d:%02d %s\n", hour, min, sec, meridian);
}

int main() {
    char region[100];
    struct taia now, local_time;
    tai_t current_tai;
    int fd;

    printf("Enter a region name: ");
    scanf("%s", region);

    fd = open("/etc/zoneinfo/UTC", O_RDONLY);
    if (fd == -1) {
        perror("Error opening UTC zoneinfo");
        return 1;
    }

    taia_now(&now);
    tai_unpack(&now.sec.x, &current_tai);

    if (tzload(region) == -1) {
        perror("Error loading time zone");
        return 1;
    }

    taia_tai(&local_time, &current_tai);
    taia_uint(&local_time, local_time.nano + (uint64_t)tz.tzh_timecnt[local_time.sec.x >> 32]);

    int local_hour = (int)(local_time.sec.x / 3600);
    int local_min = (int)((local_time.sec.x / 60) % 60);
    int local_sec = (int)(local_time.sec.x % 60);

    time_t start_time = time(NULL);
    time_t end_time = start_time + 6 * 3600;  // Run for 6 hours

    while (time(NULL) < end_time) {
        display12HourFormat(local_hour, local_min, local_sec);
        sleep(1);  // Update every second
        taia_now(&now);
        tai_unpack(&now.sec.x, &current_tai);
        taia_tai(&local_time, &current_tai);
        taia_uint(&local_time, local_time.nano + (uint64_t)tz.tzh_timecnt[local_time.sec.x >> 32]);
        local_hour = (int)(local_time.sec.x / 3600);
        local_min = (int)((local_time.sec.x / 60) % 60);
        local_sec = (int)(local_time.sec.x % 60);
    }

    close(fd);

    return 0;
}
