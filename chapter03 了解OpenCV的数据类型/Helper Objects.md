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

===23.3.2 : From page 56 to 60

## The cv::DataType<>template

`cv::DataType<>` itself is a template. 

```c
template<typename _Tp> class DataType
{
    typedef _Tp 	value_type;
    typedef value_type work_type;
    typedef value_type channel_type;
    typedef value_type vec_type;
    
    enum{
        generic_type = 1,
        depth 		 = -1,
        channels     = 1,
        fmt 		 = 0,
        type 		 = CV_MAKETYPE(depth, channels)
    };
};
```

```c
template<> class DataType<float>
{
public:
    typedef float 		value_type;
    typedef value_type work_type;
    typedef value_type channel_type;
    typedef value_type vec_type;
    
    enum {
        generic_type = 0,
        depth        = DataDepth<channel_type>::value,
        channels     = 1,
        fmt        	 = DataDepth<channel_type>::fmt,
        type         = CV_MAKETYPE(depth, channels)
    };
};
```

```c
template<typename _Tp> class DataType<Rect_<_Tp> >
{
public:
    typedef Rect_<_Tp> value_type;
    typedef Rect_<typename DataType<_Tp>::worrk_type> work_type;
    typedef _Tp channel_type;
    typedef Vec<channel_type, channels> vect_type;
    
    enum {
        generic_type = 0,
        depth = DataDepth<channel_type>::value,
        channels = 4,
        fmt = ((channels - 1) << 8) + DataDepth<channel_type>::fmt,
        type = CV_MAKETYPE(depth, channels)
    };
};
```

由于本科没好好学C++的Template，这段完全看不懂在讲什么。

## The cv::InputArray and cv::OutputArray classes

`cv::Scalar, cv::Vec, cv::Matx`, `std::vector<>`

`cv::InputArray` is assumed to be const (i.e., read only).