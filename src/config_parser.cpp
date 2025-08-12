#include "flirmulticamera/config_parser.h"


namespace flirmulticamera {

bool load_camera_settings(const std::string& settings_path, CameraSettings& settings) {
    // TODO: Add checking of env constants on specific build flag
    // i.e. #IFDEFINE enable_system_checking (default on!) 
    // if (!GLOBAL_CONST_NCAMS == settings.sns.size()){spdlog::error("something something")}
    // #ENDIF
    spdlog::info("Loading camera settings from {}", settings_path);
    Document settings_doc;
    const bool success = cpp_utils::load_json_with_schema(
        settings_path, 
        std::string(CONFIG_DIR)+"/CameraSettings.Schema.json",
        DOC_BUFFER, settings_doc
    );
    settings.height = settings_doc["img_height"].GetInt();
    settings.width = settings_doc["img_width"].GetInt();
    settings.fps = settings_doc["fps"].GetDouble();
    settings.pixel_format = settings_doc["pixel_format"].GetString();
    settings.video_mode = settings_doc["video_mode"].GetString();
    settings.black_level = settings_doc["black_level"].GetDouble();
    settings.gain = settings_doc["gain"].GetDouble();
    settings.exposure_time = settings_doc["exposure_time"].GetDouble();
    settings.binning_vertical = settings_doc["binning_vertical"].GetDouble();
    settings.save_dir = settings_doc["save_dir"].GetString();
    std::string msg = "Camera settings:\n\t- width: {}\n\t- height: {}\n\t- binning_vertical: {}\n\t- pixel_format: {}\n\t- video_mode: {}\n\t- fps: {}\n\t- black_level: {}\n\t- gain: {}\n\t- exposure_time: {}";
    spdlog::info(msg,
        settings.width, 
        settings.height, 
        settings.binning_vertical, 
        settings.pixel_format, 
        settings.video_mode, 
        settings.fps, 
        settings.black_level, 
        settings.gain, 
        settings.exposure_time
    );    
    return success;
}

} // namespace flirmulticamera