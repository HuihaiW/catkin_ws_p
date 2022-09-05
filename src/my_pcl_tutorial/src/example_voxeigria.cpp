#include <ros/ros.h>

#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/filters/voxel_grid.h>

ros::Publisher pub;

void cloud_cb (const sensor_msgs::PointCloud2ConstPtr& cloud_msg){
    pcl::PCLPointCloud2 pcl_pcl2;
    pcl_conversions::toPCL(*msg, pcl_pcl2);

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud()

    pcl_conversions::toPCL(*cloud_msg, *cloud);
    

}

int main(int argc, char** argv){
    ros::init (argc, argv, "my_pcl_tutorial");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe<sensor_msgs::PointCloud2>("input", 1, cloud_cb);

    pub = nh.advertise<sensor_msgs::PointCloud2>("output", 1);

    ros::spin();
}
