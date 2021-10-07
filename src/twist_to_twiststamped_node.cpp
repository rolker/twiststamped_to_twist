// Roland Arsenault
// Center for Coastal and Ocean Mapping
// University of New Hampshire
// Copyright 2017, All rights reserved.

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/TwistStamped.h"

ros::Publisher pub;
std::string frame_id;

void twistCallback(const geometry_msgs::Twist::ConstPtr& inmsg)
{
    geometry_msgs::TwistStamped outmsg;
    outmsg.header.stamp = ros::Time::now();
    outmsg.header.frame_id = frame_id;
    outmsg.twist = *inmsg;
    pub.publish(outmsg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "twist_to_twiststamped");

    ros::param::param<std::string>("~frame_id", frame_id, "base_link");

    ros::NodeHandle n;
    
    pub = n.advertise<geometry_msgs::TwistStamped>("output",10);

    ros::Subscriber sub = n.subscribe("input",10,twistCallback);
    
    ros::spin();
    
    return 0;
    
}
