#include "Cursor.hpp"

namespace umm {

void resize_image(const sf::Image& original_image, sf::Image& resized_image) {
    const sf::Vector2u original_image_size{ original_image.getSize() };
    const sf::Vector2u resized_image_size{ resized_image.getSize() };
    for (unsigned int y{ 0u }; y < resized_image_size.y; ++y) {
        for (unsigned int x{ 0u }; x < resized_image_size.x; ++x) {
            unsigned int orig_x{ static_cast<unsigned int>(static_cast<double>(x) / resized_image_size.x * original_image_size.x) };
            unsigned int orig_y{ static_cast<unsigned int>(static_cast<double>(y) / resized_image_size.y * original_image_size.y) };
           
            resized_image.setPixel(x, y, original_image.getPixel(orig_x, orig_y));
        }
    }
}

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
