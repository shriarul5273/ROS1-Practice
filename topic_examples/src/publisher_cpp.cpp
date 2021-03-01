/*                              ROS-Melodic-Pratice
 *
 * Copyright (C) 2021  Shriarulmozivarman 
 *                                         
 *
 * Objective:
 *      Implementation of Simple Publisher with custom message. 
 *
 * Development:
 *      The code is developed and implemented on the C++ with Visual Studio Code.
 */


#include<ros/ros.h>
#include<topic_examples/custom_msg.h>


int main(int argc,char **argv)
{
    //Initialize a ROS Node
    ros::init(argc,argv,"publisher_cpp");
    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<topic_examples::custom_msg>("NumTopic",10);
    ros::Rate rate(5);
    topic_examples::custom_msg msg;
    msg.msgA.data = 0;
    while (ros::ok())
    {
        pub.publish(msg);
        rate.sleep();
        ros::spinOnce();
        msg.msgA.data ++;
        ROS_INFO("Sent message");

    }
    

    return 0;
}