/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:03:53
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-16 16:31:43
 * @FilePath: \VirtualMachineCpp\main.cpp
 * @Description
 */
#include <iostream>
#include <memory>
#include <thread>
#include "src/VMLogic.h"
#include  "src/Crank_IO/CrankIO.h"

#include "src/Util.h"

using namespace std;
using json=nlohmann::json;
string JSON_ROOT_PATH = R"(MachineCfg/)";
int main()
{
 
    // string json_path =R"(D:\Sourcetrail_All\CodeBlock_Project\
    // VirtualMachineCpp\VirtualMachine\bin\Debug\MachineCfg\Machine.json)";

  
    string json_path = "MachineCfg/Machine.json";
    json j1= Util::GetIns()->GetJsonFromFile(json_path);
 //   cout<<j1<<endl;
 
    cout<<"Crazy boy"<<endl;
    unique_ptr<VMLogic> uni_vmlogic(new VMLogic(json_path));
    
    
    unique_ptr<CrankIO> uni_crankio(new CrankIO());

    auto send_func =std::bind(&CrankIO::SendMSG,uni_crankio.get(),std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4);

    auto recv_func =std::bind(&VMLogic::OnRecvDataFromCrankIO,uni_vmlogic.get(),std::placeholders::_1,std::placeholders::_2,std::placeholders::_3);
    
    uni_crankio.get()->AddObserver(recv_func,1);
 
    send_func(nullptr,nullptr,2,nullptr);
 

    getchar();
    return 0;
}
