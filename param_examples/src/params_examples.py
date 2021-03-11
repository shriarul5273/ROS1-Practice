#!/usr/bin/env python3
import rospy 
import datetime


def main():
    rospy.set_param('Time_now',datetime.datetime.now())
    rospy.sleep(10)
    sec = rospy.get_param('Time_now')
    rospy.loginfo(sec)
    param_names = rospy.get_param_names()
    rospy.loginfo(param_names)
    # rospy.spin()


if __name__ == "__main__":
    rospy.init_node('params_examples')
    try:
        main()
    except rospy.ROSException as e:
        print(e)
