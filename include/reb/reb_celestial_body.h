#ifndef REB_CELESTIAL_BODY_H
#define REB_CELESTIAL_BODY_H

#include "bn_sprite_ptr.h"
#include "bn_fixed.h"

namespace reb
{
    class celestial_body
    {
        public:
            celestial_body(bn::sprite_ptr,
                            bn::fixed primary_x,
                            bn::fixed primary_y,
                            bn::fixed orbit_radius,
                            bn::fixed start_angle_degree
                        );

            // current body position and angle
            [[nodiscard]] bn::fixed x() const;
            [[nodiscard]] bn::fixed y() const;
            [[nodiscard]] bn::fixed angle() const;
    };
}

#endif