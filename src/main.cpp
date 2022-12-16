/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:03:53
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-14 13:47:20
 * @FilePath: \VirtualMachineCpp\main.cpp
 * @Description
 */
#include <iostream>
#include <memory>
#include <thread>
#include "src/nlohmann/json.hpp"
#include "src/VirtualMachine.h"
#include "src/Util.h"

using namespace std;
using json=nlohmann::json;

int main()
{

    unique_ptr<VirtualMachine> uni_vm(new VirtualMachine());

    // string json_path =R"(D:\Sourcetrail_All\CodeBlock_Project\
    // VirtualMachineCpp\VirtualMachine\bin\Debug\MachineCfg\Machine.json)";
    string json_path = "MachineCfg/Machine.json";

    json j1= Util::GetIns()->GetJsonFromFile(json_path);
    cout<<j1<<endl;


    uni_vm.get()->InitFromJson(json_path);

    cout<<"Crazy boy"<<endl;


    auto res_tte = uni_vm.get()->GetTimeToEndRes();

    cout<<"LETS GO "<<res_tte->Drum1_Air_1<<endl;

    // auto g_util=Util::GetIns();
    // string test_path = R"(JsonFile)";
    // g_util->Dir(test_path);
    // for(auto i: g_util->GetFileNameByFormatUnderDir(test_path,"json"))
    // {
    //     cout<<" we got "<<i<<endl;
    // }

    //! cout<<"Hello Virtual  Machine"<<endl;

    getchar();
    return 0;
}
