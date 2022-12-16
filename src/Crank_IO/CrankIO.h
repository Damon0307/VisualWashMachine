/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-12-06 14:30:45
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-08 16:08:57
 * @FilePath: \VirtualMachine\src\Crank_IO\CrankIO.h
 * @Description: Crank IO 的 底层通讯的封装
 * 对外提供发送和接收 的接口
 */

#include <string>
#include <stdio.h>
#include <map>


using namespace std;

const string target_io_name ="hello";
const string m_io_name="me";


//should we add a topic for control the msg deliver
using ob_func = function<void(char*,void*,char*)>;

class CrankIO
{

public:
    CrankIO(/* args */){
       InitIOChannel();
    }
    ~CrankIO(){}
    void InitIOChannel();

    //data+fmt+len+target
    bool SendMSG(const char* data,const char* fmt,int len,const char* target=NULL);

    void RecvMSG();

    void AddObserver(ob_func observer_func, int observer_id);

    void DeleteObserver(int observer_id);

 private:

   map<int,ob_func> m_ob_map;
 
};


