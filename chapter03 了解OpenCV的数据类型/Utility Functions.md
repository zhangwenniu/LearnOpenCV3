# Utility Functions

| Fucnction                 | Description                                                  |
| ------------------------- | ------------------------------------------------------------ |
| `cv::alignPtr()`          | Align pointer to given number of bytes                       |
| `cv::alignSize`           | Align buffer size to given number of bytes                   |
| `cv::allocate()`          | Allocate a C-style array of objects                          |
| `cvCeil()`                | Round float number x to nearest integer not smaller than x   |
| `cv::cubeRoot`            | Compute the cube root of a number                            |
| `cv::CV_Assert()`         | Throw an exception if a given condition is not true          |
| `CV_Error()`              | Macro to build a `cv::Exception` (from a fixed string) and throw it |
| `CV_Error_()`             | Macro to build a `cv::Exception` (from a formatted string) and throw it |
| `cv::deallocate()`        | Deallocate a C-style array of objects                        |
| `cv::error()`             | Indicate an error and throw an exception                     |
| `cv::fastAtan2()`         | Calculate two-dimensional angle of a vector in degrees.      |
| `cv::fastFree()`          | Deallocate a memory buffer                                   |
| `cv::fastMalloc()`        | Allocate an aligned memory buffer                            |
| `cvFloor()`               | Round float number x to nearest integer not larger than x    |
| `cv::format()`            | Create an STL string using `sprintf-like` formatting         |
| `cv::getCPUTickCount()`   | Get tick count from internal CPU timer                       |
| `cv::getNumThreads()`     | Count number of threads currently used by OpenCV             |
| `cv::getOptimalDFTSize()` | Compute the best size for an array that you plan to pass to cv::DFT() |
| `cv::getThreadNum()`      | Get index of the current thread                              |
| `cv::getTickCount()`      | Get tick count from system                                   |
| `cv::getTickFrequency()`  | Get number or ticks per second (see `cv::getTickCount()`)    |
| `cvIsInf()`               | Check if a floating-point number x is infinity               |
| `cvIsNan()`               | Check if a floating-point number x is "Not a Number"         |
| `cvRound()`               | Round float number x to the nearest integer                  |
| `cv::setNumThreads()`     | Set number of threads used by OpenCV                         |
| `cv::setUseOptimized()`   | Enables or disables the use of optimized code (SSE2, etc.)   |
| `cv::useOptimized()`      | Indicates status of optimized code enabling (see `cv::setUseOptimized()`) |