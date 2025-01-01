#include "Animator.hpp"

namespace umm {

Animator::Animator(const char* atlas_file_path) : _frame_index(0.f), _selected_row(0.f), _selected_col(0.f) {
    if (!_atlas_animator_texture.loadFromFile(atlas_file_path))
        throw std::runtime_error("Unkown: load animations atlas -> false");

    _animator_sprite.setTexture(_atlas_animator_texture);
    _animator_sprite.setScale(image_scale_factor, image_scale_factor);

    _frames_per_row = _atlas_animator_texture.getSize().x / frame_width;
    _frames_per_col = _atlas_animator_texture.getSize().y / frame_height;
}

void Animator::update_animator_logic(const sf::Time& delta_time) {
    _elapsed_time += delta_time;
    if (_elapsed_time.asSeconds() >= frame_duration) {
        _elapsed_time -= sf::seconds(frame_duration);

        _frame_index = (_frame_index + 1) % (_frames_per_row * _frames_per_col);
        _selected_col = _frame_index % _frames_per_row;
    }
}

void Animator::set_selected_row(const unsigned short selected_new_row) {
    if (selected_new_row < _frames_per_col) _selected_row = selected_new_row;
}

void Animator::set_flip_var(const bool is_flipped) {
    sf::FloatRect bounds = _animator_sprite.getLocalBounds();
    if (is_flipped) {
        _animator_sprite.setScale(image_scale_factor, image_scale_factor);
        _animator_sprite.setOrigin(0.f, 0.f);
    } else {
        _animator_sprite.setScale(-image_scale_factor, image_scale_factor);
        _animator_sprite.setOrigin(bounds.width, 0.f);
    }
}

const sf::Sprite& Animator::request_sprite_to_render(void) {
    sf::IntRect frame_rect(_selected_col * frame_width, _selected_row * frame_height, 
        frame_width, frame_height);
    _animator_sprite.setTextureRect(frame_rect);
    
    return _animator_sprite;
}

}
