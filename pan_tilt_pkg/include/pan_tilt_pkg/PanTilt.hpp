#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "dynamixel_msgs/JointState.h"
#include <time.h>
//
void sleepcp(int milliseconds);
class PanTilt{
    public:
        PanTilt();
        void goToZero();
        void setPanTilt(double g_pan, double g_tilt);
        void setPanPosition(double goal);
        void setTiltPosition(double goal);
        double pan_position, tilt_position;
        bool moving;
    private:
        ros::NodeHandle nh;
        ros::Publisher tilt_publisher;
        ros::Publisher pan_publisher;
        ros::Subscriber pan_subscriber;
        ros::Subscriber tilt_subscriber;
        std_msgs::Float64 goal_pan;
        std_msgs::Float64 goal_tilt;
        void getPan(dynamixel_msgs::JointState pan_data);
        void getTilt(dynamixel_msgs::JointState tilt_data);
};