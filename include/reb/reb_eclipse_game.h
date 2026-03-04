#ifndef REB_ECLIPSE_GAME_H
#define REB_ECLIPSE_GAME_H

#include "bn_sprite_ptr.h"
#include "mj/mj_game.h"
#include "bn_sprite_items_reb_sun.h"
#include "bn_sprite_items_reb_moon.h"
#include "bn_sprite_items_reb_earth.h"
#include "bn_sprite_animate_actions.h"
#include "bn_optional.h"

namespace reb
{

    class reb_eclipse_game : public mj::game
    {
        public:

            static constexpr int minimum_frames = 3 * 60; 
            static constexpr int maximum_frames = 5 * 60; 

            reb_eclipse_game(int completed_games, const mj::game_data& data);

            [[nodiscard]] bn::string<16> title() const final
            {
                return "Solar Eclipse";
            }

            [[nodiscard]] int total_frames() const final
            {
                return minimum_frames;
            }

            void fade_in(const mj::game_data& data) final;

            [[nodiscard]] mj::game_result play(const mj::game_data& data) final;

            [[nodiscard]] bool victory() const final;

            void fade_out(const mj::game_data& data) final;

        private:
            bn::sprite_ptr _sunSprite = bn::sprite_items::reb_sun.create_sprite(-105,0);
            bn::sprite_ptr _earthSprite = bn::sprite_items::reb_earth.create_sprite(75,0);
            bool _victory;
    };
}

#endif