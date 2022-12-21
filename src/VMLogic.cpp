/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-12-07 11:15:02
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-16 16:51:29
 * @FilePath: \VirtualMachine\src\VMLogic.cpp
 * @Description: 业务层实现文件，  实现对业务的封装 
 */

#include <iostream>
#include <functional>
#include "VMLogic.h"
 

using namespace std;
 
//从CrankIO 中接收到数据，根据事件名称，取出对应的结构体信息，然后进行处理

void VMLogic::OnRecvDataFromCrankIO(char* ev_name,void* ev_data,char* ev_fmt)
{
 //! too much if else . using unordered_map replace
//    if(strcmp(ev_name,E_GETGENERALSTATERES_EVENT) ==0 )
//    {
//         e_getgeneralstateres_event_t* ev =(e_getgeneralstateres_event_t*)ev_data;
//    }   

    auto iter = m_slots_map.find(ev_name);

    if(iter != m_slots_map.end())
     {
         
         auto slot_func =iter->second;
         slot_func(ev_name,ev_data,ev_fmt);
     }else
     {
          cout<<" slot not found"<<endl;
     }
 
}

//! 链接信号槽函数
void VMLogic::InitSlotMap(const char* event_name,event_slot& event_slot)
{

     string res ="hh";

     auto f1 =std::bind(&VMLogic::DealGetGeneralStateReq,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);

     m_slots_map.insert(make_pair(res, f1));
     //来自用户界面的UI请求
     // m_slots_map.insert(make_pair(E_GETGENERALSTATERES_EVENT ,this->DealGetGeneralStateReq));
     // m_slots_map.insert(make_pair(E_GETMACHINESTATERES_EVENT,this->DealGetMachineStateReq));
     // m_slots_map.insert(make_pair(E_GETPROCESSCONFIGRES_EVENT,this->DealGetProcessCfgReq));
     // m_slots_map.insert(make_pair(E_GETTIMETOENDRES_EVENT,this->DealGetTimeToEndReq));
     //来自数据模块本身后面操作数据的请求
     //todo shutdown warning...
 
#if 0
 'std::unordered_map<std::__cxx11::basic_string<char>, std::function<void(char*, void*, char*)> >::insert(std::pair<const char*, void (VMLogic::*)(char*, void*, char*)>)'|


no match for call to '(std::function<int(const char*, const char*, int, const char*)>) (e_getprocessconfigres_event_t*&, const char [40], long long unsigned int)'|
#endif



}
 
//todo处理 获取流程配置请求
void VMLogic::DealGetProcessCfgReq(char* ev_name,void* ev_data,char* ev_fmt)
{
     //shit about msg size.
      auto res =m_vm.get()->GetProcessCfgRes();
      m_send_func((char*)res,E_GETPROCESSCONFIGREQ_FMT,sizeof(*res),nullptr);
     
}

//todo处理 获取机器状态请求
void VMLogic::DealGetMachineStateReq(char* ev_name,void* ev_data,char* ev_fmt)
{
     
}

//todo处理 获取通用配置请求
void VMLogic::DealGetGeneralStateReq(char* ev_name,void* ev_data,char* ev_fmt)
{
     
}

//todo处理 获取用户配置请求
void VMLogic::DealGetUserCfgReq(char* ev_name,void* ev_data,char* ev_fmt)
{
     
}

//todo处理 获取默认时间请求
void VMLogic::DealGetTimeToEndReq(char* ev_name,void* ev_data,char* ev_fmt)
{
     
}
 