#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class secondwindow;
}

class secondwindow : public QDialog
{
    Q_OBJECT

public:

    int arranged_balls[7][3];

    explicit secondwindow(QWidget *parent = 0);
    int get_arranged_balls(int, int);

    ~secondwindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::secondwindow *ui;

};

#endif // SECONDWINDOW_H
