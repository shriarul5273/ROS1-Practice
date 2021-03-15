#!/usr/bin/env python

import rospy
from param_examples.cfg import dynamic_paramConfig
from dynamic_reconfigure.server import Server


def callback(config,level):
    rospy.loginfo("Get these parameters int_param:{int_param}, str_param:{str_param}, bool_param:{bool_param}".format(**config))
    return config
if __name__ == '__main__':
    rospy.init_node('dynamic_param_examples')
    try :
        Server = Server(dynamic_paramConfig,callback)
        rospy.spin()
    except rospy.ROSException as e :
        print(e)