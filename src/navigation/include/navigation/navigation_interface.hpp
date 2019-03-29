#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <dynamixel_msgs/JointState.h>

class Navigation{
    public:
    Navigation(std::string name);
    ~Navigation();
    void home_pose();
    void pub_msg();
    void pub_msg(float angle);
    void state_callback(const dynamixel_msgs::JointState& js);
    void rotate();
    std::string _topic_name;

    private:
    ros::Publisher _pub_cmd;
    ros::Subscriber _sub_state;
    ros::NodeHandle _nh;
    float _home;
    float _joint_state;



};