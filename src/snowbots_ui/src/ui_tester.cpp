/*
 * Created By: Adam Nguyen
 * Created On: August 21st, 2021
 * Snowbots UI Tester. This publishes random twist messages to the "/cmd_vel"
 * topic in place of the procontroller package
 */

#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include "std_msgs/String.h"
#include <stdlib.h>
#include <sstream>

int main(int argc, char** argv) {
    ros::init(argc, argv, "ui_tester");

    ros::NodeHandle n;

    ros::Publisher pub = n.advertise<std_msgs::Float32>("/cmd_vel", 1000);

    ros::Rate rate(10);

    srand(time(0));

    while (ros::ok()) {
        // Declares the message to be sent
        std_msgs::Float32 msg;

        // Random z value between -3 and 3
        msg = 6 * double(rand()) / double(RAND_MAX) - 3;

        // Publish the message
        pub.publish(msg);

        // Delays until it is time to send another message
        rate.sleep();
    }

    return 0;
}
