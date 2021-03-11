#!/usr/bin/env python3

import rospy
from topic_examples.msg import custom_msg

class ExampleClass:
    def __init__(self):
        self.pub = rospy.Publisher('NumTopic',custom_msg,queue_size=10)
        self.msg = custom_msg()
        self.msg.msgA.data =0 
        self.rate = rospy.Rate(5)
    def publishing(self):
        if self.pub.get_num_connections>=1:
            pub = self.pub.publish(self.msg)
            self.msg.msgA.data += 1 
            rospy.loginfo("Sent message")

def main():
    pubClass = ExampleClass()
    while not rospy.is_shutdown():
        pubClass.publishing()
        pubClass.rate.sleep()   



if __name__ == "__main__":
     # Initialize a ROS Node
    rospy.init_node("class_publisher")
    try:
        main()
    except rospy.ROSException  as e:
        print(e)
