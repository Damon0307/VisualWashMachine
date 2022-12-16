/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-12-07 11:13:49
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-14 13:10:32
 * @FilePath: \VirtualMachine\src\VMLogic.h
 * @Description: 虚拟机模型的业务逻辑部分，主要从 数据层 得到属于以后，对书进行解析，然后对业务进行分发处理
 */
#ifndef __VMLOGIC_H__
#define __VMLOGIC_H__

 
#include <string>
#include <functional>
#include <unordered_map>
#include <memory>

#include "VirtualMachine.h"

using event_slot =std::function<void(char*,void*,char*)>;

class VMLogic
{

public:
    VMLogic(/* args */){}
    ~VMLogic(){}

    void LoadMachine(std::unique_ptr<VirtualMachine> p);

//todo 有可能从UI拉的模式，改成后端推的模式，所以 可能需要引入定时器

    void DealGetProcessCfgReq(char* ev_name,void* ev_data,char* ev_fmt);
    void DealGetMachineStateReq(char* ev_name,void* ev_data,char* ev_fmt);
    void DealGetGeneralStateReq(char* ev_name,void* ev_data,char* ev_fmt);
    void DealGetUserCfgReq(char* ev_name,void* ev_data,char* ev_fmt);
    void DealGetTimeToEndReq(char* ev_name,void* ev_data,char* ev_fmt);
       
    void OnRecvDataFromCrankIO(char* ev_name,void* ev_data,char* ev_fmt);

    void InitSlotMap(const char* event_name,event_slot& event_slot);

    inline void SetSendFunc(std::function<int(const char *, const char *, int ,const char*)>p_send_func)
    {
        this->m_send_func = p_send_func;
    }
    private:

    std::unique_ptr<VirtualMachine>m_vm;

    //data+fmt+len+target
    std::function<int(const char *, const char *, int ,const char*)>m_send_func;

    std::unordered_map<std::string,event_slot>m_slots_map;

};

 
 #endif // __VMLOGIC_H__