/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-21 15:32:05
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-14 14:20:27
 * @FilePath: \VirtualMachineCpp\src\Drum.cpp
 * @Description:
 */
#include "Drum.h"
 
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
     this->run_mode =p;
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
     this->run_strategy =p;
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
     this->err_code =p;
 }
 
 int Drum::GetCurDoor()
 {
     return  this->door;
 }
 
 void Drum::SetCurDoor(int p)
 {
     this->door = p;
 }
 
 void Drum::AddStrategy(Strategy* p_strategy)
 {
     this->m_strategy_list.push_back(p_strategy);
 }
 
 