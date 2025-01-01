#include "Tools.hpp"

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

}
