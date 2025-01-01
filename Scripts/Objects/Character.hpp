#ifndef umm_character_hpp
#define umm_character_hpp

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>

#include "../Functionality/Modules/Animator.hpp"
#include "../Classes/IsRender.hpp"
#include "../Functionality/Modules/Camera.hpp"

namespace umm {

class Character : public IsRender {
public:
    Character(void);
   
    void update_logic(const sf::Time& delta_time, Camera& view_camera) override;
    void update_render(sf::RenderWindow& render_window, Camera& view_camera) override;

    const sf::Vector2f& request_coordinates(void) override;
private:
    void _update_character_velocity_vector(void);

    Animator _character_animator;

    sf::Vector2f _character_velocity, _character_coordinates;
    sf::Sound _character_walking_sound; sf::SoundBuffer _character_walking_sound_buffer;
};

}

#endif
