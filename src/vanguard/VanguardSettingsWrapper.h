#pragma once
#include "common/common_types.h"
#include <utility>
#include <string>

public ref class VanguardSettingsWrapper
{
    public:
    bool is_new_3ds;

    int region_value;
    int init_clock;
    u64 init_time;

    bool shaders_accurate_mul;

    bool upright_screen;

    bool enable_dsp_lle;
    bool enable_dsp_lle_multithread;

    static VanguardSettingsWrapper ^ GetVanguardSettingsFromCitra();
    static void SetSettingsFromWrapper(VanguardSettingsWrapper ^ vSettings);
   // int birthmonth;
   // int birthday;
   // int language_index;
   // u8 country;
   // u16 play_coin;
    };
