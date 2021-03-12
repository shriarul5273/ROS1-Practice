#include<ros/ros.h>
#include<tf2_ros/transform_broadcaster.h>
#include<geometry_msgs/TransformStamped.h>

void callback(const geometry_msgs::TransformStamped &msg)
{
    static tf2_ros::TransformBroadcaster br;
    br.sendTransform(msg);
    ROS_INFO("updated tf");

}


int main(int argc,char ** argv)
{
    ros::init(argc,argv,"broadcaster");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("pose",10,callback);
    ros::spin();
    return 0;
}