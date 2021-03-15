#!/usr/bin/env python

import rospy
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped


def callback(msg):
    br = TransformBroadcaster()
    br.sendTransform(msg)


def main():
    _ = rospy.Subscriber('pose',TransformStamped,callback)
    rospy.spin()

if __name__ == '__main__':
    rospy.init_node('broadcaster')
    try :
        main()
    except rospy.ROSException as e:
        print(e)