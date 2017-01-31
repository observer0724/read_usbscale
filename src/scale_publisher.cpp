#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <libusb-1.0/libusb.h>

extern "C" {
  double read_scale(void);
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "scale_publisher"); // name of this node will be "scale_publisher"
    ros::NodeHandle n; 
  
    ros::Publisher scale_publisher_object = n.advertise<std_msgs::Float64>("scale", 1);

    double weight;
    std_msgs::Float64 weight_msg;

    while (ros::ok())
    {

        weight = read_scale(); //get data from the scale
      
        weight_msg.data = weight; // make the data publishable in ROs

        scale_publisher_object.publish(weight_msg); 
      
        ros::Duration(1).sleep();
    }
}
