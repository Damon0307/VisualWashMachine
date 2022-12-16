#ifndef __DRUM_H__
#define __DRUM_H__

/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:29:35
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-15 13:54:17
 * @FilePath: \VirtualMachineCpp\src\Drum.h
 * @Description:
 */

#include "Strategy.h"



class Drum
{

public:
    Drum(/* args */) {}
    ~Drum() {}
    int GetDrumID();
    void SetDrumID(int p);

    int GetRunMode();
    void SetRunMode(int p);

    int GetRunProgress();
    void SetRunProgress(int p);

    int GetRunStage();
    void SetRunStage(int p);

    int GetRunStrategy();
    void SetRunStrategy(int p);

    int GetRunMaterialID();
    void SetMaterialID(int p);

    int GetErrCode();
    void SetErrCode(int p);

    int GetCurDoor();
    void SetCurDoor(int p);

    void AddStrategy(Strategy* p_strategy);
    std::vector<Strategy*>& GetStrategyList()
    {
      return  m_strategy_list;
    }

//由于需要在命名空间中使用JSON映射功能，数据需要定义为public
public:
      int  drum_id;
      int  run_mode;
      int  run_strategy;
      int  run_process_id;
      int  run_stage;
      int  run_progress;
      int  door;
      int  err_code;
      std::vector<Strategy*>m_strategy_list;
};

#endif // __DRUM_H__
//今日放倍量+阳线+删除涨停+删除st+删除科创板+删除北交所+删除创业板+删除流通市值大于100亿