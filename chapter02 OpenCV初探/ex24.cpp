#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0; // start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide( int pos, void * ){
    g_cap.set( cv::CAP_PROP_POS_FRAMES, pos );
    if( !g_dontset ){
        g_run = 1;
    }
}

int main( int argc, char** argv ){
    cv::namedWindow( "Example2_4", cv::WINDOW_AUTOSIZE );
    g_cap.open( string(argv[1]) );
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tempw  = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int temph  = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cout << "Video has " << frames << " frames of dimensions(" << tempw << ", " << temph << ")." << endl;

    cv::createTrackbar("Position", "Example2_4", &g_slider_position, frames, onTrackbarSlide);
    cv::Mat frame;
    for(;;) {

        if( g_run != 0){
            g_cap >> frame; if(frame.empty()) break;
            int current_pos = (int) g_cap.get(cv::CAP_PROP_POS_FRAMES);
            g_dontset = 1;

            cv::setTrackbarPos("Position", "Example2_4", current_pos);
            cv::imshow( "Example2_4", frame );

            g_run -= 1;
        }

        char c = (char) cv::waitKey(10);
        if( c== 's' ) // single step
        {
            g_run = 1;
            cout << "Single step, run = " << g_run <<endl;
            g_dontset = 0;
        }
        if( c == 'r' ) // run mode
        {
            g_run -= 1;
            cout << "Run mode, run = " << g_run << endl;
        }
        if( c == 27 ) // Esc
        {
            break;
        }
    }
    return 0;

}