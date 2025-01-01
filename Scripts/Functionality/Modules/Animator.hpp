#ifndef umm_animator_hpp
#define umm_animator_hpp

#include <SFML/Graphics.hpp>

#include "../../Config.hpp"

namespace umm {

class Animator {
public:
    explicit Animator(const char* atlas_file_path);
    
    void update_animator_logic(const sf::Time& delta_time);

    void set_selected_row(const unsigned short selected_new_row);
    void set_flip_var(const bool is_flipped);

    sf::Sprite& request_sprite_to_render(void);
private:
    sf::Sprite _animator_sprite; sf::Texture _atlas_animator_texture;
   
    unsigned short _selected_row, _selected_col, _frames_per_row, _frames_per_col, _frame_index;
    sf::Time _elapsed_time;
};

}

#endif
