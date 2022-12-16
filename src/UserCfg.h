/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-12-14 16:03:35
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-15 10:07:11
 * @FilePath: \VirtualMachine\src\UserCfg.h
 * @Description: 处理用户配置
 */
#include <iostream>
#include <string>

#include <stdlib.h>

#include "Util.h"


extern "C"
{
    #include "UI_Protocol_Events.h"
}

#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

// 同样使用 从JSON 映射方式初始化该类
 
class UserCfg
{

public:
    UserCfg()
    {
        m_res_usercfg = (e_getuserconfigres_event_t *)malloc(sizeof(e_getuserconfigres_event_t));
    }
    ~UserCfg() {
        
    }

    e_getuserconfigres_event_t *GetUserCfgRes()
    {
        memset(m_res_usercfg, 0, sizeof(e_getuserconfigres_event_t));

        m_res_usercfg->ai_sort = this->ai_sort;
        m_res_usercfg->ai_voice = this->ai_voice;
        m_res_usercfg->online_time = this->online_time;
        m_res_usercfg->ai_sort = this->ai_sort;
        m_res_usercfg->net_state = this->net_state;
        m_res_usercfg->kid_lock = this->kid_lock;
        m_res_usercfg->anti_wrinkle = this->anti_wrinkle;
        m_res_usercfg->mute = this->mute;
        m_res_usercfg->online_wash = this->online_wash;
        m_res_usercfg->user_login_state = this->user_login_state;
        m_res_usercfg->inform_volume = this->inform_volume;
        m_res_usercfg->touch_volume = this->touch_volume;
        m_res_usercfg->screen_brightness = this->screen_brightness;
        m_res_usercfg->auto_sync_time = this->auto_sync_time;

        return m_res_usercfg;
    }

    int online_time;
    int ai_voice;
    int ai_voice_volume;
    int ai_sort;
    int net_state;
    int kid_lock;
    int anti_wrinkle;
    int mute;
    int online_wash;
    int user_login_state;
    int inform_volume;
    int touch_volume;
    int screen_brightness;
    int auto_sync_time;

private:
    e_getuserconfigres_event_t *m_res_usercfg;
};
