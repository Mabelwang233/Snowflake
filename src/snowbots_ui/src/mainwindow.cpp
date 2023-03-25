/*
 * Created By: Adam Nguyen
 * Created On: August 21st, 2021
 * Snowbots UI
 */

#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

// QT
#include "QDebug"
#include "QDir"
#include "QLabel"
#include "QMessageBox"
#include "QPixmap"
#include "QProcess"

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

MainWindow::MainWindow(QWidget* parent)
  :

    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("Snowbots Interface");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(twist_values()));
    ;
    timer->start(50);

    // ROS
    ros_f = new RosIntegration();
    qDebug() << "Constructor OK";

    // UI
    connect(ui->Pos1_button, &QPushButton::released, this, &MainWindow::handleButton1);
    connect(ui->Pos2_button, &QPushButton::released, this, &MainWindow::handleButton2);
    connect(ui->Pos3_button, &QPushButton::released, this, &MainWindow::handleButton3);
    connect(ui->Pos4_button, &QPushButton::released, this, &MainWindow::handleButton4);
    connect(ui->Pos5_button, &QPushButton::released, this, &MainWindow::handleButton5);
    connect(ui->Pos6_button, &QPushButton::released, this, &MainWindow::handleButton6);
    // Snowbots Logo
    QPixmap pixmap("./src/snowbots_ui/resources/snowbot2.png");
    ui->label_5->setPixmap(pixmap);
    ui->label_5->show();
    ui->label_5->setScaledContents(true);
    qDebug() << "Current dir:" << QDir::currentPath();
}
MainWindow::~MainWindow() {
    delete ui;
    qDebug() << "Destructor OK";
}

void MainWindow::twist_values() {
    ui->mode_lcd->setText(sub_msg.data.c_str()); // replace hellow world with message for mode
    ui->nuc_temp_lcd->display(twist_message_right.linear.x); // message req for updating nuc temp
    ui->rover_temp_lcd->display(twist_message_controller.angular.z); // message req for updating rover temp
    ui->elec_box_temp_lcd->display(twist_message_controller.linear.x); // message req for updating elec box temp
    ui->end_effector_force_feedback_lcd->display(twist_message_controller.linear.x); // message req for updating end effector force feeback as % of grip
    ui->end_effector_pos_feedback_lcd->display(twist_message_controller.linear.x); // message req for updating end effector position feedback
    ros_f->twist_subscriber(); // message req for updating elec box temp
}
// TODOS: 
// Current Mode - status - done
// end effector position feedback (hopefully) - ui ok
// end effector force feedback as % of grip - ui ok
// nuc temperature - done
// rover ambient temp - done
// elec box temp - done
// stored arm poses (button) - added in the ui, but still need to figure out for ros integration

//TODO: ros inegration: get texts/numbres and send messages 

void MainWindow::handleButton1()
{
    ui->Pos1_button->setText("Clicked!");
    ros::NodeHandle n;
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);

    std_msgs::String msg;
    std::stringstream ss;
    ss << "pos 1 clicked!";
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);
    ros::spinOnce();
}
void MainWindow::handleButton2()
{
  // change the text
  ui->Pos2_button->setText("Clicked!");
  // resize button
}
void MainWindow::handleButton3()
{
  // change the text
  ui->Pos3_button->setText("Clicked!");
  // resize button
}
void MainWindow::handleButton4()
{
  // change the text
  ui->Pos4_button->setText("Clicked!");
  // resize button
}
void MainWindow::handleButton5()
{
  // change the text
  ui->Pos5_button->setText("Clicked!");
  // resize button
}
void MainWindow::handleButton6()
{
  // change the text
  ui->Pos6_button->setText("Clicked!");
  // resize button
}