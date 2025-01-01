#ifndef umm_camera_hpp
#define umm_camera_hpp

#include <SFML/Graphics.hpp>

#include "../../Config.hpp"

namespace umm {

class Camera {
public:
    Camera(void);
   
    void change_camera_target(const sf::Vector2f move_distance);
    void update_camera_logic(void);
   
    const sf::Vector2f& request_camera_coordinates(void);
private:
    sf::Vector2f _offset_coordinates, _target_coordinates;
};

}

#endif
