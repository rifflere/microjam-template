#ifndef REB_EARTH_H
#define REB_EARTH_H

#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_sprite_items_reb_earth.h"

namespace reb
{
    class earth
    {
        public:
            earth(bn::fixed sun_x, bn::fixed sun_y, bn::fixed orbit_radius, bn::fixed start_angle_degree);

            // current earth position and angle
            [[nodiscard]] bn::fixed x() const;
            [[nodiscard]] bn::fixed y() const;
            [[nodiscard]] bn::fixed angle() const;

        private:
            bn::sprite_ptr _earthSprite;
            bn::fixed _sun_x;
            bn::fixed _sun_y;
            bn::fixed _orbit_radius;
            bn::fixed _angle;           // degrees, 0–360
            bn::fixed _angular_speed;   // degrees per frame

            void _update_sprite_position();            
    };
}

#endif