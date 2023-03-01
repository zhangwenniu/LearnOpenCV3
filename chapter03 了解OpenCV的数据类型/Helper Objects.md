===23.3.1 : From page 52 to 56

# Helper Objects

## The cv::TermCriteria class

`TermCriteria( int type, int maxCount, double epsilong )`

`cv::TermCriteria::COUNT` or `TermCriteria::EPS`

`cv::TermCriteria::COUNT`=`cv::TermCriteria::MAX_ITER`

## The cv::Range class

`cv::Range( int start, int end )`

`cv::Range rng( 0, 4 )` includes the values 0, 1, 2 and 3, but not 4. 

## The cv::Ptr template and Garbage Colection 101

```c
cv::Ptr<Matx33f> p( new cv::Matx33f );
// or 
cv::Ptr<Matx33f> p = makePtr(cv::Matx33f)();
```

It support operators such as `operator*()` and `operator->()`.

The functions `addref()` and `release()` increment and decrement the internal reference counter of the pointer. 

```c
IplImage* img_p = cvLoadImage( ... );
cv::Ptr<IplImage> img_p = cvLoadImage( "an_imgage" );
cv::Ptr<IplImage> img_p( cvLoadImage("an_image") );
```

```c
template<> inline void cv::Ptr<IplImage>::delete_obj() {
    cvReleaseImage(&obj);
}
```

```c
template<> inline void cv::Ptr<FILE>::delete_obj() {
    fclose(obj);
}
```

```c
{
    cv::Ptr<FILE> f(fopen("myfile.txt", "r"));
    if(f.empty())
        throw ...; // Throw an exception, we will get to this later on ...
    fprintf(f, ...);
    ...
}
```

## The cv::Exception class and exception handling

`cv::Exception`, from STL `std::exception`

`CV_Error( errorcode, description )`

`CV_ERROR_( errorcode, printf_fmt_str, [printf-args] )`

`CV_Assert( condition )`

`CV_DbgAssert( condition )`