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