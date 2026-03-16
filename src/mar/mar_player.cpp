#include "mar/mar_player.h"

#include <bn_keypad.h>
#include <bn_rect.h>

#include "bn_sprite_items_square.h"
#include "bn_sprite_items_droid.h"

// All game functions/classes/variables/constants scoped to the namespace
namespace mar
{

    /**
     * mar_player constructor
     *
     * @param starting_position the location to start the mar_player at
     * @param speed the pixels/frame the mar_player moves at in each dimension
     */
    mar_player::mar_player(
        bn::fixed_point starting_position,
        bn::fixed speed) : _sprite(bn::sprite_items::droid.create_sprite(starting_position)),
                           _speed(speed),
                           _rect(
                               bn::rect(
                                   starting_position.x().round_integer(),
                                   starting_position.y().round_integer(), 8, 8))
    {
    }

    /**
     * Reads from the d-pad and moves the mar_player by one frame accordingly.
     */
    void mar_player::update()
    {
        // thrust buildup while up is held, resets when released
        if (bn::keypad::up_held() && _sprite.y() > MIN_Y)
        {
            _thrust_up += bn::fixed(0.2);
            if (_thrust_up >= bn::fixed(1.5))
            {
                _thrust_up = bn::fixed(1.5);
            }
        }
        else
        {
            _thrust_up = bn::fixed(0.5);
        }

        // gravity always applies
        _velocity += _gravity;

        // jetpack counters gravity
        if (bn::keypad::up_held() && _sprite.y() > MIN_Y)
        {
            _velocity -= _thrust_up;
        }

        // fast fall
        if (bn::keypad::down_held() && _sprite.y() < MAX_Y)
        {
            _velocity += _gravity * bn::fixed(2);
        }

        // apply velocity
        _sprite.set_y(_sprite.y() + _velocity);

        // clamps — keeps player on screen
        if (_sprite.y() >= MAX_Y)
        {
            _sprite.set_y(MAX_Y);
            _velocity = bn::fixed(0);
        }
        if (_sprite.y() <= MIN_Y)
        {
            _sprite.set_y(MIN_Y);
            _velocity = bn::fixed(0);
        }

        _rect.set_position(
            _sprite.x().round_integer(),
            _sprite.y().round_integer());
    }
}