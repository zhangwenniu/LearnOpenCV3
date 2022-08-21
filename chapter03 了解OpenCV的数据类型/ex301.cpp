// cv::DataType<> template. 

template<typename _Tp> class DataType
{
    typedef _Tp value_type;
    typedef value_type work_typee;
    typedef value_type channel_type;
    typedef value_type vec_type;

    enum{
        generic_type = 1,
        depth        = -1,
        channels     = 1,
        fmt          = 0,
        type         = CV_MAKETYPE(depth, channels)
    };
};


// from core.hpp, cv::DataType<>特例化的例子。
// 为float类型定义的cv::DataType。
template<> class DataType<float>
{
public:
    typedef float       value_type;
    typedef value_type  work_type;
    typedef value_type  channel_type;
    typedef value_type  vec_type;

    enum{
        generic_type    = 0;
        depth           = DataDepth<channel_type>::value,
        channels        = 1,
        fmt             = DataDepth<channel_type>::fmt,
        type            = CV_MAKETYPE(depth, channels)
    };
};


// cv::Rect<>中的cv::DataType<>实例的例子
template<typename _Tp> class DataType<Rect_<_Tp> >
{
public:
    typedef Rect_<_Tp>                      value_type;
    typedef Rect_<typename DataType<_Tp>::work_type>    work_type;
    typedef _Tp                                         channel_type;
    typedef Vec<channel_type, channels>                 vec_type;

    enum {
        generic_type    = 0,
        depth           = DataDepth<channel_type>::value,
        channels        = 4,
        fmt             = ((channels-1)<<8) + DataDepth<channel_type>::fmt,
        type            = CV_MAKETYPE(depth, channels)
    };
};