//#include <k4a/k4a.h>
#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/point_cloud_conversion.h>
#include <std_msgs/Header.h>


//std_msgs::Header pointCloud;
sensor_msgs::PointCloud2 pointCloud;
sensor_msgs::PointCloud out_Cloud;

void callback(const sensor_msgs::PointCloud2ConstPtr& cloud_msgs){
    pointCloud = *cloud_msgs;
    sensor_msgs::convertPointCloud2ToPointCloud(pointCloud, out_Cloud);
    //std::cout << out_Cloud.points.size() << std::endl;
    //
    //
    for(int i = 0; i < out_Cloud.points.size(); ++i){
	//std::cout << out_Cloud.channels[0] << std::endl;
	
	//std::cout << "xyz value is: " << out_Cloud.channels[i]<< "," << out_Cloud.points[i].y << "," << out_Cloud.points[i].z << std::endl;
	std::cout << "xyz value is: " << out_Cloud.points[i].rgb << std::endl;

    }
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
