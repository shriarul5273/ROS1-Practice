#include<ros/ros.h>
#include<service_examples/custom_srv.h>
#include<iostream>


using namespace std;

bool callback(service_examples::custom_srvRequest &req,
              service_examples::custom_srvResponse &res)
{
    if (req.srvB.linear.x > 0)
    {
        res.srvC.data = true;
        cout<<"ok\n";
    }
    else 
    {
        res.srvC.data = false;
    }
    return true;
}


int main(int argc,char ** argv)
{
    ros::init(argc,argv,"service_server");
    ros::NodeHandle n;
    ros::ServiceServer server = n.advertiseService("speed_check",callback);
    ros::spin();

    return 0;
}