#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "QMessageBox"
#include <QLabel>
#include <QPixmap>

secondwindow::secondwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwindow)
{
    ui->setupUi(this);

    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 3;j++){
            arranged_balls[i][j] = 10;
        }
    }
    QPixmap pix1(":/slike/blue.png");
        ui->label->setPixmap(pix1);
    QPixmap pix2(":/slike/red.png");
        ui->label_2->setPixmap(pix2);
    QPixmap pix3(":/slike/green.png");
        ui->label_3->setPixmap(pix3);
    QPixmap pix4(":/slike/yellow.png");
        ui->label_4->setPixmap(pix4);
    QPixmap pix5(":/slike/black.png");
        ui->label_5->setPixmap(pix5);
    QPixmap pix6(":/slike/white.png");
        ui->label_6->setPixmap(pix6);
    QPixmap pix7(":/slike/pink.png");
        ui->label_7->setPixmap(pix7);
}

secondwindow::~secondwindow()
{
    delete ui;
}


void secondwindow::on_pushButton_clicked()
{
    int i, j;

    if(ui->radioButton->isChecked()){
        i = 0;
        j = 0;
        arranged_balls[i][j] = 0;
    }
    if(ui->radioButton_2->isChecked()){
        i = 0;
        j = 1;
        arranged_balls[i][j] = 1;
    }
    if(ui->radioButton_3->isChecked()){
        i = 0;
        j = 2;
        arranged_balls[i][j] = 2;
    }
    if(ui->radioButton_4->isChecked()){
        i = 1;
        j = 0;
        arranged_balls[i][j] = 0;
    }
    if(ui->radioButton_5->isChecked()){
        i = 1;
        j = 1;
        arranged_balls[i][j] = 1;
    }
    if(ui->radioButton_6->isChecked()){
        i = 1;
        j = 2;
        arranged_balls[i][j] = 2;
    }
    if(ui->radioButton_7->isChecked()){
        i = 2;
        j = 0;
        arranged_balls[i][j] = 0;
    }
    if(ui->radioButton_8->isChecked()){
        i = 2;
        j = 1;
        arranged_balls[i][j] = 1;
    }
    if(ui->radioButton_9->isChecked()){
        i = 2;
        j = 2;
        arranged_balls[i][j] = 2;
    }
    if(ui->radioButton_10->isChecked()){
        i = 3;
        j = 0;
        arranged_balls[i][j] = 0;
    }
    if(ui->radioButton_11->isChecked()){
        i = 3;
        j = 1;
        arranged_balls[i][j] = 1;
    }
    if(ui->radioButton_12->isChecked()){
        i = 3;
        j = 2;
        arranged_balls[i][j] = 2;
    }
    if(ui->radioButton_13->isChecked()){
        i = 4;
        j = 0;
        arranged_balls[i][j] = 0;
    }
    if(ui->radioButton_14->isChecked()){
        i = 4;
        j = 1;
        arranged_balls[i][j] = 1;
    }
    if(ui->radioButton_15->isChecked()){
        i = 4;
        j = 2;
        arranged_balls[i][j] = 2;
    }
    if(ui->radioButton_16->isChecked()){
        i = 5;
        j = 0;
        arranged_balls[i][j] = 0;
    }
    if(ui->radioButton_17->isChecked()){
        i = 5;
        j = 1;
        arranged_balls[i][j] = 1;
    }
    if(ui->radioButton_18->isChecked()){
        i = 5;
        j = 2;
        arranged_balls[i][j] = 2;
    }
    if(ui->radioButton_19->isChecked()){
        i = 6;
        j = 0;
        arranged_balls[i][j] = 0;
    }
    if(ui->radioButton_20->isChecked()){
        i = 6;
        j = 1;
        arranged_balls[i][j] = 1;
    }
    if(ui->radioButton_21->isChecked()){
        i = 6;
        j = 2;
        arranged_balls[i][j] = 2;
    }

    close();
}

int secondwindow::get_arranged_balls(int i, int j){
    return arranged_balls[i][j];
}

