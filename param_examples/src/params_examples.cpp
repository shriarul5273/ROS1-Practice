#include<ros/ros.h>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"params_examples");
    ros::NodeHandle n;
    ros::param::set("time",5);
    ros::Duration(5).sleep();
    int hu;
    ros::param::get("time",hu);
    ROS_INFO("%d",  hu);
    return 0;
}