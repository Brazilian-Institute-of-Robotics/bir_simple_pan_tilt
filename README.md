# PanTilt

## Requirements
This repository was created using:
 - ROS Version - **Kinetic**
 - OS - **Ubuntu 16.04**
 
 ## ROS Packages
It's necessary to have some packages installed:
```bash
sudo apt-get install ros-kinetic-dynamixel-controllers ros-kinetic-uvc-camera ros-kinetic-image-transport ros-kinetic-cv-bridge
```

## Photos Path
You'll need to change the frame_path and save_path variables from [ImageConverter.cpp](https://github.com/Brazilian-Institute-of-Robotics/bir_simple_pan_tilt/blob/develop/pan_tilt/pan_tilt_pkg/src/ImageConverter.cpp) file.

## Launch
To launch the pan&tilt, type in terminal:sss
```bash
roslaunch pan_tilt_pkg pan_tilt_camera.launch
```