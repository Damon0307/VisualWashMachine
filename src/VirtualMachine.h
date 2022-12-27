#ifndef __VIRTUALMACHINE_H__
#define __VIRTUALMACHINE_H__

/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:12:42
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-27 15:08:16
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

    e_getprocessconfigres_event_t* m_res_process_cfg;
    e_getmachinestateres_event_t*  m_res_machine_state;
    e_getuserconfigres_event_t*    m_res_user_cfg;
    e_getgeneralstateres_event_t*  m_res_general_state;
    e_gettimetoendres_event_t*     m_res_tte;

    //通过 筒号，策略号，材质号 获得对应程序
    Process* GetProcessBy_DS_ID(int drum_id,int strategy_id,int process_id);
    //通过筒号获取ID
    Drum*  GetDrumBy_ID(int pdrum_id);
 
  

};

#endif // __VIRTUALMACHINE_H__
