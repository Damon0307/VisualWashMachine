#ifndef __UTIL_H__
#define __UTIL_H__

/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-22 10:57:47
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-11-29 14:56:50
 * @FilePath: \VirtualMachineCpp\src\Util.h
 * @Description: 单例工具类
 */

#include <io.h>
#include <string>
#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <functional>
#include <memory>
#include <thread>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;

using json =nlohmann::json;

class Util
{
private:
    static  unique_ptr<Util>m_util;
    Util(/* args */){};
    
public:
   
    Util(const Util&)=delete;
    Util& operator=(const Util&)=delete;

    static Util* GetIns();
    void Dir(std::string);
    vector<string>GetFileNameByFormatUnderDir(const string& dir_path,const string& file_format);

    json GetJsonFromFile(const string& file);


    ~Util(){
       
    }

};

 

#endif // __UTIL_H__