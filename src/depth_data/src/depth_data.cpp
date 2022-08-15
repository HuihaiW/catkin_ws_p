//#include <k4a/k4a.h>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <std_msgs/Header.h>

//std_msgs::Header pointCloud;
sensor_msgs::PointCloud2 pointCloud;

void callback(const sensor_msgs::PointCloud2ConstPtr& cloud_msgs){
    pointCloud = *cloud_msgs;
    //std::cout << pointCloud.seq << std::endl;
    std::cout << "output something" << std::endl;
}

int main(int argc, char **argv){
    ros::init(argc, argv, "depth_data");
    ros::NodeHandle nh;
    ros::Rate loop_rate(30);
    std::string topic = nh.resolveName("/points2");
    uint32_t queue_size = 1;
    ros::Subscriber sub = nh.subscribe(topic, queue_size, callback);



    
    ros::spin();

    //return 0;
}
