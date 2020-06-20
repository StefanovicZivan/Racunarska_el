#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
#include "QDateTime"
#include "QMessageBox"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPixmap pix1(":/slike/im1.jpg");
    ui->label_2->setPixmap(pix1.scaled(75,75,Qt::KeepAspectRatio));

    QTime vreme (QTime::currentTime());
    h = vreme.hour();
    m = vreme.minute();
    s = vreme.second();


    myTimer1 = new QTimer(this);
    connect(myTimer1, SIGNAL(timeout()), this,SLOT(rtcReadTimeSlot()));
    myTimer1->start(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{

    QString ocitaj_v = ui->lineEdit->text();
    QString ocitaj_alarm = ui->lineEdit_2->text();
    QTime alarm = QTime::fromString(ocitaj_alarm, "HH:mm:ss");
    QTime vreme = QTime::fromString(ocitaj_v, "HH:mm:ss");
    h = vreme.hour();
    m = vreme.minute();
    s = vreme.second();
    c = 1;
    hh = alarm.hour();
    mm = alarm.minute();
    ss = alarm.second();
    if(!vreme.isValid()){
        QMessageBox::warning(this, "Time", "Nije uneto validno vreme");
    }

}
void Dialog::rtcReadTimeSlot()
{

    QTime t, alarm;
    QTime vreme;
    vreme.setHMS(h, m, s );
    alarm.setHMS(hh, mm, ss);
    t = vreme.addSecs(c);
    QString str = t.toString("hh : mm : ss");
    ui->label_5->setText(str);
    c++;

    if(t == alarm){
        QPixmap pix2(":/slike/im2.jpeg");
        ui->label_2->setPixmap(pix2.scaled(75,75,Qt::KeepAspectRatio));
    }
}
