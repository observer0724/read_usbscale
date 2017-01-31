# read_usbscale

Publishing data from a usb scale to ROS nodes.

Modified from https://github.com/erjiang/usbscale

The program externs the code in usbscale.c to read data from the usbscale in scale_publisher.cpp to publish it. 

To publish, use 
  $rosrun scaler scale_publisher 

The fastest speed of reading is about 1 result per second.

File '70-persistent-usb.rules' have to be put in etc/udev/rules.d/ or the program does not have the permission to access the usbscale
