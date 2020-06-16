#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include "QDateTime"

#include "QTimer"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
   void rtcReadTimeSlot();

private:
    Ui::Dialog *ui;
    QTimer *myTimer1;
    int val1, val2;
};

#endif // DIALOG_H
