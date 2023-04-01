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
    //n = new ros::NodeHandle();
    arm_pos = n.advertise<std_msgs::String>("chatter", 1000);
    ui->setupUi(this);
    this->setWindowTitle("Snowbots Interface");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(twist_values()));
    ;
    timer->start(50);

    // ROS
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
    ros::Rate(10).sleep();//probably want to make this ros::Rate
    ros::spinOnce();
    qDebug() << "Destructor OK";
}

void MainWindow::twist_values() {
    ui->mode_lcd->setText("hello"); // replace hellow world with message for mode
    ui->nuc_temp_lcd->display(nuc_temp.data); // message req for updating nuc temp
    ui->rover_temp_lcd->display(nuc_temp.data); // message req for updating rover temp
    ui->elec_box_temp_lcd->display(nuc_temp.data); // message req for updating elec box temp
    ui->end_effector_force_feedback_lcd->display(nuc_temp.data); // message req for updating end effector force feeback as % of grip
    ui->end_effector_pos_feedback_lcd->display(nuc_temp.data); // message req for updating end effector position feedback
    feedback_subscriber(); // message req for updating elec box temp
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