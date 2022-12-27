/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:32:05
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-27 16:42:47
 * @FilePath: \VirtualMachineCpp\src\Drum.cpp
 * @Description:
 */
#include "Drum.h"

using namespace std;

int Drum::GetDrumID()
{
    return this->drum_id;
}

void Drum::SetDrumID(int p)
{
    this->drum_id = p;
}

int Drum::GetRunMode()
{
    return this->run_mode;
}

void Drum::SetRunMode(int p)
{
    this->run_mode = p;
}

int Drum::GetRunProgress()
{
    return this->run_progress;
}

void Drum::SetRunProgress(int p)
{
    this->run_progress = p;
}

int Drum::GetRunStage()
{
    return this->run_stage;
}

void Drum::SetRunStage(int p)
{
    this->run_stage = p;
}

int Drum::GetRunStrategy()
{
    return this->run_strategy;
}

void Drum::SetRunStrategy(int p)
{
    this->run_strategy = p;
}

int Drum::GetRunMaterialID()
{
    return this->run_process_id;
}

void Drum::SetMaterialID(int p)
{
    this->run_process_id = p;
}

int Drum::GetErrCode()
{
    return this->err_code;
}

void Drum::SetErrCode(int p)
{
    this->err_code = p;
}

int Drum::GetCurDoor()
{
    return this->door;
}

void Drum::SetCurDoor(int p)
{
    this->door = p;
}

void Drum::AddStrategy(Strategy *p_strategy)
{
    this->m_strategy_list.push_back(p_strategy);
}

void Drum::DealControlCmd(int strategy, int processid, int cmd_type, int cfgv1, int cfgv2, char *cfg_str)
{

    switch (cmd_type)
    {
    case ProcessCMD::QuickStart:
    {
        this->run_mode = RunMode::Running;
        this->run_progress = 0;
        this->run_stage = 0;
        this->run_process_id = processid;
    }
    break;
    case ProcessCMD::Coltrol:
    {
        if (cfgv1 == 1) // 启动
        {
            this->run_mode = RunMode::Running;
            this->run_progress = 0;
            this->run_stage = 0;
            this->run_process_id = processid;
            ReStartTimer();
        }
        else
        { // 暂停
            this->run_mode = RunMode::Pause;
            StopTimer();
        }
    }

    break;
    case ProcessCMD::GoWaitMode:
    {
        StopTimer();
        this->run_mode = RunMode::Ready;
        this->run_progress = 0;
        this->run_stage = 0;
        this->run_process_id = 0;
    }
    break;
    default:
        break;
    }
}

void Drum::InitProcessingData()
{
    vector<PreSetData> t{};
    m_data_runing.swap(t);

    m_data_runing.push_back({1, RunningData{RunMode::Running, 1, 1}});
    m_data_runing.push_back({3, RunningData{RunMode::Running, 2, 10}});
    m_data_runing.push_back({5, RunningData{RunMode::Running, 3, 25}});
    m_data_runing.push_back({8, RunningData{RunMode::Running, 4, 50}});
    m_data_runing.push_back({10, RunningData{RunMode::Running, 5, 99}});
    m_data_runing.push_back({15, RunningData{RunMode::Running, 6, 100}});
}

// 重置时间节点
void Drum::ReStartTimer()
{
    this->time_pos = 0;
    StopTimer();
    m_tiemr->setInterval([&]()
                         {
    for(auto& i : m_data_runing) 
    {
        if(this->time_pos <= i.first*1000)
        {
            this->run_mode = i.second.run_mode;
            this->run_stage = i.second.run_stage;
            this->run_progress = i.second.run_progress;
        }
    } },
                         500);
}

void Drum::StopTimer()
{
    m_tiemr->stop();
}
