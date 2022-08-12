#include <opencv2/opencv.hpp>
#include <iostream>

int main( int argc, char** argv ){
    cv::Mat frame_bgr, frame_pry;
    cv::namedWindow( "Practice2_3", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Pyramid_downsample", cv::WINDOW_AUTOSIZE );

    cv::VideoCapture capture;
    if( argc == 3 ){
        capture.open( argv[1] );
    }
    else{
        capture.open( 0 );
    }
    double fps = capture.get( cv::CAP_PROP_FPS );
    if( fps == 0 ){
        fps = 24;
    }
    cv::Size size(
        (int)capture.get( cv::CAP_PROP_FRAME_WIDTH ) / 2,
        (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT) / 2
    );

    cv::VideoWriter writer;
    if( argc == 1 ){
        writer.open( "output_downsample.mp4", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
    }
    else{
        writer.open( argv[argc-1], CV_FOURCC('M', 'J', 'P', 'G'), fps, size );
    }

    for(;;){
        capture >> frame_bgr;
        if( frame_bgr.empty() ) break; // end if done
        cv::imshow( "Practice2_3", frame_bgr);
        cv::pyrDown( frame_bgr, frame_pry );
        cv::imshow( "Pyramid_downsample", frame_pry );
        writer << frame_pry;
        char c = cv::waitKey(10);
        if( c == 27 ) break; // allow the user to break out when type Esc
    }
    capture.release();
    return 0;
    
}