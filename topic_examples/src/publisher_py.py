#!/usr/bin/env python
import rospy
from topic_examples.msg import custom_msg

def main():
    pub = rospy.Publisher('NumTopic',custom_msg,queue_size=100)
    rate = rospy.Rate(5)
    msg = custom_msg()
    msg.msgA.data = 0 
    while (not (rospy.is_shutdown())):
        pub.publish(msg)
        msg.msgA.data+=1
        rate.sleep()
        rospy.loginfo("Sent message")


if __name__ =='__main__':
    # Initialize a ROS Node
    rospy.init_node('publisher_py')
    try :
        main()
    except rospy.ROSException as e:
        print(e)