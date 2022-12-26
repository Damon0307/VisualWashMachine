/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-22 14:19:39
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-26 16:02:56
 * @FilePath: \VirtualMachineCpp\src\Process.cpp
 * @Description:
 */
#include "Process.h"
int Process::GetDefaultTTE()
{
     return pcfg_1.default_tte;
}

e_getprocessconfigres_event_t *Process::GetProcessCfgRes()
{
     m_pcfg_res->anion_ctrl = this->pcfg_1.anion_ctrl;
     m_pcfg_res->anion_cur = this->pcfg_1.anion_cur;
     m_pcfg_res->anion_vis = this->pcfg_1.anion_vis;
     m_pcfg_res->anti_allergy_cur = this->pcfg_2.anti_allergy_cur;
     m_pcfg_res->anti_allergy_vc = this->pcfg_2.anti_allergy_vc;
     m_pcfg_res->anti_wrinkle_ctrl = this->pcfg_1.anti_wrinkle_ctrl;

     m_pcfg_res->anti_wrinkle_cur = this->pcfg_1.anti_wrinkle_cur;
     m_pcfg_res->anti_wrinkle_max = this->pcfg_1.anti_wrinkle_max;
     m_pcfg_res->anti_wrinkle_min = this->pcfg_1.anti_wrinkle_min;
     m_pcfg_res->anti_wrinkle_vis = this->pcfg_1.anti_wrinkle_vis;

     m_pcfg_res->coupling_wd_ctrl = this->pcfg_2.coupling_wd_ctrl;
     m_pcfg_res->coupling_wd_cur = this->pcfg_2.coupling_wd_cur;
     m_pcfg_res->coupling_wd_vis = this->pcfg_2.coupling_wd_vis;

     m_pcfg_res->cur_remain_anti_wrinkle_time = this->pcfg_1.cur_remain_anti_wrinkle_time;
     m_pcfg_res->cur_remain_time = this->pcfg_1.cur_remain_time;

     m_pcfg_res->dry_mode_cur = this->pcfg_1.dry_mode_cur;
     m_pcfg_res->dry_mode_vis = this->pcfg_1.dry_mode_vis;
     m_pcfg_res->dry_mode_eco_vis = this->pcfg_1.dry_mode_eco_vis;
     m_pcfg_res->dry_mode_quick_vis = this->pcfg_1.dry_mode_quick_vis;
     m_pcfg_res->dry_mode_standard_vis = this->pcfg_1.dry_mode_standard_vis;

     m_pcfg_res->dry_level_ctrl = this->pcfg_1.dry_level_ctrl;
     m_pcfg_res->dry_level_vis = this->pcfg_1.dry_level_vis;
     m_pcfg_res->dry_level_min = this->pcfg_1.dry_level_min;
     m_pcfg_res->dry_level_max = this->pcfg_1.dry_level_max;
     m_pcfg_res->dry_level_cur = this->pcfg_1.dry_level_cur;

     // m_pcfg_res->drum_id = this->pcfg_1.anion_cur;

     m_pcfg_res->dry_temp_ctrl = this->pcfg_2.dry_temp_ctrl;
     m_pcfg_res->dry_temp_vis = this->pcfg_2.dry_temp_vis;
     m_pcfg_res->dry_temp_min = this->pcfg_2.dry_temp_min;
     m_pcfg_res->dry_temp_max = this->pcfg_2.dry_temp_max;
     m_pcfg_res->dry_temp_cur = this->pcfg_2.dry_temp_cur;

     m_pcfg_res->dry_time_ctrl = this->pcfg_2.dry_time_ctrl;
     m_pcfg_res->dry_time_vis = this->pcfg_2.dry_time_vis;
     m_pcfg_res->dry_time_cur = this->pcfg_1.dry_time_cur;
     m_pcfg_res->dry_time_min = this->pcfg_1.dry_time_min;
     m_pcfg_res->dry_time_max = this->pcfg_1.dry_time_max;

     m_pcfg_res->Detergent_ctrl = this->pcfg_2.Detergent_ctrl;
     m_pcfg_res->Detergent_cur = this->pcfg_2.Detergent_cur;
     m_pcfg_res->Detergent_vis = this->pcfg_2.Detergent_vis;
     m_pcfg_res->Detergent_vol = this->pcfg_2.Detergent_vol;

     m_pcfg_res->eco_wash_cur = this->pcfg_2.eco_wash_cur;
     m_pcfg_res->eco_wash_vc = this->pcfg_2.eco_wash_vc;

     m_pcfg_res->high_water_level_cur = this->pcfg_2.high_water_level_cur;
     m_pcfg_res->high_water_level_vc = this->pcfg_2.high_water_level_vc;

     m_pcfg_res->night_wash_cur = this->pcfg_2.night_wash_cur;
     m_pcfg_res->night_wash_vc = this->pcfg_2.night_wash_vc;

     m_pcfg_res->plasma_ctrl = this->pcfg_2.plasma_ctrl;
     m_pcfg_res->plasma_cur = this->pcfg_2.plasma_cur;
     m_pcfg_res->plasma_vis = this->pcfg_2.plasma_vis;

     m_pcfg_res->reserve_ctrl = this->pcfg_2.reserve_ctrl;
     m_pcfg_res->reserve_vis = this->pcfg_2.reserve_vis;
     m_pcfg_res->reserve_min = this->pcfg_1.reserve_min;
     m_pcfg_res->reserve_max = this->pcfg_1.reserve_max;
     m_pcfg_res->reserve_cur = this->pcfg_1.reserve_cur;

     m_pcfg_res->rinse_ctrl = this->pcfg_1.rinse_ctrl;
     m_pcfg_res->rinse_vis = this->pcfg_1.rinse_vis;
     m_pcfg_res->rinse_min = this->pcfg_1.rinse_min;
     m_pcfg_res->rinse_max = this->pcfg_1.rinse_max;
     m_pcfg_res->rinse_cur = this->pcfg_1.rinse_cur;

     m_pcfg_res->sanitize_ctrl = this->pcfg_1.sanitize_ctrl;
     m_pcfg_res->sanitize_cur = this->pcfg_1.sanitize_cur;
     m_pcfg_res->sanitize_vis = this->pcfg_1.sanitize_vis;

     m_pcfg_res->soak_wash_cur = this->pcfg_2.soak_wash_cur;
     m_pcfg_res->soak_wash_vc = this->pcfg_2.soak_wash_vc;

     m_pcfg_res->speed_ctrl = this->pcfg_1.speed_ctrl;
     m_pcfg_res->speed_vis = this->pcfg_1.speed_vis;
     m_pcfg_res->speed_cur = this->pcfg_1.speed_cur;
     m_pcfg_res->speed_min = this->pcfg_1.speed_min;
     m_pcfg_res->speed_max = this->pcfg_1.speed_max;

     m_pcfg_res->stain_ctrl = this->pcfg_2.stain_ctrl;
     m_pcfg_res->stain_cur = this->pcfg_2.stain_cur;
     m_pcfg_res->stain_vis = this->pcfg_2.stain_vis;

     m_pcfg_res->super_air_cur = this->pcfg_1.super_air_cur;
     m_pcfg_res->super_air_deacarid_vc = this->pcfg_2.super_air_deacarid_vc;
     m_pcfg_res->super_air_dealde_vc = this->pcfg_2.super_air_dealde_vc;
     m_pcfg_res->super_air_fast_vc = this->pcfg_2.super_air_fast_vc;
     m_pcfg_res->super_air_plasma_cur = this->pcfg_2.super_air_plasma_cur;

     m_pcfg_res->super_air_plasma_vc = this->pcfg_1.super_air_plasma_vc;
     m_pcfg_res->super_air_standard_vc = this->pcfg_1.super_air_standard_vc;
     m_pcfg_res->super_air_steri_vc = this->pcfg_1.super_air_steri_vc;
     m_pcfg_res->super_air_fluffy_vc = this->pcfg_1.super_air_fluffy_vc;
     m_pcfg_res->super_air_desmell_vc = this->pcfg_1.super_air_desmell_vc;
     m_pcfg_res->super_air_dehumid_vc = this->pcfg_1.super_air_dehumid_vc;
     m_pcfg_res->super_air_dewrinkle_vc = this->pcfg_1.super_air_dewrinkle_vc;

     m_pcfg_res->Softener_vis = this->pcfg_2.Softener_vis;
     m_pcfg_res->Softener_cur = this->pcfg_2.Softener_cur;
     m_pcfg_res->Softener_ctrl = this->pcfg_2.Softener_ctrl;
     m_pcfg_res->Softener_vol = this->pcfg_2.Softener_vol;

     m_pcfg_res->uv_ctrl = this->pcfg_2.uv_ctrl;
     m_pcfg_res->uv_vis = this->pcfg_2.uv_vis;
     m_pcfg_res->uv_cur = this->pcfg_2.uv_cur;

     m_pcfg_res->wash_temp_ctrl = this->pcfg_1.wash_temp_ctrl;
     m_pcfg_res->wash_temp_vis = this->pcfg_1.wash_temp_vis;
     m_pcfg_res->wash_temp_max = this->pcfg_1.wash_temp_max;
     m_pcfg_res->wash_temp_min = this->pcfg_1.wash_temp_min;
     m_pcfg_res->wash_temp_cur = this->pcfg_1.wash_temp_cur;

     m_pcfg_res->wash_temp_ctrl = this->pcfg_1.wash_temp_ctrl;
     m_pcfg_res->wash_temp_vis = this->pcfg_1.wash_temp_vis;
     m_pcfg_res->wash_temp_min = this->pcfg_1.wash_temp_min;
     m_pcfg_res->wash_temp_max = this->pcfg_1.wash_temp_max;
     m_pcfg_res->wash_temp_cur = this->pcfg_1.wash_temp_cur;

     //注意部分字段是没有填写的eg ,drumid  strategy id ,process id , 这些需要更上层的模块去填充
     return m_pcfg_res;
}
