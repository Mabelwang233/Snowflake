/*
 * Created By: Adam Nguyen
 * Created On: August 21st, 2021
 * Snowbots UI
 */

#include "../include/RosIntegration.h"

RosIntegration::RosIntegration() {
    n = new ros::NodeHandle();
}
RosIntegration::~RosIntegration() {
    ros::Rate(10).sleep();//probably want to make this ros::Rate
    ros::spinOnce();
    delete n;
}
