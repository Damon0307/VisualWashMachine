#ifndef __UI_PROTOCOL_EVENTS_H__
#define __UI_PROTOCOL_EVENTS_H__



#define E_GETGENERALSTATEREQ_EVENT "E_GetGeneralStateReq"
#define E_GETMACHINESTATEREQ_EVENT "E_GetMachineStateReq"

#define E_GETPROCESSCONFIGREQ_EVENT "E_GetProcessConfigReq"
#define E_GETPROCESSCONFIGREQ_FMT "4u1 process_id 1u1 strategy 1u1 drum_id"
typedef struct {
	uint32_t process_id;
	uint8_t strategy;
	uint8_t drum_id;
} e_getprocessconfigreq_event_t;

#define E_GETTIMETOENDREQ_EVENT "E_GetTimeToEndReq"

#define E_GETUSERCONFIGREQ_EVENT "E_GetUserConfigReq"

#define E_REPEAT_BACKGROUND_VIDEO_EVENT "e_repeat_background_video"
#define E_REPEAT_BACKGROUND_VIDEO_FMT "1s0 video_id"
typedef struct {
	char 	video_id[1];
} e_repeat_background_video_event_t;

#define E_SETPROCESSCONFIGREQ_EVENT "E_SetProcessConfigReq"
#define E_SETPROCESSCONFIGREQ_FMT "4u1 cur_strategy 4u1 cur_process_id 4u1 config_type 4u1 config_value1 4u1 config_value2 1u1 drum_id 1s0 config_str"
typedef struct {
	uint32_t cur_strategy;
	uint32_t cur_process_id;
	uint32_t config_type;
	uint32_t config_value1;
	uint32_t config_value2;
	uint8_t drum_id;
	char    	config_str[1];
} e_setprocessconfigreq_event_t;

#define E_SETUSERCONFIGREQ_EVENT "E_SetUserConfigReq"
#define E_SETUSERCONFIGREQ_FMT "4s1 user_config_value1 4s1 user_config_value2 1u1 user_config_type 1s0 user_config_value_str"
typedef struct {
	int32_t user_config_value1;
	int32_t user_config_value2;
	uint8_t user_config_type;
	char   	user_config_value_str[1];
} e_setuserconfigreq_event_t;

#define E_COMMERROR_EVENT "E_CommError"
#define E_COMMERROR_FMT "1u1 error_num 1s0 error_msg"
typedef struct {
	uint8_t error_num;
	char   	error_msg[1];
} e_commerror_event_t;

#define E_GETGENERALSTATERES_EVENT "E_GetGeneralStateRes"
#define E_GETGENERALSTATERES_FMT "8u1 cur_rtc 4u1 cur_temperature 4u1 cur_screen_backlight_mode 1u1 cur_weather 1u1 cur_greeting 1s0 cur_system_info"
typedef struct {
	uint64_t cur_rtc;
	uint32_t cur_temperature;
	uint32_t cur_screen_backlight_mode;
	uint8_t cur_weather;
	uint8_t cur_greeting;
	char    	cur_system_info[1];
} e_getgeneralstateres_event_t;

#define E_GETMACHINESTATERES_EVENT "E_GetMachineStateRes"
#define E_GETMACHINESTATERES_FMT "4u1 drum1_process_id 4u1 drum2_process_id 2u1 drum1_err_code 2u1 drum2_err_code 2u1 uibackend_err_code 1u1 drum1_progress 1u1 drum1_stage 1u1 drum1_strategy 1u1 drum1_run_mode 1u1 drum2_progress 1u1 drum2_stage 1u1 drum2_strategy 1u1 drum2_run_mode 1u1 drum1_door 1u1 drum2_door 1u1 coupling_wd_state 1u1 network"
typedef struct {
	uint32_t drum1_process_id;
	uint32_t drum2_process_id;
	uint16_t drum1_err_code;
	uint16_t drum2_err_code;
	uint16_t uibackend_err_code;
	uint8_t drum1_progress;
	uint8_t drum1_stage;
	uint8_t drum1_strategy;
	uint8_t drum1_run_mode;
	uint8_t drum2_progress;
	uint8_t drum2_stage;
	uint8_t drum2_strategy;
	uint8_t drum2_run_mode;
	uint8_t drum1_door;
	uint8_t drum2_door;
	uint8_t coupling_wd_state;
	uint8_t network;
} e_getmachinestateres_event_t;

#define E_GETPROCESSCONFIGRES_EVENT "E_GetProcessConfigRes"
#define E_GETPROCESSCONFIGRES_FMT "4u1 process_id 4u1 cur_remain_time 2u1 reserve_cur 2u1 reserve_max 2u1 reserve_min 2u1 cur_remain_anti_wrinkle_time 1u1 dry_time_min 1u1 dry_time_max 1u1 dry_time_cur 1u1 speed_ctrl 1u1 speed_vis 1u1 speed_cur 1u1 speed_max 1u1 speed_min 1u1 wash_temp_ctrl 1u1 wash_temp_vis 1u1 wash_temp_cur 1u1 wash_temp_max 1u1 wash_temp_min 1u1 rinse_ctrl 1u1 rinse_vis 1u1 rinse_cur 1u1 rinse_max 1u1 rinse_min 1u1 wash_time_ctrl 1u1 wash_time_vis 1u1 wash_time_cur 1u1 wash_time_max 1u1 wash_time_min 1u1 super_air_cur 1u1 super_air_standard_vc 1u1 super_air_steri_vc 1u1 super_air_desmell_vc 1u1 super_air_dewrinkle_vc 1u1 super_air_fluffy_vc 1u1 super_air_dehumid_vc 1u1 super_air_plasma_vc 1u1 sanitize_ctrl 1u1 sanitize_vis 1u1 sanitize_cur 1u1 anion_ctrl 1u1 anion_vis 1u1 anion_cur 1u1 dry_level_ctrl 1u1 dry_level_vis 1u1 dry_level_cur 1u1 dry_level_max 1u1 dry_level_min 1u1 dry_mode_standard_vis 1u1 dry_mode_quick_vis 1u1 dry_mode_eco_vis 1u1 dry_mode_vis 1u1 dry_mode_cur 1u1 anti_wrinkle_ctrl 1u1 anti_wrinkle_vis 1u1 anti_wrinkle_cur 1u1 anti_wrinkle_max 1u1 anti_wrinkle_min 1u1 dry_time_ctrl 1u1 dry_time_vis 1u1 dry_temp_ctrl 1u1 dry_temp_vis 1u1 dry_temp_cur 1u1 dry_temp_min 1u1 dry_temp_max 1u1 reserve_ctrl 1u1 reserve_vis 1u1 strategy 1u1 drum_id 1u1 uv_cur 1u1 uv_vis 1u1 uv_ctrl 1u1 plasma_vis 1u1 plasma_cur 1u1 plasma_ctrl 1u1 coupling_wd_vis 1u1 coupling_wd_cur 1u1 coupling_wd_ctrl 1u1 stain_vis 1u1 stain_cur 1u1 stain_ctrl 1u1 high_water_level_cur 1u1 high_water_level_vc 1u1 super_clean_wash_cur 1u1 super_clean_wash_vc 1u1 soak_wash_cur 1u1 soak_wash_vc 1u1 night_wash_cur 1u1 night_wash_vc 1u1 eco_wash_cur 1u1 eco_wash_vc 1u1 anti_allergy_cur 1u1 anti_allergy_vc 1u1 super_air_deacarid_vc 1u1 super_air_fast_vc 1u1 super_air_dealde_vc 1u1 Detergent_vis 1u1 Detergent_cur 1u1 Detergent_ctrl 1u1 Detergent_vol 1u1 Softener_vis 1u1 Softener_cur 1u1 Softener_ctrl 1u1 Softener_vol 1u1 super_air_plasma_cur"
typedef struct {
	uint32_t process_id;
	uint32_t cur_remain_time;
	uint16_t reserve_cur;
	uint16_t reserve_max;
	uint16_t reserve_min;
	uint16_t cur_remain_anti_wrinkle_time;
	uint8_t dry_time_min;
	uint8_t dry_time_max;
	uint8_t dry_time_cur;
	uint8_t speed_ctrl;
	uint8_t speed_vis;
	uint8_t speed_cur;
	uint8_t speed_max;
	uint8_t speed_min;
	uint8_t wash_temp_ctrl;
	uint8_t wash_temp_vis;
	uint8_t wash_temp_cur;
	uint8_t wash_temp_max;
	uint8_t wash_temp_min;
	uint8_t rinse_ctrl;
	uint8_t rinse_vis;
	uint8_t rinse_cur;
	uint8_t rinse_max;
	uint8_t rinse_min;
	uint8_t wash_time_ctrl;
	uint8_t wash_time_vis;
	uint8_t wash_time_cur;
	uint8_t wash_time_max;
	uint8_t wash_time_min;
	uint8_t super_air_cur;
	uint8_t super_air_standard_vc;
	uint8_t super_air_steri_vc;
	uint8_t super_air_desmell_vc;
	uint8_t super_air_dewrinkle_vc;
	uint8_t super_air_fluffy_vc;
	uint8_t super_air_dehumid_vc;
	uint8_t super_air_plasma_vc;
	uint8_t sanitize_ctrl;
	uint8_t sanitize_vis;
	uint8_t sanitize_cur;
	uint8_t anion_ctrl;
	uint8_t anion_vis;
	uint8_t anion_cur;
	uint8_t dry_level_ctrl;
	uint8_t dry_level_vis;
	uint8_t dry_level_cur;
	uint8_t dry_level_max;
	uint8_t dry_level_min;
	uint8_t dry_mode_standard_vis;
	uint8_t dry_mode_quick_vis;
	uint8_t dry_mode_eco_vis;
	uint8_t dry_mode_vis;
	uint8_t dry_mode_cur;
	uint8_t anti_wrinkle_ctrl;
	uint8_t anti_wrinkle_vis;
	uint8_t anti_wrinkle_cur;
	uint8_t anti_wrinkle_max;
	uint8_t anti_wrinkle_min;
	uint8_t dry_time_ctrl;
	uint8_t dry_time_vis;
	uint8_t dry_temp_ctrl;
	uint8_t dry_temp_vis;
	uint8_t dry_temp_cur;
	uint8_t dry_temp_min;
	uint8_t dry_temp_max;
	uint8_t reserve_ctrl;
	uint8_t reserve_vis;
	uint8_t strategy;
	uint8_t drum_id;
	uint8_t uv_cur;
	uint8_t uv_vis;
	uint8_t uv_ctrl;
	uint8_t plasma_vis;
	uint8_t plasma_cur;
	uint8_t plasma_ctrl;
	uint8_t coupling_wd_vis;
	uint8_t coupling_wd_cur;
	uint8_t coupling_wd_ctrl;
	uint8_t stain_vis;
	uint8_t stain_cur;
	uint8_t stain_ctrl;
	uint8_t high_water_level_cur;
	uint8_t high_water_level_vc;
	uint8_t super_clean_wash_cur;
	uint8_t super_clean_wash_vc;
	uint8_t soak_wash_cur;
	uint8_t soak_wash_vc;
	uint8_t night_wash_cur;
	uint8_t night_wash_vc;
	uint8_t eco_wash_cur;
	uint8_t eco_wash_vc;
	uint8_t anti_allergy_cur;
	uint8_t anti_allergy_vc;
	uint8_t super_air_deacarid_vc;
	uint8_t super_air_fast_vc;
	uint8_t super_air_dealde_vc;
	uint8_t Detergent_vis;
	uint8_t Detergent_cur;
	uint8_t Detergent_ctrl;
	uint8_t Detergent_vol;
	uint8_t Softener_vis;
	uint8_t Softener_cur;
	uint8_t Softener_ctrl;
	uint8_t Softener_vol;
	uint8_t super_air_plasma_cur;
} e_getprocessconfigres_event_t;

#define E_GETTIMETOENDRES_EVENT "E_GetTimeToEndRes"
#define E_GETTIMETOENDRES_FMT "1u1 Drum2_Wash_1 1u1 Drum2_Wash_2 1u1 Drum2_Wash_4 1u1 Drum2_Wash_5 1u1 Drum2_Wash_6 1u1 Drum2_Wash_7 1u1 Drum2_Wash_8 1u1 Drum2_Wash_10 1u1 Drum2_Wash_11 1u1 Drum2_Wash_12 1u1 Drum1_Dry_1 1u1 Drum1_Dry_2 1u1 Drum1_Dry_7 1u1 Drum1_Dry_8 1u1 Drum1_Dry_12 1u1 Drum1_Air_1 1u1 Drum1_Air_2 1u1 Drum1_Air_3 1u1 Drum1_Air_7 1u1 Drum1_Air_8 1u1 Drum1_Air_9 1u1 Drum1_Air_12 1u1 Drum1_Air_13 1u1 Drum2_Wash_14 1u1 Drum1_Air_15 1u1 Drum2_Wash_16 1u1 Drum1_Air_16 1u1 Drum1_Dry_16 1u1 Drum1_Air_17 1u1 Drum2_Wash_18 1u1 Drum2_Wash_19 1u1 Drum1_Dry_19 1u1 Drum2_Wash_20 1u1 Drum1_Air_21 1u1 Drum2_Wash_22 1u1 Drum2_Wash_24 1u1 Drum1_Dry_24 1u1 Drum2_Wash_25 1u1 Drum1_Dry_26 1u1 Drum1_Air_26 1u1 Drum2_Wash_26 1u1 Drum1_Dry_27 1u1 Drum1_Air_28 1u1 Drum2_Wash_29 1u1 Drum1_Dry_29 1u1 Drum2_Wash_30 1u1 Drum1_Air_31 1u1 Drum1_Dry_32 1u1 Drum2_Wash_32 1u1 Drum1_Dry_33 1u1 Drum1_Dry_34 1u1 Drum2_Wash_34 1u1 Drum1_Air_35 1u1 Drum1_Dry_36 1u1 Drum2_Wash_36 1u1 Drum1_Dry_37 1u1 Drum1_Wellness_38 1u1 Drum1_Wellness_39 1u1 Drum1_Wellness_40 1u1 Drum1_Wellness_41 1u1 Drum1_Dry_42"
typedef struct {
	uint8_t Drum2_Wash_1;
	uint8_t Drum2_Wash_2;
	uint8_t Drum2_Wash_4;
	uint8_t Drum2_Wash_5;
	uint8_t Drum2_Wash_6;
	uint8_t Drum2_Wash_7;
	uint8_t Drum2_Wash_8;
	uint8_t Drum2_Wash_10;
	uint8_t Drum2_Wash_11;
	uint8_t Drum2_Wash_12;
	uint8_t Drum1_Dry_1;
	uint8_t Drum1_Dry_2;
	uint8_t Drum1_Dry_7;
	uint8_t Drum1_Dry_8;
	uint8_t Drum1_Dry_12;
	uint8_t Drum1_Air_1;
	uint8_t Drum1_Air_2;
	uint8_t Drum1_Air_3;
	uint8_t Drum1_Air_7;
	uint8_t Drum1_Air_8;
	uint8_t Drum1_Air_9;
	uint8_t Drum1_Air_12;
	uint8_t Drum1_Air_13;
	uint8_t Drum2_Wash_14;
	uint8_t Drum1_Air_15;
	uint8_t Drum2_Wash_16;
	uint8_t Drum1_Air_16;
	uint8_t Drum1_Dry_16;
	uint8_t Drum1_Air_17;
	uint8_t Drum2_Wash_18;
	uint8_t Drum2_Wash_19;
	uint8_t Drum1_Dry_19;
	uint8_t Drum2_Wash_20;
	uint8_t Drum1_Air_21;
	uint8_t Drum2_Wash_22;
	uint8_t Drum2_Wash_24;
	uint8_t Drum1_Dry_24;
	uint8_t Drum2_Wash_25;
	uint8_t Drum1_Dry_26;
	uint8_t Drum1_Air_26;
	uint8_t Drum2_Wash_26;
	uint8_t Drum1_Dry_27;
	uint8_t Drum1_Air_28;
	uint8_t Drum2_Wash_29;
	uint8_t Drum1_Dry_29;
	uint8_t Drum2_Wash_30;
	uint8_t Drum1_Air_31;
	uint8_t Drum1_Dry_32;
	uint8_t Drum2_Wash_32;
	uint8_t Drum1_Dry_33;
	uint8_t Drum1_Dry_34;
	uint8_t Drum2_Wash_34;
	uint8_t Drum1_Air_35;
	uint8_t Drum1_Dry_36;
	uint8_t Drum2_Wash_36;
	uint8_t Drum1_Dry_37;
	uint8_t Drum1_Wellness_38;
	uint8_t Drum1_Wellness_39;
	uint8_t Drum1_Wellness_40;
	uint8_t Drum1_Wellness_41;
	uint8_t Drum1_Dry_42;
} e_gettimetoendres_event_t;

#define E_GETUSERCONFIGRES_EVENT "E_GetUserConfigRes"
#define E_GETUSERCONFIGRES_FMT "4u1 online_time 1u1 ai_voice 1u1 ai_voice_volume 1u1 ai_sort 1u1 net_state 1u1 kid_lock 1u1 anti_wrinkle 1u1 mute 1u1 online_wash 1u1 user_login_state 1u1 inform_volume 1u1 touch_volume 1u1 screen_brightness 1u1 auto_sync_time"
typedef struct {
	uint32_t online_time;
	uint8_t ai_voice;
	uint8_t ai_voice_volume;
	uint8_t ai_sort;
	uint8_t net_state;
	uint8_t kid_lock;
	uint8_t anti_wrinkle;
	uint8_t mute;
	uint8_t online_wash;
	uint8_t user_login_state;
	uint8_t inform_volume;
	uint8_t touch_volume;
	uint8_t screen_brightness;
	uint8_t auto_sync_time;
} e_getuserconfigres_event_t;

#define E_NOTIFICATION_EVENT "E_Notification"
#define E_NOTIFICATION_FMT "4u1 event_type 4u1 value1 4u1 value2 1u1 drum_id 1s0 value_str"
typedef struct {
	uint32_t event_type;
	uint32_t value1;
	uint32_t value2;
	uint8_t drum_id;
	char    	value_str[1];
} e_notification_event_t;

#define E_TEST_EVENT "E_Test"
#define E_TEST_FMT "4u1 hello 1u5 af"
typedef struct {
	uint32_t hello;
	uint8_t 	af[5];
} e_test_event_t;




/****************************************枚举定义***********************************************/

 
 enum ProcessCMD {
    Selected=1, //! 程序选择 //起始值为  1
    QuickStart, // 快速启动
    Coltrol, // 普通 启动/暂停
    GoWaitMode, // 程序停止
    Reserve, // 预约
    Temperature, //烘干温度
    DryTime, // 烘干时间
    AntiWrink, // 防皱
    DryMode, // 烘干模式待商榷
    DryLevel, // 干燥度
    Anion, // 负离子
    Sanitize, // 除菌螨
    SuperAirMode, // 超级空气洗优化模式
    SwitchProcess, // 在已经运行流程状态下切换到新的流程并进入配置界面
    WashTime,//洗涤时间
    WashTemp,//洗涤温度
    Rinse,//漂洗次数
    Speed,//转速
    Stain,//特渍
    UV,//紫外
    Plasma,//光等离子
    CouplingWD,//洗烘联动
    HighWaterLevel, //附加功能 高水位
    SuperCleanWash, //附加功能 超净洗
    SoakWash,       //附加功能 浸泡洗
    NightWash,      //附加功能 夜间洗
    ECOWash,        //附加功能 节能洗
    AntiAllergy,    //附加功能 防过敏
    Detergent,//洗涤剂  
    Softener,//柔顺剂   
};


 enum RunMode {
    ShutDown=0, //   
    Ready, //  
    Running, // 
    Pause, //  
    AddCloth, //  
    Invalid, // 
    
 };

#endif // __UI_PROTOCOL_EVENTS_H__