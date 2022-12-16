#ifndef __PROCESS_H__
#define __PROCESS_H__

/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-22 14:18:57
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-15 16:46:28
 * @FilePath: \VirtualMachineCpp\src\Process.h
 * @Description: 基本的程序
 * 如果最外层没有提供相应的配置文件，则使用最简单的默认配置;
 */
#include "Headers.h"


#include <iostream>
using namespace std;

// json 映射很好用，但是似乎长度有限制，这里需要把整个变量区域分为两个大小才能使用映射功能
 
class Process_CFG_1
{
public:
    Process_CFG_1(/* args */){}
    ~Process_CFG_1(){}
    int cur_remain_time;
    int default_tte;
    int like_value;
    int reserve_cur;
    int reserve_max;
    int reserve_min;
    int cur_remain_anti_wrinkle_time;
    int dry_time_min;
    int dry_time_max;
    int dry_time_cur;
    int speed_ctrl;
    int speed_vis;
    int speed_cur;
    int speed_max;
    int speed_min;
    int wash_temp_ctrl;
    int wash_temp_vis;
    int wash_temp_cur;
    int wash_temp_max;
    int wash_temp_min;
    int rinse_ctrl;
    int rinse_vis;
    int rinse_cur;
    int rinse_max;
    int rinse_min;
    int wash_time_ctrl;
    int wash_time_vis;
    int wash_time_cur;
    int wash_time_max;
    int wash_time_min;
    int super_air_cur;
    int super_air_standard_vc;
    int super_air_steri_vc;
    int super_air_desmell_vc;
    int super_air_dewrinkle_vc;
    int super_air_fluffy_vc;
    int super_air_dehumid_vc;
    int super_air_plasma_vc;
    int sanitize_ctrl;
    int sanitize_vis;
    int sanitize_cur;
    int anion_ctrl;
    int anion_vis;
    int anion_cur;
    int dry_level_ctrl;
    int dry_level_vis;
    int dry_level_cur;
    int dry_level_max;
    int dry_level_min;
    int dry_mode_standard_vis;
    int dry_mode_quick_vis;
    int dry_mode_eco_vis;
    int dry_mode_vis;
    int dry_mode_cur;
    int anti_wrinkle_ctrl;
    int anti_wrinkle_vis;
    int anti_wrinkle_cur;
    int anti_wrinkle_max;
    int anti_wrinkle_min;
};

class Process_CFG_2
{
public:
    Process_CFG_2(/* args */){}
    ~Process_CFG_2(){}
    int dry_time_ctrl;
    int dry_time_vis;
    int dry_temp_ctrl;
    int dry_temp_vis;
    int dry_temp_cur;
    int dry_temp_min;
    int dry_temp_max;
    int reserve_ctrl;
    int reserve_vis;
    int strategy;
    int drum_id;
    int uv_cur;
    int uv_vis;
    int uv_ctrl;
    int plasma_vis;
    int plasma_cur;
    int plasma_ctrl;
    int coupling_wd_vis;
    int coupling_wd_cur;
    int coupling_wd_ctrl;
    int stain_vis;
    int stain_cur;
    int stain_ctrl;
    int high_water_level_cur;
    int high_water_level_vc;
    int super_clean_wash_cur;
    int super_clean_wash_vc;
    int soak_wash_cur;
    int soak_wash_vc;
    int night_wash_cur;
    int night_wash_vc;
    int eco_wash_cur;
    int eco_wash_vc;
    int anti_allergy_cur;
    int anti_allergy_vc;
    int super_air_deacarid_vc;
    int super_air_fast_vc;
    int super_air_dealde_vc;
    int Detergent_vis;
    int Detergent_cur;
    int Detergent_ctrl;
    int Detergent_vol;
    int Softener_vis;
    int Softener_cur;
    int Softener_ctrl;
    int Softener_vol;
    int super_air_plasma_cur;
};

class Process
{

public:
    Process(/* args */) {}
    ~Process() {}

    int GetDefaultTTE();
    

    void SetCFG_1(const Process_CFG_1& p_cfg_1){
        cout<<"SetCFG_1 "<<p_cfg_1.anion_ctrl<<endl;
        pcfg_1 = p_cfg_1;
    }
    void SetCFG_2(const Process_CFG_2& p_cfg_2){
        cout<<"SetCFG_2  " <<pcfg_2.Softener_ctrl<<endl;
        pcfg_2 = p_cfg_2;
    }

//处理和自己相关的消息， 其实就是填写结构体内容
   bool  Deal_UIGET_CFG();
     

private:
    Process_CFG_1 pcfg_1;
    Process_CFG_2 pcfg_2;
};

#endif // __PROCESS_H__