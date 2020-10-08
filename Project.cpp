#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <raspicam/raspicam_cv.h>
#include <unistd.h>

using namespace std;
using namespace cv;

#define TRIG 5
#define ECHO 6
#define POWER_SWITCH 15
#define LED1 27
#define LED2 28
#define LED3 29

//a function that controls the diodes
void led_manager(unsigned n){
	switch (n){
		case 0:
			cout<< "BLUE"<<endl;
			digitalWrite(LED1, HIGH);
			digitalWrite(LED2, HIGH);
			sleep(2);
			digitalWrite(LED1, LOW);
			digitalWrite(LED2, LOW);
			break;
		case 1:
			cout<< "RED"<<endl;
			digitalWrite(LED1, HIGH);
			sleep(2);
			digitalWrite(LED1, LOW);
			break;
		case 2:
			cout<< "GREEN"<<endl;
			digitalWrite(LED2, HIGH);
			sleep(2);
			digitalWrite(LED2, LOW);
			break;
		case 3:
			cout<< "BLACK"<<endl;
			digitalWrite(LED3, HIGH);
			sleep(2);
			digitalWrite(LED3, LOW);		
			break;
		case 4:
			cout<< "WHITE"<<endl;
			digitalWrite(LED1, HIGH);
			digitalWrite(LED3, HIGH);
			sleep(2);
			digitalWrite(LED1, LOW);
			digitalWrite(LED3, LOW);
			break;
		default:
			cout<< "No one color is recognized"<<endl;
			break;
	}	
}
//a function that controls the operation of the camera
Mat capture_pics(){
	Mat image;
	raspicam::RaspiCam_Cv Camera; //Cmaera object
	//Open camera 
	cout<<"Opening Camera..."<<endl;
	if (!Camera.open()) {
		cerr<<"Error opening camera"<<endl;
	}
	//wait a while until camera stabilizes
	cout<<"Sleeping for 2 secs"<<endl;
	sleep(2);
	Camera.grab();//capture
	Camera.retrieve(image);//get camera image
	Camera.release();//closed camera
			
	if(!image.data) {
		cout<<"Could not open the image"<<endl ;
	}
	return image;
}
//pin initialization
void setup() {
	//setup pin mode
	wiringPiSetup();
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
	pinMode(POWER_SWITCH, INPUT);
	pinMode(LED1, OUTPUT);
 	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);

    //TRIG pin must start LOW
    digitalWrite(TRIG, LOW);
    delayMicroseconds(10);
}
//distance calculation function
int get_cm() {
    //Send trig pulse
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(20);
    digitalWrite(TRIG, LOW);
 
    //Wait for echo start
    while(digitalRead(ECHO) == LOW);
 
    //Wait for echo end
    long startTime = micros();
    while(digitalRead(ECHO) == HIGH);
    long travelTime = micros() - startTime;
 
    //Get distance in cm
    int distance = travelTime / 58;
 
    return distance;
}

int main(){

	Mat image, hsv, hsvB, mask;
	int width, length, white_pix, black_pix, all_pix, x, y;
	int distance;
	unsigned n, flag, irq = 0;
   
	while(1){
		setup();	
		//waiting for interrupt
		if(digitalRead(POWER_SWITCH) == LOW && irq == 0){
			irq = 1;
			cout<<"Interrupt is recived"<<endl;
		}

		if(irq == 1){	
			distance = get_cm();
			cout<<"Distance: "<<distance<<" cm"<<endl;
			sleep(1);

			//controls the current distance
		  	if(distance > 2 && distance < 6 ){
				irq = 0;
				
				image = capture_pics();

				cvtColor(image, hsv, COLOR_BGR2HSV, 0);//hsv transformation of image
				medianBlur(hsv, hsvB, 5);//bluring of image

				width = image.cols;
				length = image.rows;
				
				n = 0;
				flag = 0;

				//the part where the image is processed
				while(flag == 0){
					switch (n){
						case 0://Blue
							inRange(hsvB, Scalar(80, 50, 50), Scalar(120, 255, 255), mask);		
						    break;
						case 1://Red
						    inRange(hsvB, Scalar(160, 50, 50), Scalar(190, 255, 255), mask); 	
						    break;
						case 2://Green
						    inRange(hsvB, Scalar(40, 50, 50), Scalar(90, 255, 255), mask);		
						    break;
						case 3://Black
						    inRange(hsvB, Scalar(0, 0, 0), Scalar(120, 255, 30), mask);			
						    break;
						case 4://White
						    inRange(hsvB, Scalar(0, 0, 0), Scalar(255, 100, 255), mask);		
						    break;
						default:
						    cout<< "?????"<<endl;
						    break;
						}

					white_pix = 0;
					black_pix = 0;
					all_pix = width * length;
					for(y = 0; y < length; y++){
						for(x = 0; x < width; x++){
							if(mask.at<int>(y, x) != 0)
						        white_pix += 1;
						    else
						        black_pix += 1;
						}
					}
						
					if((all_pix < white_pix * 2) || n == 5)
						flag = 1;
					n += 1;

				}
				n -= 1;
				
				led_manager(n);				

			/*	namedWindow("Image", WINDOW_NORMAL);
				resizeWindow("Image",800,600);
				imshow("Image", mask);
				waitKey(0);
				destroyAllWindows();  */

		  	}
		}
	}	

	return 0;
}









