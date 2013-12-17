#ifndef PR2_SOT_CONTROLLER_H
#define PR2_SOT_CONTROLLER_H

#include <sot_youbot/youbot_device.h>
#include <dynamic_graph_bridge/ros_interpreter.hh>
#include <sot/core/abstract-sot-external-interface.hh>

namespace sot_youbot {

class YoubotSotController : public dynamicgraph::sot::AbstractSotExternalInterface
{
public:
    static const std::string LOG_PYTHON;

public:
    explicit YoubotSotController(std::string name);
    virtual ~YoubotSotController();

    void setupSetSensors(SensorMap &sensorsIn);
    void nominalSetSensors(SensorMap &sensorsIn);
    void cleanupSetSensors(SensorMap &sensorsIn);

    void getControl(ControlMap &controlOut);

    boost::shared_ptr<dynamicgraph::Interpreter> interpreter_;
    ros::NodeHandle node_;

protected:
    void updateRobotState(std::vector<double> &anglesIn);

    void runPython(std::ostream &file,
                   const std::string &command,
                   dynamicgraph::Interpreter &interpreter);

    virtual void startupPython();

private:
    YoubotDevice device_;
};

}

#endif
