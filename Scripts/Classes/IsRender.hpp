#ifndef umm_is_render_hpp
#define umm_is_render_hpp

#include <SFML/Graphics.hpp>

#include "../Functionality/Modules/Camera.hpp"

namespace umm {

class IsRender {
public:
    virtual ~IsRender() = default;
   
    virtual void update_logic(const sf::Time& delta_time, Camera& view_camera) = 0;
    virtual void update_render(sf::RenderWindow& render_window, Camera& view_camera) = 0;

    virtual const sf::Vector2f& request_coordinates(void) = 0;
};

}

#endif
