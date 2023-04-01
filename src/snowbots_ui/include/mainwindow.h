/*
 * Created By: Adam Nguyen
 * Created On: August 21st, 2021
 * Snowbots UI
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

// ros
//#include "RosIntegration.h"
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <string>
#include "std_msgs/String.h"
#include <sstream>

static std_msgs::Float32 nuc_temp;
// static std_msgs::Float32 rover_temp;
// static std_msgs::Float32 elec_box_temp;
// static std_msgs::Float32 end_effector_force;
// static std_msgs::Float32 end_effector_pos;

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow {
    Q_OBJECT
  public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

    //arm_pos button handlers
    void handleButton1(){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "pos 1 clicked!";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        arm_pos.publish(msg);
        ros::spinOnce();
    } 
     void handleButton2(){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "pos 2 clicked!";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        arm_pos.publish(msg);
        ros::spinOnce();
    } 
     void handleButton3(){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "pos 3 clicked!";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        arm_pos.publish(msg);
        ros::spinOnce();
    } 
     void handleButton4(){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "pos 4 clicked!";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        arm_pos.publish(msg);
        ros::spinOnce();
    } 
     void handleButton5(){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "pos 5 clicked!";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        arm_pos.publish(msg);
        ros::spinOnce();
    } 
     void handleButton6(){
        std_msgs::String msg;
        std::stringstream ss;
        ss << "pos 6 clicked!";
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());

        arm_pos.publish(msg);
        ros::spinOnce();
    } 

    static void
    nuc_temp_callback(const std_msgs::Float32::ConstPtr& twist_msg) {
        nuc_temp = *twist_msg;
    }

    // static void
    // twist_left_callback(const geometry_msgs::Twist::ConstPtr& twist_msg) {
    //     twist_message_left = *twist_msg;
    // }

    // static void
    // twist_right_callback(const geometry_msgs::Twist::ConstPtr& twist_msg) {
    //     twist_message_right = *twist_msg;
    // }

    void feedback_subscriber() {
        ros::Rate loop_rate(10);
        nuc_temp_sub =
        n.subscribe("/cmd_vel", 1000, nuc_temp_callback);
        // twist_left_sub = n.subscribe(
        // "/integration_node/lwheels_pub_topic", 1000, twist_left_callback);
        // twist_right_sub = n.subscribe(
        // "/integration_node/rwheels_pub_topic", 1000, twist_right_callback);

        loop_rate.sleep();
        ros::spinOnce();
    }


  public Q_SLOTS:
    void twist_values();
    /*/private slots: Note if you want to create function from mainwindow.ui
     * delete
     * private slots and put them with public QSLOTS
     * */

  private:
    Ui::MainWindow* ui;
    QTimer* timer;
    ros::NodeHandle n;
    // twist topics
    ros::Subscriber nuc_temp_sub;
    // ros::Subscriber twist_left_sub;
    // ros::Subscriber twist_right_sub;
    ros::Publisher arm_pos;

};

#endif // MAINWINDOW_H
