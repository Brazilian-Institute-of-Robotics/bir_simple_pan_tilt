#include "../include/pan_tilt_pkg/ImageConverter.hpp"
#include "../include/pan_tilt_pkg/PanTilt.hpp"
//
int main(int argc, char** argv){
    ros::init(argc, argv, "pan_tilt_node");
    ImageConverter cam;
    PanTilt controller;
//
    controller.goToZero();
    double pan = 3.14;
    double tilt = -1.57;
    for(int n_photos=1; n_photos<5; n_photos++){
        controller.setPanTilt(pan, tilt);
        while(controller.moving){ros::spinOnce();}
        //sleepcp(500);
        cam.takeAPicture(n_photos);
        pan-=1.56;
        tilt-=0.0; //1.05
    } ros::shutdown();
    return 0;
}