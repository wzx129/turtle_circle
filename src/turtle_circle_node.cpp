#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "turtle_circle_node");
    ros::NodeHandle nh;

    // 两个可配置参数：周期（转一圈几秒）、幅值（线速度大小）
    double period = 4.0;
    double amplitude = 1.0;
    nh.param<double>("period", period, 4.0);
    nh.param<double>("amplitude", amplitude, 1.0);

    // 发布速度指令到 /turtle1/cmd_vel
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate rate(20);

    const double PI = 3.141592653589793;
    geometry_msgs::Twist vel;
    vel.linear.x = amplitude;              // 线速度（幅值 → 圈的大小）
    vel.angular.z = 2.0 * PI / period;     // 角速度（周期 → 转圈快慢）

    ROS_INFO("turtle_circle running: amplitude=%.2f, period=%.2f", amplitude, period);

    while (ros::ok())
    {
        pub.publish(vel);
        rate.sleep();
    }

    return 0;
}
