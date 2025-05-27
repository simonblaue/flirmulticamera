#pragma once
#include <flirmulticamera/FlirCamera.h>
#include <opencv2/core.hpp>

namespace flirmulticamera{

class FlirCameraWrapper {
public:
    FlirCameraWrapper(const std::string& config_file);

    void start();
    void stop();

    std::vector<cv::Mat> get_images();

private:
    flirmulticamera::CameraSettings settings_;
    std::unique_ptr<FlirCameraHandler> fcamhandler_;
};

} // namespace flirmulticamera