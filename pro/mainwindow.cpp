#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "thirdwindow.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    secondwindow secwindow;
    secwindow.setModal(true); 
    if(count_2 == 1){
        secwindow.exec();
    }
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 3;j++){
            arranged_balls[i][j] = secwindow.get_arranged_balls(i, j);
        }
    }
    count_2 += 1;
}

void MainWindow::on_pushButton_3_clicked()
{
    thirdwindow thiwindow;
    thiwindow.setModal(true);
    if(count_3 == 1){
        thiwindow.exec();
    }
    for(int i = 0;i < 7;i++){
        for(int j = 0;j < 3;j++){
            arranged_cubes[i][j] = thiwindow.get_arranged_cubes(i, j);
        }
    }
    count_3 += 1;
}

void MainWindow::on_pushButton_clicked()
{
    if(count_2 > 1 && count_3 > 1){
        close();
    }
}
