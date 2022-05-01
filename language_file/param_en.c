#include "param.h"
#if SUPPORT_EN
// 开机引导  语言选择 设置
const uint16_t font_boot_language_setting_en
{
	/*Language*/
};
// 开机引导  语言选择 确认
const uint16_t font_boot_language_confirm_en
{
	/*Cancel*/
	/*Set*/
};
// 开机引导  通信
const uint16_t font_boot_Communication_en
{
	/*Communication*/
};
// 开机引导  请打开手机蓝牙连接
const uint16_t font_boot_phone_to_connect_en
{
	/*Turn on phone's Bluetooth to connect*/
};
// 开机引导  连接后 可通过手表进行通话
const uint16_t font_boot_connected_Communication_en
{
	/*You can use watch to call after connection.*/
};
// 开机引导  通信中
const uint16_t font_boot_communicating_en
{
	/*Communicating*/
};
// 开机引导  语言选择 确认 long 
const uint16_t font_boot_language_confirm_en_long
{
	/*Set language to English on Watch?*/
};
// 开机引导  使用 H Band
const uint16_t font_boot_use_hband_en
{
	/*Use H Band*/
};
// 开机引导  使用 H Band long 
const uint16_t font_boot_use_hband_en_long
{
        /*Check condition and manage device via H Band.*/
};
// 开机引导  H Band
const uint16_t font_boot_hband_en
{
	/*H Band*/
};
// 开机引导  H Band 忽略 配对
const uint16_t font_boot_ignorepair_en
{
	/*Dismiss*/
	/*Pair*/
};

// 开机引导  请按侧边按键开始使用
const uint16_t font_boot_start_using
{
	/*Press Side Button to start*/
};
// 开机引导  低电
const uint16_t font_boot_low_power_en
{
	/*Low Battery*/
};
// 开机引导  低电 long 
const uint16_t font_boot_low_power_en_long
{
	/*To continue, charge enough power.*/
};
// 开机引导  充电中
const uint16_t font_boot_charging_en
{
	/*Charging*/
	/*Watch cannot be used temporarily.*/
};
// 开机引导  充电完成
const uint16_t font_boot_charge_finish_en
{
	/*Charging Completed*/
	/*Remove from charger.*/
};
// 开机引导  连接成功
const uint16_t font_boot_connected_en
{
	/*Connection Successful*/
};
// 开机引导  下载 H Band
const uint16_t font_boot_download_en
{
	/*Scan QR code to download H Band on phone and pair watch:*/
};
// 开机引导  关于设备
const uint16_t font_boot_about_en
{
	/*About*/
};
// 开机引导  设备名称
const uint16_t font_boot_name_en
{
	/*Name*/
};
// 开机引导  配对成功
const uint16_t font_boot_pair_success_en
{
	/*Pairing Successful*/
};

// 主界面  表盘传输中
const uint16_t font_main_in_transit_en
{
	/*Power Off*/
	/*Transferring*/
	/*Cancel*/
};

// 下拉  静音模式
const uint16_t font_down_muit_en
{
	/*Cancel*/
	/*Turn On*/
	/*Continue*/
	/*Communication*/
	/*Do Not Disturb*/
	/*Communicating*/
	/*On Communication*/
	/*Disconnect*/
};
// 下拉  静音模式 long 
const uint16_t font_down_muit_en_long
{
	/*The vibration alert will not be available. Continue?*/
	/*Headphone cannot be used. Continue?*/
	/*Music will pause. Continue?*/
	/*Connect via Bluetooth*/
};
// 下拉 星期
const uint16_t font_down_week_en
{
	/*Mon*/
	/*Tue*/
	/*Wed*/
	/*Thu*/
	/*Fri*/
	/*Sat*/
	/*Sun*/
};
// 下拉 月份
const uint16_t font_down_mouth_en
{
	/*Jan.*/
	/*Feb.*/
	/*Mar.*/
	/*Apr.*/
	/*May*/
	/*Jun.*/
	/*Jul.*/
	/*Aug.*/
	/*Sept.*/
	/*Oct.*/
	/*Nov.*/
	/*Dec.*/
};
//上午  下午
const uint16_t font_am_pm_en
{
	/*AM*/
	/*PM*/
};


//功能列表
const uint16_t font_function_en
{
	/*Workouts*/
	/*Pedometer*/
	/*Sleep*/
	/*Heart Rate*/
	/*Blood Pressure*/
	/*Weather*/	
	/*Call*/
	/*Contacts*/
	/*Call Log*/
	/*Notification*/
	/*Alarm*/
	/*Stopwatch*/
	/*Timer*/
	/*Music*/
	/*Find Phone*/
	/*Female*/
	/*Camera*/
	/*Calculator*/
	/*Voice Assistant*/
	/*Settings*/
};



//运动 秒表确认
const uint16_t font_sport_stopwatch_en
{
	/*Cancel*/
	/*Continue*/
};
//运动 秒表确认
const uint16_t font_sport_stopwatch_en_long
{
	/*End Stopwatch and enter Workouts?*/
};
//运动 模式
const uint16_t font_sport_mode_en
{
	/*Workouts*/
	/*Outdoor run*/
	/*Outdoor walk*/
	/*Indoor run*/
	/*Indoor walk*/
	/*Hiking*/
	/*Stair stepper*/
	/*Outdoor cycle*/
	/*Stationary bike*/
	/*Elliptical*/
	/*Rowing machine*/
	/*Mountaineering*/
	/*Dance*/
	/*Yoga*/
	/*HIIT*/
	/*Jump Rope*/
	/*Climbing*/
	/*Athletic*/
	/*Ball*/
	/*Fitness Gaming*/
	/*Fitness*/
	/*Free play*/
};

//运动 已暂停
const uint16_t font_sport_paused_en
{
	/*Paused*/
};
//运动 控制
const uint16_t font_sport_ctrl_en
{
	/*Resume*/
	/*Pause*/
	/*End*/
};
//运动 3s提示
const uint16_t font_sport_3S_tips_en
{
	/*Keep holding, workout will end in 3s*/
};
//运动 结束提示 long 
const uint16_t font_sport_end_tips_en_long
{
	/*Finished your workout?*/
};
//运动 确认结束
const uint16_t font_sport_end_of_confirmation_en
{
	/*Finished your workout?*/
	/*Resume*/ 
	/*End*/
};
//运动 数据不足
const uint16_t font_sport_no_data_en
{
	/*No Data*/
};
//运动 单位
const uint16_t font_sport_unit_en
{
	/*kcal*/
	/*bpm*/
	/*steps*/
	/*km*/
	/*/km*/
	/*mi*/
	/*/mi*/
};

//计步 
const uint16_t font_step_en
{
	/*Pedometer*/
	/*steps*/
	/*Distance*/
	/*km*/
	/*mi*/
	/*Calories*/
	/*kcal*/
};
//睡眠 
const uint16_t font_sleep_en
{
	/*Sleep*/
	/*h*/
	/*m*/
	/*Deep*/
	/*lig.*/
};
//心率 
const uint16_t font_heart_en
{
	/*Heart Rate*/
	/*bpm*/
	/*Last*/
};


//血压 
const uint16_t font_Blood_Pressure_en
{
	/*Blood Pressure*/
	/*Start*/
	/*Tap the button below to measure*/
};
//血压无数据 
const uint16_t font_Blood_Nodata_en
{
	/*No Data*/
};
//血压  开始
const uint16_t font_BP_last_not_wear_tips_en
{
	/*Blood Pressure*/
	/*Start*/
};

//血压  测试中
const uint16_t font_BP_testing_en
{
	/*Blood Pressure*/
	/*Measuring*/
};
//血压  测试中 long 
const uint16_t font_BP_testing_en_long
{
	/*Stay still and tighten watch*/
};
//血压  失败
const uint16_t font_BP_fail_en
{
	/*Blood Pressure*/
	/*Failed*/
	/*Retry*/
};
//血压  失败 long 
const uint16_t font_BP_fail_en_long
{
	/*Stay still and tighten watch*/
};
//血压  成功
const uint16_t font_BP_success_en
{
	/*Blood Pressure*/
	/*Measurement Successful*/
	/*mmHg*/
	/*Retry*/
};


//天气
const uint16_t font_weather_en
{
	/*Weather*/
	/*Tomorrow*/
};
//天气 long
const uint16_t font_weather_en_long 
{
	/*Open H Band to get the weather*/
};

//历史消息
const uint16_t font_history_message_type_en
{
	/*Incoming call*/
	/*SMS*/
	/*WeChat*/
	/*QQ*/
	/*Facebook*/
	/*Twitter*/
	/*LinkedIn*/
	/*WhatsApp*/
	/*LINE*/
	/*Instagram*/
	/*Snapchat*/
	/*Skype*/
	/*Gmail*/
	/*Other*/
};
//历史消息 无消息
const uint16_t font_history_no_message_en
{
	/*No Notification*/
};

//历史消息 删除
const uint16_t font_history_message_display_en
{
	/*Notifications*/
	/*Clear*/
};
//历史消息 清除确认
const uint16_t font_history_message_clear_enter_en
{
	/*Notifications*/
	/*Clear Notification?*/
	/*Cancel*/
	/*Clear*/
};

//闹钟
const uint16_t font_alarm_add_en
{
	/*Alarm*/
};
//闹钟 long
const uint16_t font_alarm_add_en_long
{
	/*Set Alarm via H Band*/
};
//闹钟
const uint16_t font_alarm_en
{
	/*Alarm*/
	/*Every day*/
	/*Weekdays*/
	/*Mon*/
	/*Tue*/
	/*Wed*/
	/*Thu*/
	/*Fri*/
	/*Sat*/
	/*Sun*/
};
//闹钟
const uint16_t font_alarm_display_en
{
	/*Remind later*/
	/*Turn off*/
};
//秒表
const uint16_t font_Stopwatch_en
{
	/*Stopwatch*/
};


//计时器 计时中
const uint16_t font_timering_en
{
	/*Timer*/
	/*Reset*/
	/*Pause*/
};	
//计时器 计时中
const uint16_t font_timer_paused_en
{
	/*Reset*/
	/*Resume*/
	/*Start*/
};
//计时器 结束
const uint16_t font_timer_end_en
{
	/*Timer*/
	/*Timer Done*/
	/*Repeat*/
};

//音乐
const uint16_t font_music_en
{
	/*Music*/
	/*No Music*/
	/*Volume*/
	/*Settings*/
};
//音乐 long
const uint16_t font_music_en_long
{
	/*Connect with phone*/
	/*Add Music via USB*/
	/*Accessing to info*/	
	/*Failed to Access*/
};
//音乐 播放模式
const uint16_t font_music_mode_en
{
	/*Order*/
	/*Repeat*/
	/*Shuffle*/
};
//音乐 音乐类型
const uint16_t font_music_class_en
{
	/*Setting*/
	/*Phone*/
	/*Watch*/
	/*Headphone*/
};
//音乐 状态
const uint16_t font_state_en
{
	/*Disconnected*/
	/*Connected*/
	/*Search*/
	/*Searching*/
	/*No device available*/
	/*Retry*/
	/*Completed*/
	/*Connecting*/
	/*Failed*/
	/*Connected*/
	/*Connect*/
	/*Disconnect*/
	/*Unpair*/
	/*Disconnected*/
	/*Unpaired*/
};

//语音助手
const uint16_t font_voice_en
{
	/*Voice Assistant*/
	/*Connecting*/
	/*Failed*/
	/*I'm listening...*/
	/*Weak Bluetooth Signal*/
};
//语音助手
const uint16_t font_voice_long_en
{
	/*Headphone are not available. Continue?*/
};


//相机
const uint16_t font_camera_disconnect_en
{
	/*Camera*/
	/*Shake*/
	/*Disconnected*/
};

//找手机 蓝牙未连接
const uint16_t font_find_phone_disconnect_en
{
	/*Find Phone*/
	/*Disconnected*/
};
//找手机 准备
const uint16_t font_find_phone_ready_en
{
	/*About to ring phone*/
};
//找手机中
const uint16_t font_find_phone_ing_en
{
	/*Ringing*/
};


//设置
const uint16_t font_setting_en
{
	/*Settings*/
	/*Brightness*/
	/*Auto-Lock*/
	/*Switch*/
	/*H Band*/
	/*Dial*/
	/*Notification*/
	/*Language*/
	/*About*/
	/*Erase Data*/
	/*Power OFF*/
};

//设置-
const uint16_t font_switch_setting_en
{
	/*HR Monitor*/
	/*BP Monitor*/
	/*HR Alert*/
	/*Disconnection Alert*/
	/*Turn Wrist to Wake*/
	/*Movement Reminder*/

};


//消息设置
const uint16_t font_message_settings_en
{
	/*Notifications*/
	/*Incoming call*/
	/*SMS*/
	/*WeChat*/
	/*QQ*/
	/*Facebook*/
	/*Twitter*/
	/*LinkedIn*/
	/*WhatsApp*/
	/*LINE*/
	/*Instagram*/
	/*Snapchat*/
	/*Skype*/
	/*Gmail*/
	/*Other*/
};

//设置 清除数据
const uint16_t font_erase_en
{
	/*Cancel*/
	/*Erase*/

};
//清除数据
const uint16_t font_erase_long_en
{
	/*All data cannot be recovered. Do you want to erase?*/
};
//消息设置 提醒
const uint16_t font_setting_tips_en
{
	/*Low Battery*/
	/*Get up and move!*/
	/*Disconnected*/
	/*Congratulations on completing goal*/
};


//系统设置
const uint16_t font_system_settings_en
{
	/*System*/
	/*Name*/
	/*About*/
	/*MAC*/
	/*Version*/
	/*BT_V*/
	/*Erase Data*/
	/*Power Off*/
	/*Pair with a new phone*/
};

//连接新手机
const uint16_t font_connect_a_new_phone_en
{
	/*Continue*/
	/*Cancel*/
};

//提醒
//电量过低
const uint16_t font_battery_is_low_en
{
	/*Low Battery*/
};
//蓝牙断开
const uint16_t font_bluetooth_disconnected_en
{
	/*Disconnected*/
};

//起来活动啦！
const uint16_t font_sedentary_en
{
	/*Get up and move!*/
};


//来电
const uint16_t font_call_en
{
	/*Call*/
	/*Contacts*/
	/*Call Log*/
	/*No Record*/
	/*Volume*/
	/*Unknown*/
	/*Connecting*/
	/*Hang up*/
	/*Answer*/
	/*Failed*/
	/*Answer on Phone*/
	/*Dialing…*/
	/*Mute*/
	/*Muted*/
	/*Unmute*/
	/*Weak Bluetooth Signal*/
	/*Call Ended*/
	/*Cancel*/
	/*Continue*/
};
//来电
const uint16_t font_call_long_en
{
	/*You need to connect phone via Bluetooth. Continue?*/
	/*Music will pause. Continue?*/
	/*Headphone are not available. Continue?*/
	/*Add Contacts via H Band*/
};
//来电提示
const uint16_t font_call_en
{
	/*Call*/
	/*Muted*/
	/*Call Ended*/
};


//老化 提示
const uint16_t font_ageing_tips_en
{
	/*Continue*/
	/*Exit*/
	/*Aging tests*/
	/*Exit Test?*/
};

//老化退出
const uint16_t font_ageing_quit_en
{
	Results
	Duration
	Times
	Completed
	Incomplete
};
#endif




//初次配对 选择语言
const uint16_t font_frist_choose_language_en_en
{
#if 	SUPPORT_ZH_CN	//中文（简体）（zh_cn）
	/*简体中文*/
#endif	
#if 	SUPPORT_ZH_HK	//中文（繁体）（zh_hk）
	/*繁體中文*/
#endif	
#if 	SUPPORT_KO	//韩语(ko)
	/*한국어	*/
#endif	
#if 	SUPPORT_JA	//日语（ja）
	/*日本語*/	
#endif	
#if 	SUPPORT_EN	//英语（en）
	/*English*/
#endif	
#if 	SUPPORT_DE_DE	//德语（德国）（de_de）
	/*Deutsch*/
#endif	
#if 	SUPPORT_FR_FR	//法语（法国）（fr_fr）
	/*Français*/	
#endif	
#if 	SUPPORT_IT_IT	//意大利语（意大利）（it_it）
	/*Italiano*/
#endif	
#if 	SUPPORT_ES_ES	//西班牙语（西班牙）（es_es）
	/*Español*/
#endif	
#if 	SUPPORT_PT_PT	//葡萄牙语（葡萄牙）（pt_pt）
	/*Português(Pt)*/
#endif	
#if 	SUPPORT_PT_BR	//葡萄牙语（巴西）（pt_br）
	/*Português(Br)*/
#endif	
#if 	SUPPORT_RU	//俄语（ru）
	/*Pусский*/
#endif	
#if 	SUPPORT_UK	//乌克兰语（uk）
	/*Українська Мова*/	
#endif	
#if 	SUPPORT_HU	//匈牙利语（hu）
	/*Magyar*/	
#endif	
#if 	SUPPORT_TUR	//土耳其语（tur）
	/*Türkçe*/	
#endif	
#if 	SUPPORT_ID	//印尼语（id）
	/*Indonesia*/	
#endif	
#if 	SUPPORT_RO	//罗马尼亚语（ro）
	/*Română*/	
#endif	
#if 	SUPPORT_PL	//波兰语（pl）
	/*Polski*/	
#endif	
#if 	SUPPORT_CS	//捷克语（cs）
	/*Čeština*/	
#endif	
#if 	SUPPORT_SK	//斯洛伐克语（sk）
	/*Slovenčina*/	
#endif	
#if 	SUPPORT_HR	//克罗地亚语（hr）
	/*Hrvatski*/
#endif	
#if 	SUPPORT_LT	//立陶宛语（lt）
	/*Lietuvių*/
#endif	
#if 	SUPPORT_VI	//越南语（vi）
	/*Tiếng Việt*/	
#endif	
#if 	SUPPORT_EL	//希腊语（el）
	/*Ελληνικά*/
#endif	
#if 	SUPPORT_AR_AE //阿拉伯语（阿联酋）（ar_ae）
	/*العربية*/		
#endif																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																		
#if 	SUPPORT_SV //瑞典语（sv）
	/*Svenska*/		
#endif	
#if 	SUPPORT_NL_NL //荷兰（sv）
	/*Dutch (Nederlands)*/		
#endif	
};
