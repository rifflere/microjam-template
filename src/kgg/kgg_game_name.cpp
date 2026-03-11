#include "bn_keypad.h"
#include "kgg/kgg_game_name.h"
#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = {"Gurpinder Gill"};
    constexpr bn::string_view graphics_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
    constexpr bn::string_view sfx_credits[] = {""};
}

namespace kgg
{

    kgg_game_name::kgg_game_name([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data &data)
        : mj::game("kgg")
    {
        _rock_speed = _recommended_rock_speed(recommended_difficulty_level(completed_games, data));

    }

    bn::string<16> kgg_game_name::title() const
    {
        return "move left right";
    }

    // returns rock fall speed based on the rock difficulty
    bn::fixed kgg_game_name::_recommended_rock_speed(mj::difficulty_level difficulty) {
    if(difficulty == mj::difficulty_level::EASY) {
        return 1.0;         // easy speed 
    } else if(difficulty == mj::difficulty_level::NORMAL) {
        return 2.5;       // medium speed
    }
    return 4.0;           // hard speed
}


    int kgg_game_name::total_frames() const
    {
        return 180;
    }

    mj::game_result kgg_game_name::play([[maybe_unused]] const mj::game_data &data)
    {

        _player.update();

        if (bn::keypad::a_pressed())
        {
            _victory = true;
        }

        if (bn::keypad::b_pressed())
        {
            _victory = false;
        }

        return mj::game_result();
    }

    bool kgg_game_name::victory() const
    {
        // return false;
        return _victory;
    }

    void kgg_game_name::fade_in([[maybe_unused]] const mj::game_data &data)
    {
    }

    void kgg_game_name::fade_out([[maybe_unused]] const mj::game_data &data)
    {
    }

}
MJ_GAME_LIST_ADD(kgg::kgg_game_name);

MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits);
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits);
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits);
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits);
