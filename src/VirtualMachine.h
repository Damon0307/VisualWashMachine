#ifndef __VIRTUALMACHINE_H__
#define __VIRTUALMACHINE_H__

/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:12:42
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-26 16:20:13
 * @FilePath: \VirtualMachineCpp\src\VirtualMachine.h
 * @Description:
 */
#include <vector>
#include <string>
 
#include "Drum.h"
#include "UserCfg.h"
#include "GeneralState.h"
#include "TTE.h"
#include "UI_Protocol_Events.h"

 
 enum ProcessCMD {
    Selected=1, //! 程序选择 //起始值为  1
    QuickStart, // 快速启动
    Coltrol, // 普通 启动/暂停
    GoWaitMode, // 程序停止
    Reserve, // 预约
    Temperature, //烘干温度
    DryTime, // 烘干时间
    AntiWrink, // 防皱
    DryMode, // 烘干模式待商榷
    DryLevel, // 干燥度
    Anion, // 负离子
    Sanitize, // 除菌螨
    SuperAirMode, // 超级空气洗优化模式
    SwitchProcess, // 在已经运行流程状态下切换到新的流程并进入配置界面
    WashTime,//洗涤时间
    WashTemp,//洗涤温度
    Rinse,//漂洗次数
    Speed,//转速
    Stain,//特渍
    UV,//紫外
    Plasma,//光等离子
    CouplingWD,//洗烘联动
    HighWaterLevel, //附加功能 高水位
    SuperCleanWash, //附加功能 超净洗
    SoakWash,       //附加功能 浸泡洗
    NightWash,      //附加功能 夜间洗
    ECOWash,        //附加功能 节能洗
    AntiAllergy,    //附加功能 防过敏
    Detergent,//洗涤剂  
    Softener,//柔顺剂   
};


class VirtualMachine
{

public:
    VirtualMachine(const std::string& json_path);
    void InitFromJson(const std::string& json_path);
    ~VirtualMachine();
   
    e_getmachinestateres_event_t*  GetMachineStateRes();
    e_getuserconfigres_event_t*    GetUserCfgRes();
    e_getgeneralstateres_event_t*  GetGeneralStateRes();
    e_gettimetoendres_event_t*     GetTimeToEndRes();
    e_getprocessconfigres_event_t* GetProcessCfgRes();
 
 //处理 E_SetProcessConfigReq 请求
    void DealProcessCmdReq(int drum_id,int strategy,int processid,int cfg_type,int cfgv1,int cfgv2,char* cfg_str);


private:
    
    int ui_cur_drum_id;  //标记着当前UI 正在轮训的筒ID
    int ui_cur_strategy;
    int ui_cur_process_id;
    //!以上三个信息 通过 用户下发程序选择获得并更新

    std::vector<Drum*> m_drums;
    unique_ptr<UserCfg> m_usercfg;
    unique_ptr<GeneralState> m_general_state;
    unique_ptr<TTE> m_tte;
    //通过 筒号，策略号，材质号 获得对应程序
    Process* GetProcessBy_DS_ID(int drum_id,int strategy_id,int process_id);
    //通过筒号获取ID
    Drum*  GetDrumBy_ID(int pdrum_id);
 
    e_getprocessconfigres_event_t* m_res_process_cfg;
    e_getmachinestateres_event_t*  m_res_machine_state;
    e_getuserconfigres_event_t*    m_res_user_cfg;
    e_getgeneralstateres_event_t*  m_res_general_state;
    e_gettimetoendres_event_t*     m_res_tte;

};

#endif // __VIRTUALMACHINE_H__
