#include <ros/ros.h>
// PCL includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

ros::Publisher pub;

void cloud_cb(const sensor_msgs::PointCloud2ConstPtr& input){
    // create a container for the data
    sensor_msgs::PointCloud2 output;

    // Do data processing here ...
    output = *input;

    pub.publish(output);
}

int main(int argc, char** argv){
    ros::init (argc, argv, "my_pcl_tutorial");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("input", 1, cloud_cb);

    pub = nh.advertise<sensor_msgs::PointCloud2>("output", 1);

    ros::spin();
}
