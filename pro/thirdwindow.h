#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>

namespace Ui {
class thirdwindow;
}

class thirdwindow : public QDialog
{
    Q_OBJECT

public:

    int arranged_cubes[7][3];

    explicit thirdwindow(QWidget *parent = 0);
    int get_arranged_cubes(int, int);

    ~thirdwindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::thirdwindow *ui;
};

#endif // THIRDWINDOW_H
