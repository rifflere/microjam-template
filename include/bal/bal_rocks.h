#ifndef BAL_ROCKS_H
#define BAL_ROCKS_H

#include <bn_display.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_rect.h>
#include <bn_size.h>

namespace bal{

class rock{
        //GBA screen size
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = - bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = - bn::display::height() / 2;

    public:
        rock(int starting_x, int starting_y, bn::fixed speed, bn::size rock_size);

        bool update();

        bn::sprite_ptr sprite;
        bn::fixed speed;
        bn::size size;
        bn::rect bounding_box;
};

}

#endif