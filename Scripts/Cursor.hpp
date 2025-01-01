#ifndef umm_cursor_hpp
#define umm_cursor_hpp

#include <SFML/Graphics.hpp>

#include "Config.hpp"

namespace umm {

class Cursor {
public:
    Cursor(void);

    sf::Cursor& request_window_cursor(void);
private:
    sf::Cursor _window_cursor; sf::Image _original_cursor_image; sf::Image _resized_cursor_image;
};

}

#endif
