// Roland Arsenault
// Center for Coastal and Ocean Mapping
// University of New Hampshire
// Copyright 2017, All rights reserved.

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TwistStamped.h"

ros::Publisher pub;


void twistCallback(const geometry_msgs::Twist::ConstPtr& inmsg)
{
    geometry_msgs::TwistStamped outmsg;
    outmsg.header.stamp = ros::Time::now();
    outmsg.twist.angular.x = inmsg->angular.x;
    outmsg.twist.angular.y = inmsg->angular.y;
    outmsg.twist.angular.z = inmsg->angular.z;
    outmsg.twist.linear.x = inmsg->linear.x;
    outmsg.twist.linear.y = inmsg->linear.y;
    outmsg.twist.linear.z = inmsg->linear.z;
    pub.publish(outmsg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "twist_to_twiststamped");
    ros::NodeHandle n;
    
    pub = n.advertise<geometry_msgs::TwistStamped>("/output",10);

    ros::Subscriber sub = n.subscribe("/input",10,twistCallback);
    
    ros::spin();
    
    return 0;
    
}
