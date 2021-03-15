#!/usr/bin/env python
import rospy
from topic_examples.msg import custom_msg


def CallBack(msg):
    if msg.msgA.data %5 == 0:
        rospy.logerr('Recived:{}'.format(msg.msgA.data))
    else:
        rospy.loginfo('Recived:{}'.format(msg.msgA.data))

def main():
    sub = rospy.Subscriber('NumTopic',custom_msg,callback=CallBack)
    rospy.spin()

if __name__ == '__main__':
    # Initialize a ROS Node
    rospy.init_node('subscriber_py')
    try:
        main()
    except rospy.ROSException() as e:
        print(e)
