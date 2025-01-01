#include "Object.hpp"

namespace umm {

Object::Object(const char* object_vmname, sf::Vector2f object_position) :
    _object_animator(object_vmname), _object_vmname(object_vmname), _object_position(object_position) { }

void Object::update_logic(const sf::Time& delta_time, Camera& view_camera) { _object_animator.update_animator_logic(delta_time); }

void Object::update_render(sf::RenderWindow& render_window, Camera& view_camera) {
    sf::Sprite object_sprite = _object_animator.request_sprite_to_render();
    object_sprite.setPosition(_object_position-view_camera.request_camera_coordinates());
    render_window.draw(object_sprite);
}

sf::Vector2f& Object::request_coordinates(void) { return _object_position; }
const char* Object::request_object_vmname(void) { return _object_vmname; }

}
