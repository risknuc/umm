#ifndef umm_curl_hpp
#define umm_curl_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>

#include "../Functionality/Modules/Animator.hpp"
#include "../Classes/IsRender.hpp"
#include "../Functionality/Modules/Camera.hpp"
#include "../Config.hpp"

namespace umm {

class Curl : public IsRender {
public:
    Curl(void);
   
    void update_logic(const sf::Time& delta_time, Camera& view_camera) override;
    void update_render(sf::RenderWindow& render_window, Camera& view_camera) override;

    const sf::Vector2f& request_coordinates(void) override;
private:
    void _update_curl_volume_by_distance(Camera& view_camera);
    void _create_new_curl_target_coordinates(void);

    Animator _curl_animator; sf::Clock _curl_movement_timer;

    std::random_device _rd; std::mt19937 _gen; std::uniform_int_distribution<> _distrib;

    sf::Vector2f _curl_target_coordinates, _curl_coordinates, _curl_velocity;
    sf::Sound _curl_walking_sound; sf::SoundBuffer _curl_walking_sound_buffer;
};

}

#endif
