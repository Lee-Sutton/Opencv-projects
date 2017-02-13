// Program to filter images based on colour
// Trackbar are used to interactively adjust the threshold limits
// Author: Lee Sutton
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

// Function declarations
void high_R_trackbar(int pos, void *);
void low_R_trackbar(int pos, void *);

void high_G_trackbar(int pos, void *);
void low_G_trackbar(int pos, void *);

void high_B_trackbar(int pos, void *);
void low_B_trackbar(int pos, void *);

// Global variables
const int slider_max = 255;
int slider;
int low_r = 0;
int low_b = 0;
int low_g = 0;
int high_r = 255;
int high_g = 255;
int high_b = 255;
Mat thresh_img, img;



int main()
{
    img = imread("/Users/Lee/MOOCS/OpenCV-Projects/C++-openCV/Opencv-tutorial/Opencv-tutorial/beach.png");
    // Create windows for the input image and the filtered image
    namedWindow("Trackbar app");
    namedWindow("Filtering");
    
    // Display the original image on the screen
    imshow("Trackbar app", img);
    
    // Display the filtered image
    inRange(img, Scalar(low_r, low_g, low_b), Scalar(high_r, high_g, high_b), thresh_img);
    imshow("Filtering", thresh_img);
    
    // Create a trackbar to interactively filter the red objects
    createTrackbar("High Red filter", "Filtering", &high_r, slider_max, high_R_trackbar);
    createTrackbar("Low Red Filter", "Filtering", &low_r, slider_max, low_R_trackbar);
    
    createTrackbar("High Green filter", "Filtering", &high_g, slider_max, high_G_trackbar);
    createTrackbar("Low Green Filter", "Filtering", &low_g, slider_max, low_G_trackbar);
    
    createTrackbar("High Blue filter", "Filtering", &high_b, slider_max, high_B_trackbar);
    createTrackbar("Low Blue Filter", "Filtering", &low_b, slider_max, low_B_trackbar);
    
    // Create the while loop to pause until the user presses q to quit
    while(char(waitKey(1)) != 'q') {}
    return 0;
}


// Callback function for trackbar event
void high_R_trackbar(int pos, void *)
{
    // First make sure the high red threshold is above the low red threshold
    high_r = max(high_r,low_r);
    inRange(img, Scalar(low_r, low_g, low_b), Scalar(high_r, high_g, high_b), thresh_img);
    setTrackbarPos("High Red Filter", "Filtering", pos);
    imshow("Filtering", thresh_img);
    cout << "The low range is (" << low_r << ", " << low_g << ", " << low_b <<")" << endl;
    cout << "The high range is (" << high_r << ", " << high_g << ", " << high_b <<")\n\n" << endl;
}

// Callback function for trackbar event
void low_R_trackbar(int pos, void *)
{
    // First make sure the high red threshold is above the low red threshold
    low_r = min(high_r,low_r);
    inRange(img, Scalar(low_r, low_g, low_b), Scalar(high_r, high_g, high_b), thresh_img);
    setTrackbarPos("Low Red Filter", "Filtering", pos);
    imshow("Filtering", thresh_img);
}

// Callback function for trackbar event
void high_G_trackbar(int pos, void *)
{
    // First make sure the high red threshold is above the low red threshold
    high_g = max(high_g,low_g);
    inRange(img, Scalar(low_r, low_g, low_b), Scalar(high_r, high_g, high_b), thresh_img);
    setTrackbarPos("High Green Filter", "Filtering", pos);
    imshow("Filtering", thresh_img);
}

// Callback function for trackbar event
void low_G_trackbar(int pos, void *)
{
    // First make sure the high red threshold is above the low red threshold
    low_g = min(high_g,low_g);
    inRange(img, Scalar(low_r, low_g, low_b), Scalar(high_r, high_g, high_b), thresh_img);
    setTrackbarPos("Low Green Filter", "Filtering", pos);
    imshow("Filtering", thresh_img);
}

// Callback function for trackbar event
void high_B_trackbar(int pos, void *)
{
    // First make sure the high red threshold is above the low red threshold
    high_b = max(high_b,low_b);
    inRange(img, Scalar(low_r, low_g, low_b), Scalar(high_r, high_g, high_b), thresh_img);
    setTrackbarPos("High Blue Filter", "Filtering", pos);
    imshow("Filtering", thresh_img);
}

// Callback function for trackbar event
void low_B_trackbar(int pos, void *)
{
    // First make sure the high red threshold is above the low red threshold
    low_b = min(high_b,low_b);
    inRange(img, Scalar(low_r, low_g, low_b), Scalar(high_r, high_g, high_b), thresh_img);
    setTrackbarPos("Low Blue Filter", "Filtering", pos);
    imshow("Filtering", thresh_img);
}
