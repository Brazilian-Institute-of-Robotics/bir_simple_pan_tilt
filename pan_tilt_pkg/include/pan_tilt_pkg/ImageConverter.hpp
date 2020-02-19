#include <ros/ros.h>
#include <sensor_msgs/Image.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
//
class ImageConverter{
    public:
        ImageConverter();
        std::string frame_path;
        std::string save_path;
        void takeAPicture(int n_photos);
    private:
        void imageCallback(const sensor_msgs::Image::ConstPtr &img);
        cv::Mat frame;
        ros::NodeHandle nh;
        image_transport::ImageTransport it;
        image_transport::Subscriber img_sub;
        cv_bridge::CvImagePtr cv_prt;
};