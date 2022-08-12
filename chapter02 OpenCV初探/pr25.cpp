// 根据拖动进度条的程度，设置视频的缩小比例。

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

cv::Mat g_frame_bgr, g_frame_pyr;
cv::VideoCapture g_cap;
int g_slider_position = 1;
void onTrackbarSlide( int pos, void * ){
    // Do nothing.
}

int main( int argc, char** argv ){
    cv::namedWindow( "Practice2_5", cv::WINDOW_AUTOSIZE ) ;
    int tempw = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int temph = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    if( argc == 1 ){
        g_cap.open( 0 );
    }
    else{
        g_cap.open( string(argv[1]) );
    }
    cv::createTrackbar( "Level", "Practice2_5", &g_slider_position, 4, NULL);
    for(;;){
        g_cap >> g_frame_bgr;
        if( g_frame_bgr.empty() ) break;
        if(g_slider_position > 1){
            int grade = g_slider_position;
            cv::pyrDown(g_frame_bgr, g_frame_pyr);
            for(int i = 0; i < grade - 2; i++){
                cv::pyrDown( g_frame_pyr, g_frame_pyr );
            }
        }
        else{
            g_frame_pyr = g_frame_bgr;
        }
        cv::imshow( "Practice2_5", g_frame_pyr );
        char c;
        if( argc == 1){
            c = (char) cv::waitKey(10);
        }
        else{
            c = (char) cv::waitKey(100);
        }
        if( c == 27 ){
            break;
        }
    }
}