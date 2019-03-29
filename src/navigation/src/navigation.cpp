#define _USE_MATH_DEFINES

#include <navigation/navigation_interface.hpp>
#include <math.h>

void Navigation::state_callback(const dynamixel_msgs::JointState& joint_state){
    Navigation::_joint_state = joint_state.current_pos;

}

Navigation::Navigation(std::string name) :
                           _home(0.0), 
                           _topic_name("/" + name + "_controller"),
                           _nh("navigation"),
                           _pub_cmd(_nh.advertise<std_msgs::Float64>(_topic_name + "/command", 100)),
                           _sub_state(_nh.subscribe(_topic_name + "/state", 100, &Navigation::state_callback, this)) 
                           {
}

Navigation::~Navigation(){

}

void Navigation::pub_msg(float angle){
    std_msgs::Float64 nav_msg;
    nav_msg.data = angle;
    _pub_cmd.publish(nav_msg);
}

void Navigation::home_pose(){
    Navigation::pub_msg(_home);
}

void Navigation::rotate(){
    Navigation::pub_msg(Navigation::_joint_state + M_PI/4);
    ros::Duration(2.0).sleep();
}