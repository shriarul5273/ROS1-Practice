#include<ros/ros.h>
#include<param_examples/dynamic_paramConfig.h>
#include<dynamic_reconfigure/server.h>


void callback(param_examples::dynamic_paramConfig &config,uint32_t level)
{
    ROS_INFO("got these params: %d %s %s",config.int_param,config.str_param.c_str(),config.bool_param?"True":"False");
}


int main(int argc,char ** argv)
{
    ros::init(argc,argv,"dynamic_param_examples");

    dynamic_reconfigure::Server<param_examples::dynamic_paramConfig> server;
    dynamic_reconfigure::Server<param_examples::dynamic_paramConfig>::CallbackType f;
    f = boost::bind(&callback,_1,_2);
    server.setCallback(f);
    ros::spin();

    return 0;
}