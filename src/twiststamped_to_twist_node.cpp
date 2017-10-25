// Roland Arsenault
// Center for Coastal and Ocean Mapping
// University of New Hampshire
// Copyright 2017, All rights reserved.

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TwistStamped.h"

ros::Publisher pub;


void twistStampedCallback(const geometry_msgs::TwistStamped::ConstPtr& inmsg)
{
    geometry_msgs::Twist outmsg;
    outmsg.angular.x = inmsg->twist.angular.x;
    outmsg.angular.y = inmsg->twist.angular.y;
    outmsg.angular.z = inmsg->twist.angular.z;
    outmsg.linear.x = inmsg->twist.linear.x;
    outmsg.linear.y = inmsg->twist.linear.y;
    outmsg.linear.z = inmsg->twist.linear.z;
    pub.publish(outmsg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "twiststamped_to_twist");
    ros::NodeHandle n;
    
    pub = n.advertise<geometry_msgs::Twist>("/output",10);

    ros::Subscriber sub = n.subscribe("/input",10,twistStampedCallback);
    
    ros::spin();
    
    return 0;
    
}
