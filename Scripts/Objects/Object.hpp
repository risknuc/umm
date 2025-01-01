#ifndef umm_object_hpp
#define umm_object_hpp

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "../Functionality/Modules/Animator.hpp"
#include "../Functionality/Modules/Camera.hpp"
#include "../Classes/IsRender.hpp"

namespace umm {

class Object : public IsRender {
public:
    Object(const char* object_vmname, sf::Vector2f object_position);

    void update_logic(const sf::Time& delta_time, Camera& view_camera) override;
    void update_render(sf::RenderWindow& render_window, Camera& view_camera) override;

    const sf::Vector2f& request_coordinates(void) override;
    const char* request_object_vmname(void);
private:
    Animator _object_animator; sf::Vector2f _object_position; const char* _object_vmname;
};

}

#endif
