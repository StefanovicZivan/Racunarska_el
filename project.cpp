#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>

using namespace cv;
using namespace std;


int main(int argc, char** argv) {

    Mat image, hsv, hsvB, edge, grayB, gray, mask;
    int width, length, white_pix, black_pix, all_pix, x, y, i;
    unsigned n, flag;
    vector<Vec3f> circles;

    image = imread("image3.jpg", 1);
    if(! image.data) {
        cout<<"Could not open or find the image"<<endl ;
    	return -1;
    }

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
	    	cout<< "Nesto ne valja"<<endl;
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
	cout<< "Ukupno piksela " << all_pix <<endl;
	cout<< "Beli pikseli " << white_pix <<endl;
	cout<< "Crni pikseli " << black_pix<<endl;

	if(all_pix < white_pix * 2)
            flag = 1;

	n += 1;
    }
    
    n -= 1;
    if(n == 0)
	cout<< "BLUE" <<endl;
    if(n == 1)
	cout<< "RED" <<endl;
    if(n == 2)
	cout<< "GREEN" <<endl;
    if(n == 3)
	cout<< "YELLOW" <<endl;
    if(n == 4)
	cout<< "BLACK" <<endl;
    if(n == 5)
	cout<< "WHITE" <<endl;
    if(n == 6)
	cout<< "PINK" <<endl;

    HoughCircles( grayB, circles, CV_HOUGH_GRADIENT, 1, 80, 70, 50, 150, 380);
    cout<<"Broj krugova: "<< circles.size() <<endl;
	
    if(circles.size() >= 1)
	cout<< "LOPTA"<< endl;
    else
	cout<< "KOCKA"<< endl;

    imshow("M", mask);
    imshow("H", hsvB);
    waitKey(0);
    destroyAllWindows();

return 0;
}








