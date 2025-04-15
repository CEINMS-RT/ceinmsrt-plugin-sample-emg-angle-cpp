#ifndef SAMPLEEMGANDANGLEPLUGIN_H
#define SAMPLEEMGANDANGLEPLUGIN_H

#include <EMGAndAnglePlugin.h>
#include <string>
#include <map>

/**
 * @brief Minimal implementation of the EMGAndAnglePlugin interface.
 *
 * Stores mock EMG and position data and allows the CEINMS-RT core to query it.
 */
class SampleEMGAndAnglePlugin : public EMGAndAnglePlugin {
public:
    /**
     * @brief Constructor.
     */
    SampleEMGAndAnglePlugin();

    /**
     * @brief Destructor.
     */
    ~SampleEMGAndAnglePlugin();

    /**
     * @brief Initialize the plugin using execution and subject XML files.
     * @param executionXMLFile Path to execution configuration.
     * @param subjectCEINMSXMLFile Path to subject-specific CEINMS configuration.
     */
    void init(std::string executionXMLFile = std::string(), std::string subjectCEINMSXMLFile = std::string()) override;

    /**
     * @brief Reset internal plugin state.
     */
    void reset() override;

    /**
     * @brief Stop plugin execution.
     */
    void stop() override;

    /**
     * @brief Get EMG data.
     * @return Map of muscle name to EMG value.
     */
    const std::map<std::string, double>& GetDataMap() override;

    /**
     * @brief Get position (angle) data.
     * @return Map of DOF name to angle value.
     */
    const std::map<std::string, double>& GetDataMapPos() override;

    /**
     * @brief Get the current simulation timestamp.
     * @return Reference to timestamp value.
     */
    const double& getTime() override;

    /**
     * @brief Set output and optional input directories.
     * @param outDirectory Output directory.
     * @param inDirectory Input directory (optional).
     */
    void setDirectories(std::string outDirectory, std::string inDirectory = std::string()) override;

    /**
     * @brief Set verbosity level.
     * @param verbose Verbosity level.
     */
    void setVerbose(int verbose) override;

    /**
     * @brief Enable or disable data recording.
     * @param record Boolean flag.
     */
    void setRecord(bool record) override;

private:
    std::map<std::string, double> emgData_;     ///< EMG signal data
    std::map<std::string, double> angleData_;   ///< Position (angle) data
    double timeStamp_;                          ///< Current time value
    std::string outDirectory_;                  ///< Output directory path
    std::string inDirectory_;                   ///< Input directory path
    int verbosity_;                             ///< Verbosity level
    bool record_;                               ///< Recording flag
};

#endif // SAMPLEEMGANDANGLEPLUGIN_H
