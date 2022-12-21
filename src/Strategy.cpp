/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-22 10:16:22
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-16 16:02:10
 * @FilePath: \VirtualMachineCpp\src\Strategy.cpp
 * @Description:
 */

#include <fstream>
#include <iostream>
#include "Strategy.h"
#include "Util.h"
#include "nlohmann/json.hpp"

using namespace std;
 
using json = nlohmann::json;
// @brief  通过JSON文件生成包含程序列表的策略

extern string JSON_ROOT_PATH;

namespace ns
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Process_CFG_1, cur_remain_time, default_tte, like_value, reserve_cur, reserve_max, reserve_min, cur_remain_anti_wrinkle_time, dry_time_min, dry_time_max, dry_time_cur, speed_ctrl, speed_vis, speed_cur, speed_max, speed_min, wash_temp_ctrl, wash_temp_vis, wash_temp_cur, wash_temp_max, wash_temp_min, rinse_ctrl, rinse_vis, rinse_cur, rinse_max, rinse_min);
}

namespace ns
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Process_CFG_2, dry_time_ctrl, dry_time_vis, dry_temp_ctrl, dry_temp_vis, dry_temp_cur, dry_temp_min, dry_temp_max, reserve_ctrl, reserve_vis, strategy, drum_id, uv_cur, uv_vis, uv_ctrl, plasma_vis, plasma_cur, plasma_ctrl, coupling_wd_vis, coupling_wd_cur, coupling_wd_ctrl, stain_vis, stain_cur, stain_ctrl, high_water_level_cur, high_water_level_vc, super_clean_wash_cur, super_clean_wash_vc, soak_wash_cur, soak_wash_vc, night_wash_cur, night_wash_vc, eco_wash_cur, eco_wash_vc, anti_allergy_cur, anti_allergy_vc, super_air_deacarid_vc, super_air_fast_vc, super_air_dealde_vc, Detergent_vis, Detergent_cur, Detergent_ctrl, Detergent_vol, Softener_vis, Softener_cur, Softener_ctrl, Softener_vol, super_air_plasma_cur);
}

Strategy::Strategy(const std::string &json_path)
{

  cout << "In Strategy cons -> strategy json_path " << json_path << endl;

  json json_strategy = Util::GetIns()->GetJsonFromFile(json_path);

  this->strategy_id = json_strategy.at("strategy_id");

  json json_processid_list = json_strategy.at("process_id");

  // 默认是 默认配置JSON
  string default_cfg = JSON_ROOT_PATH + "ProcessCfg/default_cfg.json";
  Process *p_cfg = new Process();
  Process_CFG_1 p_cfg_1;
  Process_CFG_2 p_cfg_2;
  json json_process_cfg = Util::GetIns()->GetJsonFromFile(default_cfg);

  //cout<<" fuck it  "<<endl<<json_process_cfg<<endl;

  ns::from_json(json_process_cfg, p_cfg_1);
  ns::from_json(json_process_cfg, p_cfg_2);
  p_cfg->SetCFG_1(p_cfg_1);
  p_cfg->SetCFG_2(p_cfg_2);

  for (auto i : json_processid_list.items())
  {
   // cout<<" i .value "<<i.value()<<endl;
    this->map_process.insert(make_pair(i.value(), p_cfg));
  }
}

// 通过ID 来给容器中已有的程序配置进行赋值
void Strategy::SetProcessCfgByID(int p_id, Process *p_process)
{

  auto iter = this->map_process.find(p_id);
  if (iter != map_process.end())
  {
    iter->second = p_process;
  }

  cout << " map size " << this->map_process.size() << endl;
}

Process *Strategy::GetProcess(int p_id)
{
  for (auto &i : this->map_process)
  {
    if (i.first == p_id)
    {
      return i.second;
    }
  }
  return nullptr;
}

void Strategy::ShowCurStrategyProcessListID()
{
   
        for(auto i: map_process)
        {
            cout<<" pid "<<i.first<<"  pcfg "<<i.second<<endl;
        }
    
}
