/*                              ROS-Melodic-Pratice
 *
 * Copyright (C) 2021  Shriarulmozivarman 
 *                                         
 *
 * Objective:
 *      Implementation of Simple Subscriber with custom message. 
 *
 * Development:
 *      The code is developed and implemented on the C++ with Visual Studio Code.
 */

#include<ros/ros.h>
#include<topic_examples/custom_msg.h>

void callback(const topic_examples::custom_msg& msg)
{
    int i = msg.msgA.data;
    if (i%5 == 0)
    {
        ROS_ERROR("Recived:%f",msg.msgA.data);
    }
    else
    {
        ROS_INFO("Recived:%f",msg.msgA.data);  

    }

}


int main(int argc,char **argv)
{
    //Initialize a ROS Node
    ros::init(argc,argv,"subscriber_cpp");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("NumTopic",10,callback);
    ros::spin();
    return 0 ;
}