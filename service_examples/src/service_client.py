#!/usr/bin/env python

import rospy
from service_examples.srv import custom_srv,custom_srvRequest,custom_srvResponse
import random




def main():
    rospy.wait_for_service('speed_check')
    client = rospy.ServiceProxy('speed_check',custom_srv)
    Srv = custom_srvRequest()
    rate = rospy.Rate(10)

    while(not (rospy.is_shutdown())):
        Srv.srvB.linear.x = random.randint(-100,10)
        try: 
            result = client.call(Srv)
            if result.srvC.data:
                print('move forward')
        except rospy.ServiceException as e:
            print(e)
        rate.sleep()


if __name__ == "__main__":
    rospy.init_node('service_clinet')
    try :
        main()
    except rospy.ROSException as e:
        print(e)
