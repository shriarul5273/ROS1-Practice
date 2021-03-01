# topics_examples 

## This package contains:
- a custom meaasge of type:</br>
```
std_msgs/Float64  msgA
geometry_msgs/Twist  msgB
```
in the [msg/custom_msg.msg](https://github.com/shriarul5273/ROS1-Practice/blob/main/topic_examples/msg/custom_msg.msg) file.

- Nodes in [src/](https://github.com/shriarul5273/ROS1-Practice/tree/main/topic_examples/src) publishing and subscribing to the **NumTopic** topic:
    - 4 Python Node 
        * 2 Python Subscriber 
            + Class Subscriber **rosrun topic_examples class_subscriber_py.py**
            + Simple Subscriber **rosrun topic_examples subscriber_py.py**
        * 2 Python Publisher 
            + Class Publisher **rosrun topic_examples class_publisher_py.py**
            + Simple Publisher **rosrun topic_examples publisher_py.py**  
    - 4 C++ Node 
        * 2 C++ Subscriber
            + Class Subscriber **rosrun topic_examples class_subscriber_cpp**
            + Simple Subscriber **rosrun topic_examples subscriber_cpp**
        * 2 C++ Publisher
            + Class Publisher **rosrun topic_examples class_publisher_cpp**
            + Simple Publisher **rosrun topic_examples publisher_cpp**

- a launch file to launch a publisher and a subscriber in [launch/](https://github.com/shriarul5273/ROS1-Practice/tree/main/topic_examples/launch)
    - launch file **roslaunch topic_examples topic_subscriber_publisher.launch** it launchs the class_publisher_cpp node and class_subscriber_py node 

## rqt-graph for visualizing -> **rosrun rqt_graph rqt_graph**
example :
![alt text](https://github.com/shriarul5273/ROS1-Practice/tree/main/topic_examples/rqt.png)