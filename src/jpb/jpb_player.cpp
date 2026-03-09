#include "jpb/jpb_player.h"
#include <bn_keypad.h>
#include "bn_sprite_items_jpb_ship.h"

namespace jpb {
    jpb_player::jpb_player(bn::fixed_point starting_position, bn::fixed_point enemy_position, bn::fixed _speed) :
        player_sprite(bn::sprite_items::jpb_ship.create_sprite(starting_position)),
        enemy_sprite(bn::sprite_items::jpb_ship.create_sprite(enemy_position)),
        speed(_speed)
    {}

    void jpb_player::update() {
        if(bn::keypad::left_held()) {
            player_sprite.set_x(player_sprite.x() - speed);
        }
        if(bn::keypad::right_held()) {
            player_sprite.set_x(player_sprite.x() + speed);
        }
        if(bn::keypad::up_held()) {
            player_sprite.set_y(player_sprite.y() - speed);
        }
        if(bn::keypad::down_held()) {
            player_sprite.set_y(player_sprite.y() + speed);
        }
    }

    // We'll improve this to have bounding boxes next wave
    bool jpb_player::enemy_intersect() const {
        return player_sprite.x() == enemy_sprite.x() && player_sprite.y() == enemy_sprite.y();
    }
}