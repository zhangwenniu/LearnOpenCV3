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