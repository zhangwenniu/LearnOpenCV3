// 示例2-8：在一个简单图像处理流程中结合图像金字塔操作（两次）和Canny边缘检测器

#include <opencv2/opencv.hpp>

int main(int argc, char** argv ){
    cv::Mat img_rgb, img_gry, img_cny, img_pyr, img_pyr2;

    cv::namedWindow( "Example Gray", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Example Canny", cv::WINDOW_AUTOSIZE );

    img_rgb = cv::imread( argv[1] );
    
    cv::imread( argv[1] );

    cv::cvtColor( img_rgb, img_gry, cv::COLOR_BGR2GRAY );
    cv::pyrDown( img_gry, img_pyr );
    cv::pyrDown( img_pyr, img_pyr2 );
    cv::Canny( img_pyr2, img_cny, 10, 100, 3, true );
    
    cv::imshow( "Example Gray", img_pyr2 );
    cv::imshow( "Example Canny", img_cny );

    cv::waitKey( 0 );
    return 0;
}