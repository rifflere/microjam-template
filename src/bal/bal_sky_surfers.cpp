#include "bal_sky_surfers.h"
#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = { "Pasha, Hosea" };
    constexpr bn::string_view graphics_credits[] = { "" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

MJ_GAME_LIST_ADD(bal::bal_sky_surfers)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace bal
{
bal_sky_surfers::bal_sky_surfers([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("bal"),
    _bal_player(player({20, 0}, 2))
    {}


bn::string<16> bal_sky_surfers::title() const {
    return "Dodge the rocks";
}

int bal_sky_surfers::total_frames() const {
    return 600; // 600 frames at 60fps = 10 seconds
}

mj::game_result bal_sky_surfers::play([[maybe_unused]] const mj::game_data& data)
{

    _bal_player.update();

    mj::game_result result(victory(), false);
    return result;
}

bool bal_sky_surfers::victory() const {
    return 0;
}

void bal_sky_surfers::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

void bal_sky_surfers::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

}