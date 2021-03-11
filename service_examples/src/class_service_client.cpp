#include<ros/ros.h>
#include<service_examples/custom_srv.h>
#include<iostream>

using namespace std;

class ServClient 
{
    service_examples::custom_srv srv;
    ros::ServiceClient client;
    ros::NodeHandle n;
    public:
        ServClient();
        void Call();
};

ServClient::ServClient()
{
    client = n.serviceClient<service_examples::custom_srv>("speed_check");
};

void ServClient::Call()
{
    client.waitForExistence();
    if (client.call(srv)==true)
    {
        if (srv.response.srvC.data == true)
        {
           cout<<"move forward \n";
        }
    };
    srv.request.srvB.linear.x = rand()%111-100;

};


int main(int argv,char ** argc)
{
    ros::init(argv,argc,"class_service_client");
    ServClient serclient;
    ros::Rate rate(2);
    while (ros::ok())
    {
        serclient.Call();
        rate.sleep();
    }
    
    return 0;
}