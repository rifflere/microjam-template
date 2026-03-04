#include "reb_eclipse_game.h"

#include "bn_keypad.h"
#include "bn_sprite_ptr.h"

#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = { "Rebecca Riffle" };
    constexpr bn::string_view graphics_credits[] = { "" };
    constexpr bn::string_view sfx_credits[] = {""};
}

MJ_GAME_LIST_ADD(reb::reb_eclipse_game)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
// MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace reb
{
    reb_eclipse_game::reb_eclipse_game([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
        mj::game("reb")
    {
    }

    void reb_eclipse_game::fade_in([[maybe_unused]] const mj::game_data& data)
    {
        _sunSprite.set_position(-100, 0);
        _earthSprite.set_position(75, 0);
    }

    mj::game_result reb_eclipse_game::play([[maybe_unused]] const mj::game_data& data)
    {
        _victory = false;

        mj::game_result result(victory(), false);

        return result;
    }

    bool reb_eclipse_game::victory() const
    {
        return _victory;
    }

    void reb_eclipse_game::fade_out([[maybe_unused]] const mj::game_data& data)
    {
    }

}