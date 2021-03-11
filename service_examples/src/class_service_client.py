#!/usr/bin/env python3


import rospy
from service_examples.srv import custom_srv,custom_srvRequest,custom_srvResponse
import random


class SerClient:
    def __init__(self):
        self.client = rospy.ServiceProxy('speed_check',custom_srv)
    def SerCall(self):
        srv = custom_srvRequest()
        srv.srvB.linear.x = random.randint(-100,10)
        try:
            hu = self.client.call(srv)
            if hu.srvC.data:
                print('move forward')
        except rospy.ServiceException as e :
            print(e)


def main():
    ServiceCall = SerClient()
    rospy.wait_for_service('speed_check')
    rate = rospy.Rate(10)
    while not (rospy.is_shutdown()):
        ServiceCall.SerCall()
        rate.sleep()

if __name__ == '__main__':
    rospy.init_node('class_service_client')
    try :
        main()
    except rospy.ROSException as e:
        print(e)
