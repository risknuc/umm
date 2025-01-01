#ifndef umm_config_hpp
#define umm_config_hpp

namespace umm {

constexpr unsigned int window_width = 720u;
constexpr unsigned int window_height = 440u;

constexpr const char* window_caption_string = "umm <polygon>";

constexpr unsigned int window_bpp = 32u;
constexpr unsigned int window_framerate_limit = 72u;

constexpr unsigned int frame_width = 16u;
constexpr unsigned int frame_height = 16u;

constexpr float image_scale_factor = 3.f;

constexpr float character_speed = 1.f;

constexpr float frame_duration = .048f;
constexpr float camera_interpolation_speed = .048f;

}

#endif
