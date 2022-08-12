// 示例2-10：同一个对象可以读取视频文件，也可以连接摄像头

#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char** argv ){
    cv::namedWindow( "Example2_10", cv::WINDOW_AUTOSIZE );

    cv::VideoCapture cap;
    if (argc == 1){
        cap.open(0); // open the first camera.
    }
    else{
        cap.open( argv[1] );
    }
    if( !cap.isOpened() ){ // Check if we succeeded
        std::cerr << "Couldn't open capture." << std::endl;
        return -1;
    }
    cv::Mat frame;
    for(;;){
        cap >> frame;
        if(frame.empty()){
            break;
        }
        cv::imshow( "Example2_10", frame );
        char c = (char)cv::waitKey(10);
        if(c == 27){ // 按ESC退出。
            break;
        }
    }
    return 0;
}