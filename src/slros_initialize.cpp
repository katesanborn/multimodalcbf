#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "multimodalcbf";

// For Block multimodalcbf/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Sub_multimodalcbf_52;

// For Block multimodalcbf/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Sub_multimodalcbf_53;

// For Block multimodalcbf/Subscribe4
SimulinkSubscriber<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Sub_multimodalcbf_54;

// For Block multimodalcbf/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Sub_multimodalcbf_55;

// For Block multimodalcbf/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Pub_multimodalcbf_49;

// For Block multimodalcbf/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Pub_multimodalcbf_93;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

