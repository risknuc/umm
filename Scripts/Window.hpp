#ifndef umm_window_hpp
#define umm_window_hpp

#include <SFML/Graphics.hpp>
#include <memory>

#include "Functionality/RenderQueue.hpp"
#include "Classes/IsRender.hpp"
#include "Cursor.hpp"
#include "Objects/Character.hpp"
#include "Objects/Object.hpp"
#include "Config.hpp"
#include "Functionality/Modules/Camera.hpp"

namespace umm {

class Window {
public:
    Window(void);

    int run_window_mainloop(void);
private:
    inline void _window_poll_event(void);
    inline void _update_window_render_logic(void);
   
    RenderQueue _render_queue; Camera _view_camera; Cursor _window_cursor;
    sf::Clock _window_clock; sf::RenderWindow _render_window;
};

}

#endif
