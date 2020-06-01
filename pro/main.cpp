#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>
#include <qfile.h>

#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();

    enum Items {ball = 1, cube = 2};
   // enum Colours {blue = 0, red = 1, green = 2, yellow = 3, black = 4, white = 5, pink = 6, none = 7};
    enum Field {fie1, fie2, fie3, none};
    Items item;
    Field field;

    Mat image, hsv, hsvB, grayB, gray, mask;
        int width, length, white_pix, black_pix, all_pix, x, y;
        unsigned n, flag;
        vector<Vec3f> circles;

        for(int i = 0;i < 7;i++){
            for(int j = 0;j < 3;j++){
                cout<< "AAA"<<w.arranged_balls[i][j]<<endl;
            }
        }

        for(int i = 0;i < 7;i++){
            for(int j = 0;j < 3;j++){
                cout<< "BBB"<<w.arranged_cubes[i][j]<<endl;
            }
        }
        QFile file(":/slike/image13.png");
        if(file.open(QIODevice::ReadOnly))
        {
            qint64 sz = file.size();
            vector<uchar> buf(sz);
            file.read((char*)buf.data(), sz);
            image = imdecode(buf,  CV_LOAD_IMAGE_UNCHANGED);
        }
        else
            cout<<"File is not open"<<endl;

        /*image = imread("image2.jpg", 1);
        if(! image.data) {
            cout<<"Could not open or find the image"<<endl ;
            return -1;
        }*/

        cvtColor(image, hsv, COLOR_BGR2HSV, 0);
        medianBlur(hsv, hsvB, 5);
        cvtColor(image, gray, COLOR_BGR2GRAY, 0);
        medianBlur(gray, grayB, 5);


        width = image.cols;
        length = image.rows;
        printf("length = %d\n", length);
        printf("width = %d\n", width);

        n = 0;
        flag = 0;
        while(flag == 0){
            switch (n){
                case 0:
                    inRange(hsvB, Scalar(110, 50, 50), Scalar(135, 255, 255), mask);
                    break;
                case 1:
                    inRange(hsvB, Scalar(0, 50, 50), Scalar(10, 255, 255), mask);
                    break;
                case 2:
                    inRange(hsvB, Scalar(45, 50, 50), Scalar(75, 255, 255), mask);
                    break;
                case 3:
                    inRange(hsvB, Scalar(15, 50, 50), Scalar(35, 255, 255), mask);
                    break;
                case 4:
                    inRange(hsvB, Scalar(0, 0, 0), Scalar(255, 55, 100), mask);
                    break;
                case 5:
                    inRange(hsvB, Scalar(0, 0, 0), Scalar(0, 0, 255), mask);
                    break;
                case 6:
                    inRange(hsvB, Scalar(135, 50, 50), Scalar(170, 255, 255), mask);
                    break;
                default:
                    cout<< ""<<endl;
                    break;
            }

            white_pix = 0;
            black_pix = 0;
            all_pix = width * length;
            for(y = 0; y < width; y++){
                for(x = 0; x < width; x++){
                if(mask.at<int>(y, x) != 0)
                    white_pix += 1;
                else
                    black_pix += 1;
                }
            }
      /*      cout<< "Ukupno piksela " << all_pix <<endl;
            cout<< "Beli pikseli " << white_pix <<endl;
            cout<< "Crni pikseli " << black_pix<<endl;   */

            if((all_pix < white_pix * 2) || n == 7)
                    flag = 1;
        n += 1;

        }

        n -= 1;

        HoughCircles( grayB, circles, CV_HOUGH_GRADIENT, 1, 80, 70, 50, 150, 380);
        cout<<"Number of circles: "<< circles.size() <<endl;
        if(circles.size() >= 1){
            cout<< "BALL"<< endl;
            item = ball;
        }
        else{
            cout<< "CUBE"<< endl;
            item = cube;
        }

        if(n == 0){
            cout<< "BLUE" <<endl;
            if(item == ball){
                if(w.arranged_balls[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_balls[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_balls[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged ball"<<endl;
                }
            }
            if(item == cube){
                if(w.arranged_cubes[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_cubes[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_cubes[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged cube"<<endl;
                }
            }

        }
        if(n == 1){
            cout<< "RED" <<endl;
            if(item == ball){
                if(w.arranged_balls[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_balls[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_balls[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged ball"<<endl;
                }
            }
            if(item == cube){
                if(w.arranged_cubes[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_cubes[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_cubes[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged cube"<<endl;
                }
            }
        }
        if(n == 2){
            cout<< "GREEN" <<endl;
            if(item == ball){
                if(w.arranged_balls[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_balls[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_balls[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged ball"<<endl;
                }
            }
            if(item == cube){
                if(w.arranged_cubes[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_cubes[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_cubes[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged cube"<<endl;
                }
            }
        }
        if(n == 3){
            cout<< "YELLOW" <<endl;
            if(item == ball){
                if(w.arranged_balls[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_balls[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_balls[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged ball"<<endl;
                }
            }
            if(item == cube){
                if(w.arranged_cubes[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_cubes[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_cubes[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged cube"<<endl;
                }
            }
        }
        if(n == 4){
            cout<< "BLACK" <<endl;
            if(item == ball){
                if(w.arranged_balls[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_balls[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_balls[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged ball"<<endl;
                }
            }
            if(item == cube){
                if(w.arranged_cubes[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_cubes[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_cubes[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged cube"<<endl;
                }
            }
        }
        if(n == 5){
            cout<< "WHITE" <<endl;
            if(item == ball){
                if(w.arranged_balls[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_balls[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_balls[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged ball"<<endl;
                }
            }
            if(item == cube){
                if(w.arranged_cubes[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_cubes[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_cubes[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged cube"<<endl;
                }
            }
        }
        if(n == 6){
            cout<< "PINK" <<endl;
            if(item == ball){
                if(w.arranged_balls[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_balls[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_balls[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged ball"<<endl;
                }
            }
            if(item == cube){
                if(w.arranged_cubes[n][0] == 0){
                    field = fie1;
                    cout<<"FIELD1"<<endl;
                }
                else if(w.arranged_cubes[n][1] == 1){
                    field = fie2;
                    cout<<"FIELD2"<<endl;
                }
                else if(w.arranged_cubes[n][2] == 2){
                    field = fie3;
                    cout<<"FIELD3"<<endl;
                }
                else{
                    field = none;
                    cout<<"No arranged cube"<<endl;
                }
            }
        }
        if(n == 7){
            cout<< "NONE" <<endl;
        }

        //imshow("M", mask);
        //imshow("H", hsvB);
        waitKey(0);
        destroyAllWindows();


    return 0;
}
