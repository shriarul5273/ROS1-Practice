#!/usr/bin/env python3

import rospy
from service_examples.srv import custom_srv,custom_srvRequest,custom_srvResponse


class Server:
    def __init__(self):
        self.server = rospy.Service('speed_check',custom_srv,self.cli)
    def cli(self,msg=custom_srvRequest()):
        result = custom_srvResponse()
        if msg.srvB.linear.x >0:
            rospy.loginfo('ok')
            result.srvC.data = True
        else :
            result.srvC.data = False

        return result


def main():
    S = Server()
    rospy.spin()

    


if __name__ == '__main__':
    rospy.init_node('class_service_server')
    try :
        main()
    except rospy.ROSException as e:
        print(e)
