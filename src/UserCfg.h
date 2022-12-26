/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-12-14 16:03:35
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-26 13:43:59
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
enum UC_ENUM  {
    UC_AiVoice ,
    UC_AiVoiceVolume,
    UC_AiSort,
    UC_NetState,
    UC_KidLock,
    UC_AntiWrinkle,
    UC_Mute,
    UC_OnlineWash,
    UC_InformVolume,
    UC_TouchVolume,
    UC_ScreenBrightness,
    UC_AutoSyncTime,
    UC_DateShow,
    UC_BreathLight
};
 

class UserCfg
{

public:
    UserCfg()
    {
        m_res_usercfg = (e_getuserconfigres_event_t *)malloc(sizeof(e_getuserconfigres_event_t));
    }
    ~UserCfg() {}


//! 这里有个问题，就是需不需要加锁来进行同步？同步了便模拟不了真实机器造成的不同步现象
//处理用户配置一类的请求
    void  DealUserCfgReq(int cfg_type,int ucfg1,int ucfg2,char* ucfg_str)
    {
        //由于大多数的实现比较简单只是单纯的改值，所以这里就不另起方法了
        switch (cfg_type)
        {
        case UC_ENUM::UC_AiSort:
            this->ai_sort= ucfg1;
            break;
              case UC_ENUM::UC_NetState:
           this->net_state=ucfg1;
            break;
              case UC_ENUM::UC_KidLock:
              this->kid_lock =ucfg1;
            break;
              case UC_ENUM::UC_Mute:
            this->mute = ucfg1;
            break;
              case UC_ENUM::UC_OnlineWash:
            this->online_wash = ucfg1;
            break;
        default:
        cout<<" unimpl cmd user type "<<cfg_type<<endl;
            break;
        }  
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
