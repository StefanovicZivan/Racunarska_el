#include "dialog.h"
#include <QApplication>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/fcntl.h>

#define COLUMNS 16
#define LCD_RS 3
#define LCD_E 14
#define LCD_D4 4
#define LCD_D5 12
#define LCD_D6 13
#define LCD_D7 6

int main(int argc, char *argv[])
{


    wiringPiSetup();
    QApplication a(argc, argv);
    Dialog w;
    w.show();



    return a.exec();

}
