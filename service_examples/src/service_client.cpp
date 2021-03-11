#include<ros/ros.h>
#include<stdlib.h>
#include<service_examples/custom_srv.h>
#include<iostream>

using namespace std;

int main(int argc,char **argv)
{
    ros::init(argc,argv,"service_client");
    ros::NodeHandle n;
    ros::Rate rate(10);
    ros::ServiceClient client = n.serviceClient<service_examples::custom_srv>("speed_check");
    service_examples::custom_srv ji;
    ji.request.srvB.linear.x = 5;
    client.waitForExistence();
    while (ros::ok())
    {
        if (client.call(ji) == true)
        {
            if (ji.response.srvC.data == true)
            {
            cout<<"move forward \n";
            }
        }

        
        ji.request.srvB.linear.x = rand()%111-100;
        rate.sleep();

    }


    return 0 ;
}