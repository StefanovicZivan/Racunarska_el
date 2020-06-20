#include "dialog.h"
#include "ui_dialog.h"


#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <wiringPiI2C.h>

#include "QDateTime"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    myTimer1 = new QTimer(this);
       connect(myTimer1, SIGNAL(timeout()), this,SLOT(rtcReadTimeSlot()));
       myTimer1->start(100);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::rtcReadTimeSlot()
{
    const char PCF8591 = 0x48; // adresa
    int fd;

    if(wiringPiSetup () == -1) exit (1);
            fd = wiringPiI2CSetup(PCF8591);


        wiringPiI2CReadReg8(fd, PCF8591 + 0) ;
        val1 = wiringPiI2CReadReg8(fd, PCF8591 + 0) ;
        printf("Vrednost osvetljenja = %d \n", val1);


        wiringPiI2CReadReg8(fd, PCF8591 + 3);
        val2 = wiringPiI2CReadReg8(fd, PCF8591 + 3) ;
        printf("Vrednost napona = %d \n", val2);

        ui->ddd->setValue(val2);
        ui->verticalSlider->setValue(val1);


}
