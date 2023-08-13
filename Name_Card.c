#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[0m"
#define BG_YELLOW "\x1b[43m"

int main()
{
    printf("%s\t\t\t\t\t\t\tName Card\t%s",BG_YELLOW,AC_NORMAL);
    printf("%s\n\nName:%s\t\t\tMy name is Zombie12k.\t",AC_RED,AC_NORMAL);
    printf("%s\n\nID number:%s\t\t2322663",AC_MAGENTA,AC_NORMAL);
    printf("%s\n\nHobby:%s\t\t\tReading books and typing.\t",AC_GREEN,AC_NORMAL);
    printf("%s\n\nWhy I choose CSE:%s\tI choose Computer Science Engineering because from very young age I have a passion of how an application works and how to make an application. I have also made a discord bot which mimicks the works of the discontinued discord bot Rythm. I have also worked as a back end developer in some custom rom community but had to step down from it as HSC exam was coming closer. I also made calculator and tic tak toe game in python. And I can also continue my passion in typing if I choose Computer Science Engineering. So as I had some experience and have the passion in this programming world I choose Computer Science Engineering.\t",AC_YELLOW,AC_NORMAL);

    Beep(540, 1000);

    return 0;
}
