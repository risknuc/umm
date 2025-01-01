#include "Window.hpp"

namespace umm {

Window::Window(void) :
    _render_window(sf::VideoMode(window_width, window_height, window_bpp), window_caption_string, sf::Style::Close) {
    _render_window.setFramerateLimit(window_framerate_limit);
}

const char Window::run_window_mainloop(void) {
    _render_queue.append_to_rol(std::make_shared<Character>());
    _render_queue.append_to_rol(std::make_shared<Curl>());

    _render_window.setMouseCursor(_window_cursor.request_window_cursor());
   
    while (_render_window.isOpen()) { _window_poll_event(); _update_window_render_logic(); }

    return EXIT_SUCCESS;
}

inline void Window::_update_window_render_logic(void) {
    _view_camera.update_camera_logic();
    
    _render_window.clear(sf::Color::White);
    _render_queue.render_in_queue(_render_window, _window_clock, _view_camera);
    
    _render_window.display();
}

inline void Window::_window_poll_event(void) {
    sf::Event event;
    while (_render_window.pollEvent(event)) { 
        if (event.type == sf::Event::Closed)   _render_window.close(); 
    }
}

}
