// 示例2-6，使用cv::pyrDown来创建一个新的图像，其宽高均为原始图像的一半。
#include <opencv2/opencv.hpp>

int main( int argc, char** argv ){
    cv::Mat img1, img2;
    
    cv::namedWindow( "Example1", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Example2", cv::WINDOW_AUTOSIZE );

    img1 = cv::imread( argv[1] );
    cv::imshow( "Example1", img1 );

    cv::pyrDown( img1, img2 );
    cv::imshow( "Example2", img2 );

    cv::waitKey(0);
    return 0;
}