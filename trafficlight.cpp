#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

extern int dir;

int detectTrafficLight(Mat &image)
{
    //Mat image = imread("2.jpg");
    int red_val = 170;
    int green_val = 50;
    Mat hsv;
    Mat red_mask;
    Mat green_mask;
    cvtColor(image, hsv, CV_BGR2HSV);
    //define range of RED color in HSV
    int r_lower[3] = { red_val - 10,100,100 };
    int r_upper[3] = { red_val + 10,255,255 };
    //define range of Green color in HSV
    int g_lower[3] = { green_val - 10,100,100 };
    int g_upper[3] = { green_val + 40,255,255 };
    //define range of Yellow color in HSV
    //int y_lower[3] = {};
    //int y_upper[3] = {};
    vector<int> red_lower(r_lower,r_lower+3);
    vector<int> red_upper(r_upper, r_upper+3);
    vector<int> green_lower(g_lower, g_lower+3);
    vector<int> green_upper(g_upper, g_upper+3);
    inRange(hsv, red_lower, red_upper, red_mask);
    inRange(hsv, green_lower, green_upper, green_mask);
    Mat red_res;
    Mat green_res;
    bitwise_and(image, image, red_res, red_mask);
    bitwise_and(image, image, green_res, green_mask);
    //Structuring Element
    Mat kernel = getStructuringElement(MORPH_ELLIPSE,Size(3,3));
    //Morphological Closing
    Mat red_closing;
    Mat green_closing;
    morphologyEx(red_res, red_closing, MORPH_CLOSE, kernel);
    morphologyEx(green_res, green_closing, MORPH_CLOSE, kernel);
    Mat red_gray, green_gray;
    cvtColor(red_closing, red_gray,CV_BGR2GRAY);
    cvtColor(green_closing, green_gray, CV_BGR2GRAY);
    Mat red_bw, green_bw;
    threshold(red_gray, red_bw, 128, 255, THRESH_BINARY | THRESH_OTSU);
    threshold(green_gray, green_bw, 128, 255, THRESH_BINARY | THRESH_OTSU);
    int red_black = countNonZero(red_bw);
    int green_black = countNonZero(green_bw);
    cout << "red_black:"<<red_black<<endl;
    cout << "green_black:"<<green_black<<endl;
    //imshow("g", green_bw);
    //cout << (red_black > green_black ? "red" : "green") << endl;
    if(red_black>2000)
    {dir = 0;}
    if(green_black>2000)
    {dir = 1;}
    
}

//int main(int argc, char ** argv)
void *trafficlight(void *arg)
{
    VideoCapture video =  VideoCapture(0);
    Mat image;
    while(video.isOpened())
    {
        video.read(image);
        //imshow("rgb", image);
        detectTrafficLight(image);
        cvWaitKey(33);
    }
    waitKey();
    return 0;
}
