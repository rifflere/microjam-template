#include "bal_sky_surfers.h"

namespace bal
{
bal_sky_surfers::bal_sky_surfers([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("bal")
    {}


bn::string<16> bal_sky_surfers::title() const {
    return "Dodge the rocks";
}

int bal_sky_surfers::total_frames() const {
    return 600; // 600 frames at 60fps = 10 seconds
}

mj::game_result bal_sky_surfers::play([[maybe_unused]] const mj::game_data& data)
{

    mj::game_result result(victory(), false);
    return result;
}

void bal_sky_surfers::fade_in([[maybe_unused]] const mj::game_data& data)
{
}

void bal_sky_surfers::fade_out([[maybe_unused]] const mj::game_data& data)
{
}

}