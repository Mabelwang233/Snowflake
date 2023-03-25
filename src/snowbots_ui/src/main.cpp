/*
 * Created By: Adam Nguyen
 * Created On: August 21st, 2021
 * Snowbots UI
 */

#include "../include/mainwindow.h"
#include "ros/ros.h"
#include <QApplication>
#include <QtGui>

#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    ros::init(argc, argv, "snowbot_ui");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    MainWindow w;
    w.show();

    qDebug() << "main";
    
    // ros::NodeHandle n;
    // ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    // ros::spin();

    // ros::init(argc, argv, "talker");
    
    
    // int count = 0;
    // while (ros::ok())
    // {
    //     std_msgs::String msg;
    //     std::stringstream ss;
    //     ss << "hello world " << count;
    //     msg.data = ss.str();
    //     ROS_INFO("%s", msg.data.c_str());

    //     chatter_pub.publish(msg);
    //     ros::spinOnce();
    //     loop_rate.sleep();
    //     ++count;
    // }

    return a.exec();
}
