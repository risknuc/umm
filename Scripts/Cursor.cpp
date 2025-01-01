#include "Cursor.hpp"

namespace umm {

Cursor::Cursor(void) {
    if (!_original_cursor_image.loadFromFile("Resources/Cursor.png"))
        throw std::runtime_error("Unkown: load cursor image -> false");

    sf::Vector2u tmp_size(
        _original_cursor_image.getSize().x * image_scale_factor,
        _original_cursor_image.getSize().y * image_scale_factor);

    _resized_cursor_image.create(tmp_size.x, tmp_size.y, sf::Color::Transparent);
    resize_image(_original_cursor_image, _resized_cursor_image);
    
    if (!_window_cursor.loadFromPixels(_resized_cursor_image.getPixelsPtr(), _resized_cursor_image.getSize(), sf::Vector2u(0, 0)))
        throw std::runtime_error("Unkown: create cursor from pixels -> false");
}

sf::Cursor& Cursor::request_window_cursor(void) { return _window_cursor; }

}
