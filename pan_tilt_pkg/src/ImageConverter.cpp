#include "../include/pan_tilt_pkg/ImageConverter.hpp"
//
ImageConverter::ImageConverter() : it(nh){
    img_sub = it.subscribe("/image_raw", 1, &ImageConverter::imageCallback, this);
    frame_path = "/home/felipe/bir_ws/src/pan_tilt_pkg/src/frame.jpg";
    save_path = "/home/felipe/bir_ws/src/pan_tilt_pkg/photos/";
}
void ImageConverter::imageCallback(const sensor_msgs::Image::ConstPtr &img){
    try{
        cv_prt = cv_bridge::toCvCopy(img, sensor_msgs::image_encodings::BGR8);
    } catch(const cv_bridge::Exception &e){
        ROS_ERROR("Error to convert!");
        return;
    }
    cv::imwrite(frame_path, cv_prt->image);
    frame = cv::imread(frame_path);
    cv::imshow("Webcam", frame);
    cv::waitKey(1);
}
void ImageConverter::takeAPicture(int n_photos){
    cv::Mat photo;
    std::string file_path;
    file_path = save_path + "photo_" + std::to_string(n_photos) + ".jpg";
    photo = cv::imread(frame_path);
    cv::imwrite(file_path, photo);
}
void sleepcp(int milliseconds){
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC/1000;
    while (clock() < time_end){}
}