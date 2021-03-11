# service_examples 

## This package contains:
- a custom service of type:</br>
```
std_msgs/Int32 srvA
geometry_msgs/Twist srvB
---
std_msgs/Bool srvC
```
in the [srv/custom_srv.srv](https://github.com/shriarul5273/ROS1-Practice/blob/main/service_examples/srv/custom_srv.srv) file.

- Nodes in [src/](https://github.com/shriarul5273/ROS1-Practice/tree/main/service_examples/src) with Service Server and client to the **speed_check** Service Request and Responce, the Service returns true when the srvB with geometry_msgs.linear.x is greater than 0:
    - 4 Python Node 
        * 2 Python Service Client 
            + Class Service Client  **rosrun service_examples class_service_client.py**
            + Simple Service Client **rosrun service_examples class_service_server.py**
        * 2 Python Sertvice Server 
            + Class Sertvice Server **rosrun service_examples service_client.py**
            + Simple Service Server **rosrun service_examples service_server.py**  
    - 4 C++ Node 
        * 2 C++ Service Client
            + Class Service Client  **rosrun service_examples class_service_client**
            + Simple Service Client **rosrun service_examples service_client**
        * 2 C++ Sertvice Server
            + Class Sertvice Server  **rosrun service_examples class_service_server**
            + Simple Sertvice Server **rosrun service_examples service_server**

- a launch file to launch a client and a server in [launch/](https://github.com/shriarul5273/ROS1-Practice/tree/main/service_examples/launch)
    - launch file **roslaunch service_examples service_client_server.launch** it launchs the class_publisher_cpp node and class_subscriber_py node 


