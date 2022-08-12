// 读取视频文件，并将其通过高斯模糊进行处理。
#include <opencv2/opencv.hpp>
#include <iostream>

int main( int argc, char** argv ){
    cv::Mat frame_bgr, frame_blur;
    cv::namedWindow( "Practice2_3", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Gauss_Blur", cv::WINDOW_AUTOSIZE );

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
        (int)capture.get( cv::CAP_PROP_FRAME_WIDTH ),
        (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT)
    );

    cv::VideoWriter writer;
    if( argc == 1 ){
        writer.open( "output_blur.mp4", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);
    }
    else{
        writer.open( argv[argc-1], CV_FOURCC('M', 'J', 'P', 'G'), fps, size );
    }

    for(;;){
        capture >> frame_bgr;
        if( frame_bgr.empty() ) break; // end if done
        cv::imshow( "Practice2_3", frame_bgr);
        cv::GaussianBlur( frame_bgr, frame_blur, cv::Size(5, 5), 3, 3 );
        cv::imshow( "Gauss_Blur", frame_blur );
        writer << frame_blur;
        char c = cv::waitKey(10);
        if( c == 27 ) break; // allow the user to break out when type Esc
    }
    capture.release();
    return 0;
    
}