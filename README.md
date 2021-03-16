# ROS1-Practice

## Introduction
This repository contains several ROS Melodic implementation that I have written to Practice (ROS) Robot Opearting system. It contains the package with different parts of ros in each folders.If you want to try them go ahead and try them.

## Folders
- [topic_examples](https://github.com/shriarul5273/ROS1-Practice/tree/main/topic_examples): Contains ros message nodes (both subscriber and publisher) with custom message type.
- [service_examples](https://github.com/shriarul5273/ROS1-Practice/tree/main/service_examples) : Contains ros Services nodes (both Service Client and Server) with custom service type.
- [param_examples](https://github.com/shriarul5273/ROS1-Practice/tree/main/param_examples): Contains C++ and python examples with  a parameter server,(Parameter it is  a shared, multi-variate dictionary that is accessible via network).


## Best Practices :
 - Use git from command line.(Because uploading manually makes python scripts to loose executable permissions.).
 - Use Python3 for ROS Scripts.
 - Add add_dependencies(name packagename_generate_messages_cpp) to CMakeLists.txt for all C++ programs with custom msg/srv/action.(this may not be needed but I had some issues when running on other computers).

 ## Install :
 This repository is compatible with  both ROS Melodic and ROS Noetic.
 ```
 #ros melodic clone : 
 git clone -b melodic-devel https://github.com/shriarul5273/ROS1-Practice.git
 #ros noetic clone :
 git clone -b noetic-devel https://github.com/shriarul5273/ROS1-Practice.git
 ```
 if you find any error,mistake please open a issue.

## License and Warranty
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">
  <img alt="Creative Commons Licence" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" />
</a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
Please check the file LICENSE.md for the details.
