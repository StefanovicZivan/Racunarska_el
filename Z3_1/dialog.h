#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "QTimer"
#include "QDateTime"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:


    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void rtcReadTimeSlot();

private:
    Ui::Dialog *ui;
    QTimer *myTimer1;
    int c = 1;
    int h, m, s;
    int hh, mm, ss;

};

#endif // DIALOG_H
