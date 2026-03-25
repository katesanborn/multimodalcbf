#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include <ros/ros.h>
#include <std_msgs/Float64.h>

class TopicMonitorNode {
 public:
  TopicMonitorNode() : nh_(), pnh_("~") {
    sub_cmd_accel_ = nh_.subscribe("/cmd_accel", 10, &TopicMonitorNode::cmdAccelCb, this);
    sub_cmd_accel_pre_ = nh_.subscribe("/cmd_accel_pre", 10, &TopicMonitorNode::cmdAccelPreCb, this);
    sub_cbf_acc_ = nh_.subscribe("/multimodalcbf_debug/cbf_acc", 10, &TopicMonitorNode::cbfAccCb, this);
    sub_cbf_mode_ = nh_.subscribe("/multimodalcbf_debug/cbf_mode", 10, &TopicMonitorNode::cbfModeCb, this);
    sub_lead_dist_ = nh_.subscribe("/lead_dist", 10, &TopicMonitorNode::leadDistCb, this);
    sub_lead_dist_extra_ = nh_.subscribe("/lead_dist_extra", 10, &TopicMonitorNode::leadDistExtraCb, this);
    sub_rel_vel_ = nh_.subscribe("/rel_vel", 10, &TopicMonitorNode::relVelCb, this);
    sub_rel_vel_reversed_ = nh_.subscribe("/rel_vel_reversed", 10, &TopicMonitorNode::relVelReversedCb, this);
    sub_car_state_vel_x_ = nh_.subscribe("/car_state_vel_x", 10, &TopicMonitorNode::carStateVelXCb, this);
    sub_acc_set_speed_ = nh_.subscribe("/acc/set_speed", 10, &TopicMonitorNode::accSetSpeedCb, this);
    sub_acc_set_speed2_ = nh_.subscribe("/acc/set_speed2", 10, &TopicMonitorNode::accSetSpeed2Cb, this);

    const double print_rate_hz = pnh_.param("print_rate_hz", 2.0);
    const double interval = (print_rate_hz > 0.0) ? (1.0 / print_rate_hz) : 0.5;
    print_timer_ = nh_.createTimer(ros::Duration(interval), &TopicMonitorNode::printLatestValues, this);

    ROS_INFO_STREAM("topic_monitor_node started. Printing latest values at "
                    << 1.0 / interval << " Hz.");
  }

 private:
  struct TopicValue {
    bool received = false;
    double value = std::numeric_limits<double>::quiet_NaN();
  };

  static std::string formatValue(const TopicValue& topic_value) {
    if (!topic_value.received) {
      return "(no data yet)";
    }

    std::ostringstream stream;
    stream << std::fixed << std::setprecision(4) << topic_value.value;
    return stream.str();
  }

  void printLatestValues(const ros::TimerEvent&) {
    std::ostringstream output;
      output << "\033[2J\033[H"
        << "=== Topic Monitor (latest values) ===\n"
           << std::left << std::setw(32) << "/cmd_accel" << ": " << formatValue(cmd_accel_) << "\n"
           << std::left << std::setw(32) << "/cmd_accel_pre" << ": " << formatValue(cmd_accel_pre_) << "\n"
           << std::left << std::setw(32) << "/multimodalcbf_debug/cbf_acc" << ": " << formatValue(cbf_acc_) << "\n"
           << std::left << std::setw(32) << "/multimodalcbf_debug/cbf_mode" << ": " << formatValue(cbf_mode_) << "\n"
           << std::left << std::setw(32) << "/lead_dist" << ": " << formatValue(lead_dist_) << "\n"
           << std::left << std::setw(32) << "/lead_dist_extra" << ": " << formatValue(lead_dist_extra_) << "\n"
           << std::left << std::setw(32) << "/rel_vel" << ": " << formatValue(rel_vel_) << "\n"
           << std::left << std::setw(32) << "/rel_vel_reversed" << ": " << formatValue(rel_vel_reversed_) << "\n"
           << std::left << std::setw(32) << "/car_state_vel_x" << ": " << formatValue(car_state_vel_x_) << "\n"
           << std::left << std::setw(32) << "/acc/set_speed" << ": " << formatValue(acc_set_speed_) << "\n"
           << std::left << std::setw(32) << "/acc/set_speed2" << ": " << formatValue(acc_set_speed2_) << "\n"
        << "\nPress Ctrl+C to exit.\n";
      std::cout << output.str() << std::flush;
  }

  void cmdAccelCb(const std_msgs::Float64::ConstPtr& msg) {
    cmd_accel_.received = true;
    cmd_accel_.value = msg->data;
  }

  void cmdAccelPreCb(const std_msgs::Float64::ConstPtr& msg) {
    cmd_accel_pre_.received = true;
    cmd_accel_pre_.value = msg->data;
  }

  void cbfAccCb(const std_msgs::Float64::ConstPtr& msg) {
    cbf_acc_.received = true;
    cbf_acc_.value = msg->data;
  }

  void cbfModeCb(const std_msgs::Float64::ConstPtr& msg) {
    cbf_mode_.received = true;
    cbf_mode_.value = msg->data;
  }

  void leadDistCb(const std_msgs::Float64::ConstPtr& msg) {
    lead_dist_.received = true;
    lead_dist_.value = msg->data;
  }

  void leadDistExtraCb(const std_msgs::Float64::ConstPtr& msg) {
    lead_dist_extra_.received = true;
    lead_dist_extra_.value = msg->data;
  }

  void relVelCb(const std_msgs::Float64::ConstPtr& msg) {
    rel_vel_.received = true;
    rel_vel_.value = msg->data;
  }

  void relVelReversedCb(const std_msgs::Float64::ConstPtr& msg) {
    rel_vel_reversed_.received = true;
    rel_vel_reversed_.value = msg->data;
  }

  void carStateVelXCb(const std_msgs::Float64::ConstPtr& msg) {
    car_state_vel_x_.received = true;
    car_state_vel_x_.value = msg->data;
  }

  void accSetSpeedCb(const std_msgs::Float64::ConstPtr& msg) {
    acc_set_speed_.received = true;
    acc_set_speed_.value = msg->data;
  }

  void accSetSpeed2Cb(const std_msgs::Float64::ConstPtr& msg) {
    acc_set_speed2_.received = true;
    acc_set_speed2_.value = msg->data;
  }

  ros::NodeHandle nh_;
  ros::NodeHandle pnh_;

  ros::Subscriber sub_cmd_accel_;
  ros::Subscriber sub_cmd_accel_pre_;
  ros::Subscriber sub_cbf_acc_;
  ros::Subscriber sub_cbf_mode_;
  ros::Subscriber sub_lead_dist_;
  ros::Subscriber sub_lead_dist_extra_;
  ros::Subscriber sub_rel_vel_;
  ros::Subscriber sub_rel_vel_reversed_;
  ros::Subscriber sub_car_state_vel_x_;
  ros::Subscriber sub_acc_set_speed_;
  ros::Subscriber sub_acc_set_speed2_;

  ros::Timer print_timer_;

  TopicValue cmd_accel_;
  TopicValue cmd_accel_pre_;
  TopicValue cbf_acc_;
  TopicValue cbf_mode_;
  TopicValue lead_dist_;
  TopicValue lead_dist_extra_;
  TopicValue rel_vel_;
  TopicValue rel_vel_reversed_;
  TopicValue car_state_vel_x_;
  TopicValue acc_set_speed_;
  TopicValue acc_set_speed2_;
};

int main(int argc, char** argv) {
  ros::init(argc, argv, "topic_monitor_node");
  TopicMonitorNode node;
  ros::spin();
  return 0;
}
