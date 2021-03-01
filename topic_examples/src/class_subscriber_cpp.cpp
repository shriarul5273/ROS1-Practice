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

class class_subscribe
{

public:
    class_subscribe();
    ~class_subscribe();

    void callback(const topic_examples::custom_msg& msg);
};

class_subscribe::class_subscribe()
{
}

class_subscribe::~class_subscribe()
{
}

void class_subscribe::callback(const topic_examples::custom_msg& msg)
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
    ros::init(argc,argv,"class_subscriber_cpp");
    ros::NodeHandle n;
    class_subscribe subscribing;
    ros::Subscriber sub = n.subscribe("NumTopic",10,&class_subscribe::callback,&subscribing);
    ros::spin() ;

    return 0;
}