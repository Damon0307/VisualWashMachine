/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:13:24
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-16 16:56:36
 * @FilePath: \VirtualMachineCpp\src\VirtualMachine.cpp
 * @Description:
 */

#include <iostream>
#include <string>

#include "VirtualMachine.h"
#include "nlohmann/json.hpp"
#include "Util.h"

using namespace std;
using json = nlohmann::json;
// 将类中部分成员变量与 json做好绑定

extern string JSON_ROOT_PATH;

// 映射关系
namespace ns
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Drum, drum_id, run_mode, run_strategy, run_process_id, run_stage, run_progress, door, err_code);
}
namespace ns
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Process_CFG_1, cur_remain_time, default_tte, like_value, reserve_cur, reserve_max, reserve_min, cur_remain_anti_wrinkle_time, dry_time_min, dry_time_max, dry_time_cur, speed_ctrl, speed_vis, speed_cur, speed_max, speed_min, wash_temp_ctrl, wash_temp_vis, wash_temp_cur, wash_temp_max, wash_temp_min, rinse_ctrl, rinse_vis, rinse_cur, rinse_max, rinse_min);
}

namespace ns
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Process_CFG_2, dry_time_ctrl, dry_time_vis, dry_temp_ctrl, dry_temp_vis, dry_temp_cur, dry_temp_min, dry_temp_max, reserve_ctrl, reserve_vis, strategy, drum_id, uv_cur, uv_vis, uv_ctrl, plasma_vis, plasma_cur, plasma_ctrl, coupling_wd_vis, coupling_wd_cur, coupling_wd_ctrl, stain_vis, stain_cur, stain_ctrl, high_water_level_cur, high_water_level_vc, super_clean_wash_cur, super_clean_wash_vc, soak_wash_cur, soak_wash_vc, night_wash_cur, night_wash_vc, eco_wash_cur, eco_wash_vc, anti_allergy_cur, anti_allergy_vc, super_air_deacarid_vc, super_air_fast_vc, super_air_dealde_vc, Detergent_vis, Detergent_cur, Detergent_ctrl, Detergent_vol, Softener_vis, Softener_cur, Softener_ctrl, Softener_vol, super_air_plasma_cur);
}

namespace ns
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(UserCfg, online_time, ai_voice, ai_voice_volume, ai_sort, net_state, kid_lock, anti_wrinkle, mute, online_wash, user_login_state, inform_volume, touch_volume, screen_brightness, auto_sync_time);
}

namespace ns
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(TTE, Drum2_Wash_1, Drum2_Wash_2, Drum2_Wash_4, Drum2_Wash_5, Drum2_Wash_6, Drum2_Wash_7, Drum2_Wash_8, Drum2_Wash_10, Drum2_Wash_11, Drum2_Wash_12, Drum1_Dry_1, Drum1_Dry_2, Drum1_Dry_7, Drum1_Dry_8, Drum1_Dry_12, Drum1_Air_1, Drum1_Air_2,
                                       Drum1_Air_3, Drum1_Air_7, Drum1_Air_8, Drum1_Air_9, Drum1_Air_12, Drum1_Air_13, Drum2_Wash_14, Drum1_Air_15,
                                       Drum2_Wash_16, Drum1_Air_16, Drum1_Dry_16, Drum1_Air_17, Drum2_Wash_18, Drum2_Wash_19, Drum1_Dry_19, Drum2_Wash_20,
                                       Drum1_Air_21, Drum2_Wash_22, Drum2_Wash_24, Drum1_Dry_24, Drum2_Wash_25, Drum1_Dry_26, Drum1_Air_26, Drum2_Wash_26, Drum1_Dry_27, Drum1_Air_28, Drum2_Wash_29, Drum1_Dry_29, Drum2_Wash_30, Drum1_Air_31, Drum1_Dry_32, Drum2_Wash_32, Drum1_Dry_33,
                                       Drum1_Dry_34, Drum2_Wash_34, Drum1_Air_35, Drum1_Dry_36, Drum2_Wash_36, Drum1_Dry_37, Drum1_Wellness_38,
                                       Drum1_Wellness_39, Drum1_Wellness_40, Drum1_Wellness_41, Drum1_Dry_42);
}

namespace ns
{
    NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(GeneralState, cur_rtc, cur_temperature, cur_screen_backlight_mode, cur_weather, cur_greeting, cur_system_info);
}

//! construct
VirtualMachine::VirtualMachine(const std::string& json_path)
{


    InitFromJson(json_path);

    m_res_tte = (e_gettimetoendres_event_t *)malloc(sizeof(e_gettimetoendres_event_t));
    m_res_machine_state = (e_getmachinestateres_event_t *)malloc(sizeof(e_getmachinestateres_event_t));

    m_usercfg = std::move(unique_ptr<UserCfg>(new UserCfg));
    ns::from_json(Util::GetIns()->GetJsonFromFile(JSON_ROOT_PATH + "UserCfg.json"),*(m_usercfg.get()));

    m_general_state = std::move(unique_ptr<GeneralState>(new GeneralState));
    ns::from_json(Util::GetIns()->GetJsonFromFile(JSON_ROOT_PATH + "GeneralState.json"),*(m_general_state.get()));

    m_tte = std::move(unique_ptr<TTE>(new TTE));
    ns::from_json(Util::GetIns()->GetJsonFromFile(JSON_ROOT_PATH + "TTE.json"), *(m_tte.get()));
}
VirtualMachine::~VirtualMachine()
{
    cout<<"VirtualMachine::~VirtualMachine()   byebye"<<endl;
}

Process *VirtualMachine::GetProcessBy_DS_ID(int drum_id, int strategy_id, int process_id)
{

    for (auto &drum_item : m_drums)
    {
        // cout<<" drum_item->GetDrumID() "<<drum_item->GetDrumID()<<endl;
        if (drum_id == drum_item->GetDrumID())
        {
            auto strategy_list = drum_item->GetStrategyList();
            for (auto &strategy_item : strategy_list)
            {
                // cout<<"strategy_item->GetStrategyID() "<<strategy_item->GetStrategyID()<<endl;
                strategy_item->ShowCurStrategyProcessListID();
                //  cout<<"Going to set process_id "<<process_id<<endl;
                if (strategy_item->GetStrategyID() == strategy_id)
                {
                    return strategy_item->GetProcess(process_id);
                }
            }
        }
    }

    cout << "cant  find process_id " << process_id << " in  strategy id " << strategy_id << " and drum id " << drum_id << endl;

    return nullptr;
}

/**
 * @brief 从JSON文件读取配置，初始化 虚拟机器的信息
 *执行完了以后应该会 建立完整的 机器框架， 筒， 策略， 每个策略的流程， 流程的配置
 * @param json_path
 */
void VirtualMachine::InitFromJson(const std::string &json_path)
{
    json json_machine = Util::GetIns()->GetJsonFromFile(json_path);
    // cout << "json_machine -> " << json_machine << endl;

    for (auto i : json_machine.items())
    {
        // cout<<" i.key() "<<i.key()<<" i.value() "<<i.value()<<endl;

        if (i.key() == "drums")
        {
            json json_drum_arr = i.value();

            for (auto &drum_item : json_drum_arr.items())
            {
                // cout << " drum.key() " << drum_item.key() << " drum.value() " << drum_item.value() << endl;
                Drum *pdrum = new Drum();
                ns::from_json(drum_item.value(), *pdrum);

                json json_strategy_arr = drum_item.value().at("strategys");

                for (auto strategy_item : json_strategy_arr.items())
                {
                    string strategy_path = JSON_ROOT_PATH;
                    strategy_path += strategy_item.value();

                    Strategy *pstrategy = new Strategy(strategy_path);
                    pdrum->AddStrategy(pstrategy);
                }

                // cout<<"json_strategy_arr "<<json_strategy_arr<<endl;

                this->m_drums.push_back(pdrum);

                cout << "CCCCCCCCCCC-> " << pdrum->GetRunStage() << endl;
            }
        }
    }

    // 根据 ProcessCfg 文件夹中提供的 程序的自定义配置文件,初始化对应筒对应策略对应程序id的配置
    //! 文件夹目录   MachineCfg/ProcessCfg

    string cfg_path = JSON_ROOT_PATH + "ProcessCfg";

    auto res = Util::GetIns()->GetFileNameByFormatUnderDir(cfg_path, "json");

    for (auto &i : res)
    {
        if (i == "default_cfg.json")
        {
            continue;
        }

        string cfg_file_name = i;

        // 得到 Drumid , Strategyid, Processid
        int d_pos = i.find("_");
        int d_id = stoi(i.substr(1, d_pos));

        i.erase(0, d_pos + 1);

        int s_pos = i.find("_");
        int s_id = stoi(i.substr(1, s_pos));

        i.erase(0, s_pos + 1);

        int p_pos = i.find("_");
        int p_id = stoi(i.substr(1, p_pos));
        // 根据提供的程序的配置文件，来进行准确的匹配配置
        for (auto &drum : this->m_drums)
        {
            if (drum->drum_id == d_id)
            {
                // m_strategy_list
                auto strategy_list = drum->GetStrategyList();

                for (auto &strategy_item : strategy_list)
                {
                    if (strategy_item->GetStrategyID() == s_id)
                    {
                        Process *p_cfg = new Process();
                        Process_CFG_1 p_cfg_1;
                        Process_CFG_2 p_cfg_2;

                        json json_process_cfg = Util::GetIns()->GetJsonFromFile(cfg_path + "/" + cfg_file_name);

                        // cout << "----json_process_cfg -> "<<endl << json_process_cfg << endl;

                        ns::from_json(json_process_cfg, p_cfg_1);
                        ns::from_json(json_process_cfg, p_cfg_2);

                        // cout << " cur_remain_time " << p_cfg_1.cur_remain_time << endl;
                        p_cfg->SetCFG_1(p_cfg_1);
                        p_cfg->SetCFG_2(p_cfg_2);
                        cout << " Going to set cfg of "
                             << "drum id " << d_id << " strategy id " << s_id << " process id " << p_id << endl;
                        strategy_item->SetProcessCfgByID(p_id, p_cfg);
                    }
                }
            }
        }
    }
}

// todo 四个常用的信息模块的获取
e_getmachinestateres_event_t *VirtualMachine::GetMachineStateRes()
{
    //! 也考虑过做成类似USER_CFG那样的类直接进行 单一字符串JSON映射，
    //! 好处是 可以快速定义出消息，并方便的进行设置
    //! 坏处是 失去了筒的抽象，没办法与其他模块联动，当一个数据辩护策略既需要改变当前模块有需要改变其他模块时候就比较麻烦
    //!  比如需要接收启动。暂停，中止的消息

    // 应该在消息结构中存在一些 变量名代表具体含义，比如 drum1_process_id
    // 这个Drum1 就相当于Drum ID是1， 因为需要额外的处理映射关系
    int drum1_id = 1;
    int drum2_id = 2;

    memset(m_res_machine_state, 0, sizeof(*m_res_machine_state));
    m_res_machine_state->drum1_door = GetDrumBy_ID(drum1_id)->GetCurDoor();
    m_res_machine_state->drum1_err_code = GetDrumBy_ID(drum1_id)->GetErrCode();
    m_res_machine_state->drum1_process_id = GetDrumBy_ID(drum1_id)->GetRunMaterialID();
    m_res_machine_state->drum1_progress = GetDrumBy_ID(drum1_id)->GetRunProgress();
    m_res_machine_state->drum1_run_mode = GetDrumBy_ID(drum1_id)->GetRunMode();
    m_res_machine_state->drum1_stage = GetDrumBy_ID(drum1_id)->GetRunStage();
    m_res_machine_state->drum1_strategy = GetDrumBy_ID(drum1_id)->GetRunStrategy();

    m_res_machine_state->drum2_door = GetDrumBy_ID(drum2_id)->GetCurDoor();
    m_res_machine_state->drum2_err_code = GetDrumBy_ID(drum2_id)->GetErrCode();
    m_res_machine_state->drum2_process_id = GetDrumBy_ID(drum2_id)->GetRunMaterialID();
    m_res_machine_state->drum2_progress = GetDrumBy_ID(drum2_id)->GetRunProgress();
    m_res_machine_state->drum2_run_mode = GetDrumBy_ID(drum2_id)->GetRunMode();
    m_res_machine_state->drum2_stage = GetDrumBy_ID(drum2_id)->GetRunStage();
    m_res_machine_state->drum2_strategy = GetDrumBy_ID(drum2_id)->GetRunStrategy();

    // m_res_machine_state.uibackend_err_code

    return m_res_machine_state;
}
e_getuserconfigres_event_t *VirtualMachine::GetUserCfgRes()
{
    return m_usercfg.get()->GetUserCfgRes();
}

e_getgeneralstateres_event_t *VirtualMachine::GetGeneralStateRes()
{
    return m_general_state.get()->GetGeneralStateRes();
}

e_gettimetoendres_event_t *VirtualMachine::GetTimeToEndRes()
{
    //!  由于TTE比较独立，所以采用单独模块进行管理
    return m_tte.get()->GetTimeToEndRes();
#if 0
    const int drum1 = 1;
    const int drum2 = 2;
    const int wash = 1;
    const int dry = 2;
    const int air = 3;
    const int wellness = 4;
    cout<<" m_res_tte size "<<sizeof(*m_res_tte)<<endl;
    memset(m_res_tte, 0, sizeof(*m_res_tte));
    //! m_res_tte->Drum1_Air_12 = GetProcessBy_DS_ID(1,2,12)->GetDefaultTTE();
    m_res_tte->Drum1_Air_12 = GetProcessBy_DS_ID(drum1, air, 12)->GetDefaultTTE();
   // auto pp =  GetProcessBy_DS_ID(drum1, air, 13);
  //  m_res_tte->Drum1_Air_13 = GetProcessBy_DS_ID(drum1, air, 13)->GetDefaultTTE();
  //  m_res_tte->Drum1_Air_15 = GetProcessBy_DS_ID(drum1, air, 15)->GetDefaultTTE();
 // 如果没有这个程序会返回null 进而出错
    m_res_tte->Drum1_Air_16 = GetProcessBy_DS_ID(drum1, air, 16)->GetDefaultTTE();
    m_res_tte->Drum1_Air_17 = GetProcessBy_DS_ID(drum1, air, 17)->GetDefaultTTE();
    m_res_tte->Drum1_Air_1 = GetProcessBy_DS_ID(drum1, air, 1)->GetDefaultTTE();
    m_res_tte->Drum1_Air_21 = GetProcessBy_DS_ID(drum1, air, 21)->GetDefaultTTE();
    m_res_tte->Drum1_Air_26 = GetProcessBy_DS_ID(drum1, air, 26)->GetDefaultTTE();
    m_res_tte->Drum1_Air_28 = GetProcessBy_DS_ID(drum1, air, 28)->GetDefaultTTE();
    m_res_tte->Drum1_Air_2 = GetProcessBy_DS_ID(drum1, air, 2)->GetDefaultTTE();
    m_res_tte->Drum1_Air_31 = GetProcessBy_DS_ID(drum1, air, 31)->GetDefaultTTE();
    m_res_tte->Drum1_Air_35 = GetProcessBy_DS_ID(drum1, air, 35)->GetDefaultTTE();
    m_res_tte->Drum1_Air_3 = GetProcessBy_DS_ID(drum1, air, 3)->GetDefaultTTE();
    m_res_tte->Drum1_Air_7 = GetProcessBy_DS_ID(drum1, air, 7)->GetDefaultTTE();
    m_res_tte->Drum1_Air_8 = GetProcessBy_DS_ID(drum1, air, 8)->GetDefaultTTE();
    m_res_tte->Drum1_Air_9 = GetProcessBy_DS_ID(drum1, air, 9)->GetDefaultTTE();
    //? air 结束

    m_res_tte->Drum1_Dry_12 = GetProcessBy_DS_ID(drum1, dry, 12)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_16 = GetProcessBy_DS_ID(drum1, dry, 16)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_19 = GetProcessBy_DS_ID(drum1, dry, 19)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_1 = GetProcessBy_DS_ID(drum1, dry, 1)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_2 = GetProcessBy_DS_ID(drum1, dry, 2)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_24 = GetProcessBy_DS_ID(drum1, dry, 24)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_26 = GetProcessBy_DS_ID(drum1, dry, 26)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_27 = GetProcessBy_DS_ID(drum1, dry, 27)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_29 = GetProcessBy_DS_ID(drum1, dry, 29)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_32 = GetProcessBy_DS_ID(drum1, dry, 32)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_33 = GetProcessBy_DS_ID(drum1, dry, 33)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_34 = GetProcessBy_DS_ID(drum1, dry, 34)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_36 = GetProcessBy_DS_ID(drum1, dry, 36)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_37 = GetProcessBy_DS_ID(drum1, dry, 37)->GetDefaultTTE();
    m_res_tte->Drum1_Dry_42 = GetProcessBy_DS_ID(drum1, dry, 42)->GetDefaultTTE();
    //? dry 结束

    m_res_tte->Drum1_Wellness_38 = GetProcessBy_DS_ID(drum1, wellness, 38)->GetDefaultTTE();
    m_res_tte->Drum1_Wellness_39 = GetProcessBy_DS_ID(drum1, wellness, 39)->GetDefaultTTE();
    m_res_tte->Drum1_Wellness_40 = GetProcessBy_DS_ID(drum1, wellness, 40)->GetDefaultTTE();
    m_res_tte->Drum1_Wellness_41 = GetProcessBy_DS_ID(drum1, wellness, 41)->GetDefaultTTE();
    //? 保养 结束
    m_res_tte->Drum2_Wash_10 = GetProcessBy_DS_ID(drum2, wash, 10)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_1 = GetProcessBy_DS_ID(drum2, wash, 1)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_11 = GetProcessBy_DS_ID(drum2, wash, 11)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_12 = GetProcessBy_DS_ID(drum2, wash, 12)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_14 = GetProcessBy_DS_ID(drum2, wash, 14)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_16 = GetProcessBy_DS_ID(drum2, wash, 16)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_18 = GetProcessBy_DS_ID(drum2, wash, 18)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_19 = GetProcessBy_DS_ID(drum2, wash, 19)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_2 = GetProcessBy_DS_ID(drum2, wash, 2)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_20 = GetProcessBy_DS_ID(drum2, wash, 20)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_22 = GetProcessBy_DS_ID(drum2, wash, 22)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_24 = GetProcessBy_DS_ID(drum2, wash, 24)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_25 = GetProcessBy_DS_ID(drum2, wash, 25)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_26 = GetProcessBy_DS_ID(drum2, wash, 26)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_29 = GetProcessBy_DS_ID(drum2, wash, 29)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_30 = GetProcessBy_DS_ID(drum2, wash, 30)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_32 = GetProcessBy_DS_ID(drum2, wash, 32)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_34 = GetProcessBy_DS_ID(drum2, wash, 34)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_36 = GetProcessBy_DS_ID(drum2, wash, 36)->GetDefaultTTE();
    m_res_tte->Drum2_Wash_4 = GetProcessBy_DS_ID(drum2, wash, 4)->GetDefaultTTE();
    //? 洗涤结束
    return m_res_tte;
#endif
}

e_getprocessconfigres_event_t* VirtualMachine::GetProcessCfgRes()
{
    
}

Drum *VirtualMachine::GetDrumBy_ID(int pdrum_id)
{
    for (auto &i : m_drums)
    {
        if (i->drum_id == pdrum_id)
        {
            return i;
        }
    }
}
