/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-12-16 11:21:19
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-16 15:29:53
 * @FilePath: \VirtualMachine\src\TTE.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <iostream>
#include <string>

#include "nlohmann/json.hpp"
#include "UI_Protocol_Events.h"

using json =nlohmann::json;

class TTE
{
private:
    /* data */
public:
    TTE(/* args */) {
        m_res_tte = (e_gettimetoendres_event_t *)malloc(sizeof(e_gettimetoendres_event_t));
    }
    ~TTE() {}
  //使用默认的赋值构造函数

  
int  Drum2_Wash_1=0;
int  Drum2_Wash_2=0;
int  Drum2_Wash_4=0;
int  Drum2_Wash_5=0;
int  Drum2_Wash_6=0;
int  Drum2_Wash_7=0;
int  Drum2_Wash_8=0;
int  Drum2_Wash_10=0;
int  Drum2_Wash_11=0;
int  Drum2_Wash_12=0;
int  Drum1_Dry_1=0;
int  Drum1_Dry_2=0;
int  Drum1_Dry_7=0;
int  Drum1_Dry_8=0;
int  Drum1_Dry_12=0;
int  Drum1_Air_1=0;
int  Drum1_Air_2=0;
int  Drum1_Air_3=0;
int  Drum1_Air_7=0;
int  Drum1_Air_8=0;
int  Drum1_Air_9=0;
int  Drum1_Air_12=0;
int  Drum1_Air_13=0;
int  Drum2_Wash_14=0;
int  Drum1_Air_15=0;
int  Drum2_Wash_16=0;
int  Drum1_Air_16=0;
int  Drum1_Dry_16=0;
int  Drum1_Air_17=0;
int  Drum2_Wash_18=0;
int  Drum2_Wash_19=0;
int  Drum1_Dry_19=0;
int  Drum2_Wash_20=0;
int  Drum1_Air_21=0;
int  Drum2_Wash_22=0;
int  Drum2_Wash_24=0;
int  Drum1_Dry_24=0;
int  Drum2_Wash_25=0;
int  Drum1_Dry_26=0;
int  Drum1_Air_26=0;
int  Drum2_Wash_26=0;
int  Drum1_Dry_27=0;
int  Drum1_Air_28=0;
int  Drum2_Wash_29=0;
int  Drum1_Dry_29=0;
int  Drum2_Wash_30=0;
int  Drum1_Air_31=0;
int  Drum1_Dry_32=0;
int  Drum2_Wash_32=0;
int  Drum1_Dry_33=0;
int  Drum1_Dry_34=0;
int  Drum2_Wash_34=0;
int  Drum1_Air_35=0;
int  Drum1_Dry_36=0;
int  Drum2_Wash_36=0;
int  Drum1_Dry_37=0;
int  Drum1_Wellness_38=0;
int  Drum1_Wellness_39=0;
int  Drum1_Wellness_40=0;
int  Drum1_Wellness_41=0;
int  Drum1_Dry_42=0;
 
    e_gettimetoendres_event_t *GetTimeToEndRes()
    {
        memset(m_res_tte,0,sizeof(*m_res_tte));
        m_res_tte->Drum1_Air_12=this->Drum1_Air_12;
        m_res_tte->Drum1_Air_13=this->Drum1_Air_13;
        m_res_tte->Drum1_Air_15=this->Drum1_Air_15;
        m_res_tte->Drum1_Air_16=this->Drum1_Air_16;
        m_res_tte->Drum1_Air_17=this->Drum1_Air_17;
        m_res_tte->Drum1_Air_1=this->Drum1_Air_1;
        m_res_tte->Drum1_Air_21=this->Drum1_Air_21;
        m_res_tte->Drum1_Air_26=this->Drum1_Air_26;
        m_res_tte->Drum1_Air_28=this->Drum1_Air_28;
        m_res_tte->Drum1_Air_2 =this->Drum1_Air_2;
        m_res_tte->Drum1_Air_31=this->Drum1_Air_31;
        m_res_tte->Drum1_Air_35=this->Drum1_Air_35;
        m_res_tte->Drum1_Air_3=this->Drum1_Air_3;
        m_res_tte->Drum1_Air_7=this->Drum1_Air_7;
        m_res_tte->Drum1_Air_8=this->Drum1_Air_7;
        m_res_tte->Drum1_Air_8=this->Drum1_Air_8;
        m_res_tte->Drum1_Air_9=this->Drum1_Air_9;
        m_res_tte->Drum1_Dry_12=this->Drum1_Dry_12;
        m_res_tte->Drum1_Dry_16=this->Drum1_Dry_16;
        m_res_tte->Drum1_Dry_19=this->Drum1_Dry_19;
        m_res_tte->Drum1_Dry_1=this->Drum1_Dry_1;
        m_res_tte->Drum1_Dry_24=this->Drum1_Dry_24;
        m_res_tte->Drum1_Dry_26=this->Drum1_Dry_26;
        m_res_tte->Drum1_Dry_27=this->Drum1_Dry_27;
        m_res_tte->Drum1_Dry_29=this->Drum1_Dry_29;
        m_res_tte->Drum1_Dry_2=this->Drum1_Dry_2;
        m_res_tte->Drum1_Dry_32=this->Drum1_Dry_32;
        m_res_tte->Drum1_Dry_33=this->Drum1_Dry_33;
        m_res_tte->Drum1_Dry_34=this->Drum1_Dry_34;
        m_res_tte->Drum1_Dry_37=this->Drum1_Dry_37;
        m_res_tte->Drum1_Dry_42=this->Drum1_Dry_42;
        m_res_tte->Drum1_Dry_7=this->Drum1_Dry_7;
        m_res_tte->Drum1_Dry_8=this->Drum1_Dry_8;

        return m_res_tte;
    }
    private:
    e_gettimetoendres_event_t *m_res_tte;
};
