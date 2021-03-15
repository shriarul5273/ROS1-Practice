#!/usr/bin/env python
import rospy
import tf
from geometry_msgs.msg import TransformStamped
from tf2_ros import StaticTransformBroadcaster
import argparse


ap = argparse.ArgumentParser()
ap.add_argument('-x','--x',default=0.1,help="pose in x")
ap.add_argument('-y','--y',default=0.5,help="pose in y")
ap.add_argument('-z','--z',default=1.0,help="pose in z")
ap.add_argument('-r','--roll',default=2.0,help="roll")
ap.add_argument('-p','--pitch',default=0.5,help="pitch")
ap.add_argument('-ya','--yaw',default=0.6,help="yaw")
args = vars(ap.parse_args())

def main():
    pose = TransformStamped()
    static_br = StaticTransformBroadcaster()
    pose.header.stamp = rospy.Time.now()
    pose.header.frame_id = "world"
    pose.child_frame_id = "robot"
    pose.transform.translation.x = args['x']
    pose.transform.translation.y = args['y']
    pose.transform.translation.z = args['z']

    quat = tf.transformations.quaternion_from_euler(
            args['roll'],args['pitch'],args['yaw'])
    pose.transform.rotation.x = quat[0]
    pose.transform.rotation.y = quat[1]
    pose.transform.rotation.z = quat[2]
    pose.transform.rotation.w = quat[3]



    static_br.sendTransform(pose)
    rospy.spin()

if __name__ == '__main__':
    rospy.init_node('static_broadcaster')
    try:
        main()
    except rospy.ROSException as e:
        print(e)