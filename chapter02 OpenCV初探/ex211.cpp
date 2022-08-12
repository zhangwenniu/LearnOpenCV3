// 示例2-11：一个完整的读取彩色视频并转换为对数极坐标视频的程序

#include <opencv2/opencv.hpp>
#include <iostream>

int main( int argc, char** argv ){
    cv::namedWindow( "Example2_11", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Log_Polar", cv::WINDOW_AUTOSIZE );

    // ( Note: could capture from a camera by giving a camera id as an int. )
    //
    cv::VideoCapture capture;
    if(argc > 2){
        capture.open( argv[1] );
    }
    else{
        capture.open( 0 );
    }

    double fps = capture.get( cv::CAP_PROP_FPS );
    if(fps == 0){ // 摄像头的话，获取到的帧率为零。为了能够输出视频，需要自己设置帧率。
        fps = 24; // 设置帧率。fps: frames per second.
    }
    cv::Size size(
        (int)capture.get( cv::CAP_PROP_FRAME_WIDTH ),
        (int)capture.get( cv::CAP_PROP_FRAME_HEIGHT )
    );

    cv::VideoWriter writer;
    if(argc == 1){
        std::cout << "argc = "<< argc << " , fps = " << fps << " , size = (" << size.height << ", " << size.width << ")." << std::endl;
        writer.open( "output-log-polar.mp4", CV_FOURCC('M', 'J', 'P', 'G'), fps, size );
    }
    else{
        std::cout << argv[argc-1] << std::endl;
        writer.open( argv[argc-1], CV_FOURCC('M', 'J', 'P', 'G'), fps, size );
    }

    cv::Mat logpolar_frame, bgr_frame;
    for(;;){
        capture >> bgr_frame;
        if( bgr_frame.empty() ) break; // end if done

        cv::imshow( "Example2_11", bgr_frame );

        cv::logPolar(
            bgr_frame,              // Input color frame
            logpolar_frame,         // Output log-polar frame
            cv::Point2f(            // Centerpoint for log-polar transformation
                bgr_frame.cols / 2, // x
                bgr_frame.rows / 2  // y
            ),
            40,                     // Magnitude (scale parameter)
            cv::WARP_FILL_OUTLIERS  // Fill outliers with 'zero'
        );

        cv::imshow( "Log_Polar", logpolar_frame );
        writer << logpolar_frame;
        char c = cv::waitKey(10);
        if(c == 27) break;  // allow the user to break out when type Esc
    }
    capture.release();
    return 0;
}