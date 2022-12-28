/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:03:53
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-28 14:05:53
 * @FilePath: \VirtualMachineCpp\main.cpp
 * @Description
 */
#include <iostream>
#include <memory>
#include <thread>
#include "src/VirtualMachine.h"
#include "src/Crank_IO/CrankIO.h"
#include "src/Util.h"
#include "src/timercpp.h"
 

using namespace std;
using json=nlohmann::json;
string JSON_ROOT_PATH = R"(MachineCfg/)";
 

int main()
{
 
    // string json_path =R"(D:\Sourcetrail_All\CodeBlock_Project\
    // VirtualMachineCpp\VirtualMachine\bin\Debug\MachineCfg\Machine.json)";
 
    string json_path = "MachineCfg/Machine.json";
 //   json j1= Util::GetIns()->GetJsonFromFile(json_path);
 //   cout<<j1<<endl;
 
    cout<<"Crazy boy"<<endl;
     unique_ptr<VirtualMachine> uni_vm(new VirtualMachine(json_path));
 
     unique_ptr<CrankIO> uni_crankio(new CrankIO());

    auto send_func =std::bind(&CrankIO::SendMSG,uni_crankio.get(),std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4);

    auto recv_func =std::bind(&VirtualMachine::OnRecvDataFromCrankIO,uni_vm.get(),std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);
    
    uni_crankio.get()->AddObserver(recv_func,1);
 
    uni_vm.get()->SetSendFunc(send_func);
 

    thread  io_recv_thread([&uni_crankio](){
        uni_crankio.get()->RecvMSG();
    });

    io_recv_thread.join();

    // Timer t1;
    // t1.setTimeout([&uni_vm](){
    //     uni_vm.get()->Test();
    // },2000);
    // Timer t2;
    // t2.setTimeout([&uni_crankio](){
    //     uni_crankio.get()->Test();
    // },4000);


    getchar();
    return 0;
}
