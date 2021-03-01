/*                              ROS-Melodic-Pratice
 *
 * Copyright (C) 2021  Shriarulmozivarman 
 *                                         
 *
 * Objective:
 *      Implementation of Subscriber on a C++ Class with custom message. 
 *
 * Development:
 *      The code is developed and implemented on the C++ with Visual Studio Code.
 */

#include<ros/ros.h>
#include<topic_examples/custom_msg.h>

class class_publisher
{
    ros::NodeHandle n;
    ros::Publisher pub;
    topic_examples::custom_msg i;
    ros::Rate *rate;
public:
    class_publisher();
    void looping();
};

class_publisher::class_publisher()
{

    pub = n.advertise<topic_examples::custom_msg>("NumTopic",10);
    rate = new ros::Rate(10);
    i.msgA.data = 0;
}

void class_publisher::looping()
{
    while (ros::ok())
    {
        pub.publish(this->i);
        i.msgA.data++;
        rate->sleep();
        ROS_INFO("Sent message");
    }

}
int main(int argc,char ** argv)
{
    // Initialize a ROS Node
    ros::init(argc,argv,"class_publisher_cpp");
    class_publisher publishing;
    publishing.looping();
    return 0;
}