#ifndef __DRUM_H__
#define __DRUM_H__

/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:29:35
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-27 16:22:59
 * @FilePath: \VirtualMachineCpp\src\Drum.h
 * @Description:
 */

#include "Strategy.h"
#include "timercpp.h"
 #include <vector>

struct RunningData
{
  int run_mode;
  int run_stage;
  int run_progress;
  //好像，剩余时间的属性放在筒里面会更好把握
};

 using PreSetData=std::pair<int,RunningData>;

#define  RUNNING_TIMER_INTERVAL 500  //默认定时器的间隔 单位:ms
class Drum
{

public:
    Drum(/* args */) { 
      m_tiemr = new Timer();
      InitProcessingData();
    }
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

    void DealControlCmd(int strategy,int processid, int cmd_type,int cfgv1,int cfgv2,char* cfg_str);

 
  private:
      Timer  *m_tiemr;
      int   time_pos;  //当前时间点
//!一组不断变化的预先设定好的数据集, 配合定时器使用，达到模拟流程运行全过程的目的
      std::vector<PreSetData> m_data_runing;
      void InitProcessingData();
      void ReStartTimer();
      void StopTimer();


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
 