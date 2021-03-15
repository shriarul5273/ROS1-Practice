#!/usr/bin/env python
import rospy
from topic_examples.msg import custom_msg


class exampleClass:
    def __init__(self):
        self.sub = rospy.Subscriber('NumTopic',custom_msg,callback=self.CallBack)
    def CallBack(self,msg):
        if (msg.msgA.data)%5 == 0:
            rospy.logerr('Recived:{}'.format(msg.msgA.data))
        else:
            rospy.loginfo('Recived:{}'.format(msg.msgA.data))

def main():
    Subscribing = exampleClass()
    rospy.spin()


if __name__ == '__main__':
    # Initialize a ROS Node
    rospy.init_node('class_subscriber_py')
    try:
        main()
    except rospy.ROSException as e:
        print(e)
