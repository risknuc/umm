#include "RenderQueue.hpp"

namespace umm {

void RenderQueue::render_in_queue(sf::RenderWindow& render_window, sf::Clock& window_clock, Camera& view_camera) {
    std::sort(_render_objects_list.begin(), _render_objects_list.end(),
              [](const std::shared_ptr<IsRender>& a, const std::shared_ptr<IsRender>& b) {
                  return a->request_coordinates().y < b->request_coordinates().y;
              });
    
    sf::Time delta_time = window_clock.restart();
    for (const auto& is_render : _render_objects_list) {
        is_render->update_render(render_window, view_camera);
        is_render->update_logic(delta_time, view_camera);
    }
}

void RenderQueue::append_to_rol(std::shared_ptr<IsRender> render_object) { _render_objects_list.push_back(std::move(render_object)); }

}
