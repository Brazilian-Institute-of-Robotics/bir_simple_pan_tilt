#include "../include/pan_tilt_pkg/PanTilt.hpp"
//
PanTilt::PanTilt(){
    ros::NodeHandle nh;
    pan_publisher = nh.advertise<std_msgs::Float64>("/pan_joint_controller/command", 1000);
    tilt_publisher = nh.advertise<std_msgs::Float64>("/tilt_joint_controller/command", 1000);
    pan_subscriber = nh.subscribe("/pan_joint_controller/state", 1000, &PanTilt::getPan, this);
    tilt_subscriber = nh.subscribe("/tilt_joint_controller/state", 1000, &PanTilt::getTilt, this);
    goal_pan.data = 0.0;
    goal_tilt.data = 0.0;
    pan_position = 1.0;
    tilt_position = 1.0;
    moving = true;
    ros::spinOnce();
}
void PanTilt::getPan(dynamixel_msgs::JointState pan_data){
    pan_position = pan_data.current_pos;
    moving = pan_data.is_moving;
}
void PanTilt::getTilt(dynamixel_msgs::JointState tilt_data){
    tilt_position = tilt_data.current_pos;
}
void PanTilt::goToZero(){
    setPanTilt(0,0);
}
void PanTilt::setPanTilt(double g_pan, double g_tilt){
    ros::Rate loop_rate(30);
    ros::spinOnce();
    goal_pan.data = g_pan;
    goal_tilt.data = g_tilt;
    ROS_INFO("POSITIONING...");
    while(pan_position<g_pan-0.03 || pan_position>g_pan+0.03 || 
          tilt_position<g_tilt-0.03 || tilt_position>g_tilt+0.03){
        ros::spinOnce();
        loop_rate.sleep();
        pan_publisher.publish(goal_pan);
        tilt_publisher.publish(goal_tilt);
    }
}
void PanTilt::setPanPosition(double goal){
    ros::Rate loop_rate(30);
    ros::spinOnce();
    goal_pan.data = goal;
    ROS_INFO("POSITIONING...");
    while(pan_position<goal-0.03 || pan_position>goal+0.03){
        loop_rate.sleep();
        ros::spinOnce();
        pan_publisher.publish(goal_pan);
    }
}
void PanTilt::setTiltPosition(double goal){
    ros::Rate loop_rate(30);
    ros::spinOnce();
    goal_tilt.data = goal;
    ROS_INFO("POSITIONING...");
    while(tilt_position<goal-0.03 || tilt_position>goal+0.03){
        loop_rate.sleep();
        ros::spinOnce();
        tilt_publisher.publish(goal_tilt);
    }
}