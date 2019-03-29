#include <ros/ros.h>
#include <navigation/navigation_interface.hpp>

int main (int argc, char** argv){
    Navigation nav_pan("pan");
    nav_pan.home_pose();

    Navigation nav_tilt("tilt");
    nav_tilt.home_pose();

    ros::Duration(2.0).sleep();

    nav_tilt.rotate();
    nav_pan.rotate();


}