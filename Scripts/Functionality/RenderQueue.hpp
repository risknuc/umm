#ifndef umm_render_queue_hpp
#define umm_render_queue_hpp

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

#include "../Classes/IsRender.hpp"
#include "Modules/Camera.hpp"

namespace umm {

class RenderQueue {
public:
    void render_in_queue(sf::RenderWindow& render_window, sf::Clock& window_clock, Camera& view_camera);
    void append_to_rol(std::shared_ptr<IsRender> render_object);
private:
    std::vector<std::shared_ptr<IsRender>> _render_objects_list;
};

}

#endif
