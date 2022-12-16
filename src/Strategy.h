#ifndef __STRATEGY_H__
#define __STRATEGY_H__

/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-22 10:10:58
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-16 13:16:04
 * @FilePath: \VirtualMachineCpp\src\Strategy.h
 * @Description: 策略
 */

#include <map>
#include <deque>
#include <string>
#include <io.h>
#include "process.h"


class Strategy
{

public:
    Strategy(/* args */){}
    Strategy(const std::string& json_path);
    //通过ID 号 给程序设置 默认流程配置信息
    void SetProcessCfgByID(int p_id,Process* p_process);

    Process* GetProcess(int p_id);
    ~Strategy(){}
    int GetStrategyID()
    {
        return this->strategy_id;
    }

    void ShowCurStrategyProcessListID();
    private:
    int strategy_id;
    std::map<int,Process*>map_process;

   
   

};

 

#endif // __STRATEGY_H__