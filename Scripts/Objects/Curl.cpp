#include "Curl.hpp"

namespace umm {

Curl::Curl() :
    _curl_animator("Resources/Curl/Curl.png"),
    _curl_target_coordinates(window_width / 2 - (frame_width * image_scale_factor / 2),
                      window_height / 2 - (frame_height * image_scale_factor / 2)),
    _curl_coordinates(window_width / 2 - (frame_width * image_scale_factor / 2),
                      window_height / 2 - (frame_height * image_scale_factor / 2)),
    _curl_velocity(0.f, 0.f), _gen(_rd()), _distrib(-56, 56) {

    if (!_curl_walking_sound_buffer.loadFromFile("Resources/Sounds/CharacterWalkingSound.wav"))
        throw std::runtime_error("Unknown: load walking sound -> false");

    _curl_walking_sound.setBuffer(_curl_walking_sound_buffer);
    _curl_walking_sound.setLoop(true);
    _curl_walking_sound.setVolume(48u);
}

void Curl::update_logic(const sf::Time& delta_time, Camera& view_camera) {
    _curl_animator.update_animator_logic(delta_time);

    sf::Vector2f direction = _curl_target_coordinates - _curl_coordinates;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0.01f) {
        sf::Vector2f normalized_direction = direction / distance;
        sf::Vector2f velocity_float = normalized_direction * character_speed;
        _curl_velocity = sf::Vector2f(std::round(velocity_float.x), std::round(velocity_float.y));
    } else {
        _curl_velocity = { 0, 0 }; 
    }

    if (_curl_velocity != sf::Vector2f(0.f, 0.f)) {
        if (_curl_walking_sound.getStatus() != sf::Sound::Playing) 
            _curl_walking_sound.play();

        _curl_coordinates += _curl_velocity;

        _curl_animator.set_flip_var(_curl_velocity.x > 0 ? true : false);
        _curl_animator.set_selected_row(1);
    } else {
        if (_curl_walking_sound.getStatus() == sf::Sound::Playing) 
            _curl_walking_sound.stop();

        _curl_animator.set_selected_row(0);
    }

    if (_curl_movement_timer.getElapsedTime() >= sf::seconds(7)) {
        _curl_target_coordinates = sf::Vector2f(
            _curl_target_coordinates.x + (_distrib(_gen)), _curl_target_coordinates.y + (_distrib(_gen)));
        _curl_movement_timer.restart();
    }

    float camera_curl_distance = std::sqrt(
    std::pow((_curl_coordinates.x - (view_camera.request_camera_coordinates().x + window_width / 2) + (frame_width * image_scale_factor / 2)), 2) +
    std::pow((_curl_coordinates.y - (view_camera.request_camera_coordinates().y + window_height / 2) + (frame_height * image_scale_factor / 2)), 2));

    float volume = std::max(0.f, std::min(48.f, (48.f * 2 * image_scale_factor - camera_curl_distance)));
    _curl_walking_sound.setVolume(volume);
}

void Curl::update_render(sf::RenderWindow& render_window, Camera& view_camera) {
    sf::Sprite curl_sprite = _curl_animator.request_sprite_to_render();
    curl_sprite.setPosition(_curl_coordinates - view_camera.request_camera_coordinates());
    render_window.draw(curl_sprite);
}

sf::Vector2f& Curl::request_coordinates() {
    return _curl_coordinates;
}

}
