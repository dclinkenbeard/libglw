//
// Created by Garrett on 11/25/21.
//

#ifndef GLW_INPUT_HPP
#define GLW_INPUT_HPP

#include "key_codes.hpp"

#include <functional>



/**
 * the "cb" at the end of our variables makes me believe they might be callback functions
 *
 *
 * DEFINITION:
 * A callback function is a function passed into another function as an argument, which is then
 * invoked inside the outer function to complete some kind of routine or action.
 *
 *
 * One reason to use callbacks is to write generic code which is independent from the logic
 * in the called function and can be reused with different callbacks.
 *
 */namespace glw {

using key_down_cb = std::function<void(int)>;
/**
 * These are here to obtain the desired behaviour when a certain key is pressed.
 * If the player chooses to change direction, the object can change its direction
 */
 using key_up_cb = std::function<void(int)>;
using mouse_button_down_cb = std::function<void(int)>;
using mouse_button_up_cb = std::function<void(int)>;
using mouse_move_cb = std::function<void(double, double)>;

class input {
public:
    input();
    virtual ~input();

    float get_mouse_x();
    float get_mouse_y();
    std::pair<float, float> get_mouse_pos();

    key_down_cb key_down;
    key_up_cb key_up;
    mouse_button_down_cb mouse_btn_down;
    mouse_button_up_cb mouse_btn_up;
    mouse_move_cb mouse_move;
};

}

#endif //GLW_INPUT_HPP
