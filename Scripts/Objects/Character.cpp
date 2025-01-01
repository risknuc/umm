#include "Character.hpp"

namespace umm {

Character::Character() :
    _character_animator("Resources/Character/Character.png"),
    _character_velocity(0.f, 0.f),
    _character_coordinates(window_width / 2 - (frame_width * image_scale_factor / 2),
        window_height / 2 - (frame_height * image_scale_factor / 2)) {
    if (!_character_walking_sound_buffer.loadFromFile("Resources/Sounds/CharacterWalkingSound.wav"))
        throw std::runtime_error("Unkown: load walking sound -> false");

    _character_walking_sound.setBuffer(_character_walking_sound_buffer);
    _character_walking_sound.setLoop(true);
    _character_walking_sound.setVolume(default_volume);
}

void Character::update_logic(const sf::Time& delta_time, Camera& view_camera) {
    _character_animator.update_animator_logic(delta_time);

    _update_character_velocity_vector();

    if (_character_velocity != sf::Vector2f(0.f, 0.f)) {
        if (_character_walking_sound.getStatus() != sf::Sound::Playing) _character_walking_sound.play();

        _character_coordinates += _character_velocity;

        view_camera.change_camera_target(_character_velocity);

        _character_animator.set_flip_var(_character_velocity.x > 0 ? true : false);
        _character_animator.set_selected_row(1);
    } else {
        if (_character_walking_sound.getStatus() == sf::Sound::Playing) _character_walking_sound.stop();

        _character_animator.set_selected_row(0);
    }
}

void Character::_update_character_velocity_vector(void) {
    _character_velocity = sf::Vector2f(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) _character_velocity.y = -character_speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) _character_velocity.y = character_speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _character_velocity.x = -character_speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _character_velocity.x = character_speed;
}

void Character::update_render(sf::RenderWindow& render_window, Camera& view_camera) {
    sf::Sprite character_sprite = _character_animator.request_sprite_to_render();
    character_sprite.setPosition(_character_coordinates-view_camera.request_camera_coordinates());
    render_window.draw(character_sprite);
}

const sf::Vector2f& Character::request_coordinates(void) { return _character_coordinates; }

}
