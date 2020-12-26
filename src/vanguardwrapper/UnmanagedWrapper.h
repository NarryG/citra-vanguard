#pragma once
#include <string>
#include <mutex>
#include "common/common_types.h"



struct VanguardSettingsUnmanaged {

public:
    bool is_new_3ds;

    int region_value;
    u32 init_clock;
    u64 init_time;

    bool shaders_accurate_mul;

    bool upright_screen;

    bool enable_dsp_lle;
    bool enable_dsp_lle_multithread;

    void GetSettingsFromCitra();

    //  int birthmonth;
    //  int birthday;
    //  int language_index;
    //  u8 country;
    //  u16 play_coin;
};
typedef void (*FnPtr_VanguardMethod)();
class UnmanagedWrapper
{
public:
    static void VANGUARD_EXIT();
    static void VANGUARD_LOADSTATE(const std::string &file);
    static std::string VANGUARD_SAVESTATE(const std::string& file);
    static void VANGUARD_SAVESTATE_DONE();
    static void VANGUARD_LOADSTATE_DONE();
    static void VANGUARD_STOPGAME();
    static void VANGUARD_LOADGAME(const std::string& file);
    static std::string VANGUARD_GETGAMENAME();
    static void PADDR_POKEBYTE(long long addr, unsigned char val, long offset);
    static unsigned char PADDR_PEEKBYTE(long long addr, long offset);
    static std::string VANGUARD_SAVECONFIG();
    static void VANGUARD_LOADCONFIG(std::string cfg);
    static void VANGUARD_CORESTEP();
    static void LOAD_STATE_DONE();
    static bool IS_N3DS();
    static void VANGUARD_PAUSEEMULATION();
    static void VANGUARD_RESUMEEMULATION();
    static void GetSettingsFromCitra();
    static void SetSettingsFromUnmanagedWrapper();

    static VanguardSettingsUnmanaged nSettings;

    static bool savestate_done; //REPLACE THIS
};
