#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <libusb-1.0/libusb.h>

extern "C" {
  double read_scale(void);
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "minimal_publisher"); // name of this node will be "minimal_publisher"
    ros::NodeHandle n; // two lines to create a publisher object that can talk to ROS
    ros::Publisher my_publisher_object = n.advertise<std_msgs::Float64>("topic1", 1);

    double weight;
    std_msgs::Float64 weight_msg;
    // w.data = 0.0;

    // do work here in infinite loop (desired for this example), but terminate if detect ROS has faulted
    while (ros::ok())
    {
        // this loop has no sleep timer, and thus it will consume excessive CPU time
        // expect one core to be 100% dedicated (wastefully) to this small task
        // input_float.data = input_float.data + 0.001; //increment by 0.001 each iteration

        weight = read_scale();
        weight_msg.data = weight;

        my_publisher_object.publish(weight_msg); // publish the value--of type Float64--
        //to the topic "topic1"
        ros::Duration(1).sleep();
    }
}
