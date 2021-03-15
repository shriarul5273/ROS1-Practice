#!/usr/bin/env python

import rospy
from service_examples.srv import custom_srv,custom_srvRequest,custom_srvResponse

def callBack(srv=custom_srvRequest()):
    result = custom_srvResponse()
    if srv.srvB.linear.x >0:
        rospy.loginfo('ok')
        result.srvC.data = True
    else :
         result.srvC.data = False

    return result


def main():
    server = rospy.Service('speed_check',custom_srv,callBack)
    rospy.spin()




if __name__ == '__main__':
    rospy.init_node('service_server')
    try :
        main()
    except rospy.ROSException() as e:
        print(e)
