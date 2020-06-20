#include "dialog.h"
#include "ui_dialog.h"
#include <QLineEdit>

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





Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    int lcd,j = 0,a,b;
    QString line1, line2;
    line1 = ui->lineEdit->text();
    line2 = ui->lineEdit_2->text();
    char ch1[32], ch2[32];

    unsigned char* test1 = (unsigned char*) line1.data();
    unsigned char* test2 = (unsigned char*) line2.data();

    memcpy(l1, test1, 32);
    memcpy(l2, test2, 32);
    for(int i = 0;i < 33;i++){
        if((i % 2) == 0){
            ch1[j] = l1[i];
            ch2[j] = l2[i];
              j++;
       }
    }
    a = line1.size();
    b = line2.size();

     if(lcd = lcdInit(2, 16, 4, LCD_RS, LCD_E, LCD_D4,LCD_D5, LCD_D6, LCD_D7, 0, 0, 0, 0)){
            printf ("lcdInit nije uspeo! \n");
             // return -1 ;
     }
     lcdClear(lcd);
     for(int i = 0;i < a;i++){
         lcdPosition (lcd, i,0);
         lcdPuts (lcd, &ch1[i]);
     }
     for(int i = 0;i < b;i++){
         lcdPosition (lcd, i,1);
         lcdPuts (lcd, &ch2[i]);
     }

     sleep(4);

     lcdClear(lcd);

}
