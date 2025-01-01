#ifndef umm_config_hpp
#define umm_config_hpp

namespace umm {

constexpr const char* window_caption_string = "umm <polygon>";
constexpr unsigned int window_framerate_limit = 72u;
constexpr unsigned int window_width = 720u;
constexpr unsigned int window_height = 440u;
constexpr unsigned int window_bpp = 32u;

constexpr unsigned int frame_height = 16u;
constexpr unsigned int frame_width = 16u;
constexpr float image_scale_factor = 3.f;

constexpr float max_hearing_distance = 512.f;
constexpr float min_volume_distance = 56.f;
constexpr float default_volume = 48.f;

constexpr int curl_walking_distance = 56;
constexpr float curl_sleep_time = 7.f;
constexpr float curl_reach_threshold = .2f;
constexpr float character_speed = 1.f;

constexpr float camera_interpolation_speed = .048f;
constexpr float frame_duration = .048f;

}

#endif
