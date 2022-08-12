// 示例2-5：加载图像并且在显示之前平滑处理图像

#include <opencv2/opencv.hpp>

void example2_5( const cv::Mat & image ){
    // Create some windows to show the input
    // and output images in.
    cv::namedWindow( "Example2_5-in", cv::WINDOW_AUTOSIZE );
    cv::namedWindow( "Example2_5-out", cv::WINDOW_AUTOSIZE );

    // Create a window to show our input image
    // 
    cv::imshow( "Example2_5-in", image );

    // Create an image to hold the smoothed output
    //
    cv::Mat out;

    // Do the smoothing
    // (Note: Could use GaussianBlue(), blur(), medianBlur() or bilateralFilter(). )
    //
    cv::GaussianBlur( image, out, cv::Size(5, 5), 3, 3 );
    cv::GaussianBlur( out, out, cv::Size(5, 5), 3, 3 );

    // Show the smoothed image in the output window
    //
    cv::imshow( "Example2_5-out", out );

    // Wait for the user to hit a key, windows will self destruct
    //
    cv::waitKey( 0 );
}


int main(int argc, char** argv){
    cv::Mat img = cv::imread(argv[1], -1);
    if(img.empty()) return -1;
    example2_5(img);
    // cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE); 
    // cv::imshow("Example1", img);
    // cv::waitKey(0);
    // cv::destroyWindow("Example1");
    return 0;
}