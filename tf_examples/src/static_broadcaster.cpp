#include<ros/ros.h>
#include<tf2_ros/static_transform_broadcaster.h>
#include<geometry_msgs/TransformStamped.h>



void callback(const geometry_msgs::TransformStamped &msg)
{
    static tf2_ros::StaticTransformBroadcaster static_broad;
    static_broad.sendTransform(msg);
    ROS_INFO("send tf for pose");
}

int main(int argc,char ** argv)
{
    ros::init(argc,argv,"static_broadcaster");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("pose",10,callback);
    ros::spin();

    return 0;
}