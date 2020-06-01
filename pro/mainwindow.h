#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    unsigned count_2 = 1;
    unsigned count_3 = 1;
    int arranged_balls[7][3];
    int arranged_cubes[7][3];

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
