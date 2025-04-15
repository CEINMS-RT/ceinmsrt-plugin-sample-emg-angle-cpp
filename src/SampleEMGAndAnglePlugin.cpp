#include "SampleEMGAndAnglePlugin.h"
#include <iostream>

SampleEMGAndAnglePlugin::SampleEMGAndAnglePlugin()
    : timeStamp_(0.0), verbosity_(0), record_(false), outDirectory_("output") {}

SampleEMGAndAnglePlugin::~SampleEMGAndAnglePlugin() {}

void SampleEMGAndAnglePlugin::init(std::string executionXMLFile, std::string subjectCEINMSXMLFile) {
    std::cout << "[Plugin] Initialized with execution XML: " << executionXMLFile
              << ", subject XML: " << subjectCEINMSXMLFile << std::endl;

    // You can parse the XML files here if necessary
    emgData_.clear();
    angleData_.clear();

    // Example default entries
    emgData_["biceps"] = 0.5;
    emgData_["triceps"] = 0.4;
    angleData_["elbow_angle_r"] = 0.2;
    angleData_["elbow_angle_l"] = -0.2;
    timeStamp_ = 0.0;
}

void SampleEMGAndAnglePlugin::reset() {
    std::cout << "[Plugin] Resetting plugin state." << std::endl;
    emgData_.clear();
    angleData_.clear();
    timeStamp_ = 0.0;
}

void SampleEMGAndAnglePlugin::stop() {
    std::cout << "[Plugin] Stop called. Finalizing plugin." << std::endl;
    // Optional: flush buffers, close files, etc.
}

const std::map<std::string, double>& SampleEMGAndAnglePlugin::GetDataMap() {
    // Return EMG data; you can replace this with live or calculated values
    return emgData_;
}

const std::map<std::string, double>& SampleEMGAndAnglePlugin::GetDataMapPos() {
    // Return angle data
    return angleData_;
}

const double& SampleEMGAndAnglePlugin::getTime() {
    // Return the current timestamp
    return timeStamp_;
}

void SampleEMGAndAnglePlugin::setDirectories(std::string outDirectory, std::string inDirectory) {
    outDirectory_ = outDirectory;
    inDirectory_ = inDirectory;
    std::cout << "[Plugin] Output directory set to: " << outDirectory_
              << ", Input directory: " << inDirectory_ << std::endl;
}

void SampleEMGAndAnglePlugin::setVerbose(int verbose) {
    verbosity_ = verbose;
    std::cout << "[Plugin] Verbosity set to: " << verbosity_ << std::endl;
}

void SampleEMGAndAnglePlugin::setRecord(bool record) {
    record_ = record;
    std::cout << "[Plugin] Record flag set to: " << std::boolalpha << record_ << std::endl;
}
