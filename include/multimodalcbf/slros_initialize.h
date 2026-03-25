#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "multimodalcbf_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block multimodalcbf/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Sub_multimodalcbf_52;

// For Block multimodalcbf/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Sub_multimodalcbf_53;

// For Block multimodalcbf/Subscribe4
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Sub_multimodalcbf_54;

// For Block multimodalcbf/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Sub_multimodalcbf_55;

// For Block multimodalcbf/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Pub_multimodalcbf_49;

// For Block multimodalcbf/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_multimodalcbf_std_msgs_Float64> Pub_multimodalcbf_93;

void slros_node_init(int argc, char** argv);

#endif
