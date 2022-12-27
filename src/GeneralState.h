#ifndef __GENERALSTATE_H__
#define __GENERALSTATE_H__

/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-12-15 10:11:14
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-27 10:53:51
 * @FilePath: \VirtualMachine\src\GeneralState.h
 * @Description: 机器通用状态，天气信息
 * 使用JSON 映射关系进行初始化
 */

#include <iostream>
#include <string>

#include "nlohmann/json.hpp"
#include "UI_Protocol_Events.h"


class GeneralState
{
private:
    /* data */
public:
    GeneralState(/* args */){
    m_res_general_state =(e_getgeneralstateres_event_t*)malloc(sizeof(e_getgeneralstateres_event_t)+cur_system_info.size());
    memset(m_res_general_state, 0, sizeof(*m_res_general_state));
    }
    ~GeneralState(){
      if(m_res_general_state!=NULL)
      {
     free(m_res_general_state);
      m_res_general_state=NULL;
      }
   
    }

    int cur_rtc;
    int cur_temperature;
    int cur_screen_backlight_mode;
    int cur_weather;
    int cur_greeting;
    string cur_system_info;
 
    e_getgeneralstateres_event_t *GetGeneralStateRes()
    {
    
   
    m_res_general_state->cur_greeting = cur_greeting;
    m_res_general_state->cur_rtc=cur_rtc;
    m_res_general_state->cur_screen_backlight_mode =cur_screen_backlight_mode;
    m_res_general_state->cur_temperature =cur_temperature;
    m_res_general_state->cur_weather =cur_weather;
    memcpy(m_res_general_state->cur_system_info,cur_system_info.c_str(),cur_system_info.size());
    return m_res_general_state;
        
    }
private:
  e_getgeneralstateres_event_t * m_res_general_state;

};
 
 #endif // __GENERALSTATE_H__