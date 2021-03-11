#include<ros/ros.h>
#include<service_examples/custom_srv.h>
#include<iostream>

using namespace std;


class SerServer
{
    ros::NodeHandle n;
    ros::ServiceServer server;
    service_examples::custom_srv ji;
    public:
        SerServer();    
        bool Callback(service_examples::custom_srvRequest &req ,
                         service_examples::custom_srvResponse &res);
};

SerServer::SerServer()
{
    server = n.advertiseService("speed_check",&SerServer::Callback,this);

}

bool SerServer::Callback(service_examples::custom_srvRequest &req ,
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
    ros::init(argc,argv,"class_service_server");
    SerServer serve;
    ros::spin();
    return 0;   

}