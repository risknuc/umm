#include "Camera.hpp"

namespace umm {

Camera::Camera(void) : _offset_coordinates(.0f, .0f), _target_coordinates(.0f, .0f) { }

void Camera::change_camera_target(const sf::Vector2f move_distance) { _target_coordinates += move_distance; }

void Camera::update_camera_logic(void) {
    _offset_coordinates += (_target_coordinates - _offset_coordinates) * camera_interpolation_speed;
}

const sf::Vector2f& Camera::request_camera_coordinates(void) { return _offset_coordinates; }

}
