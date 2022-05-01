#include "param.h"
#if SUPPORT_EN
//密码
const uint16_t font_password
{
	/*输\n密码*/
	/*删除*/
	/*OK*/
	/*密码错误*/
	/*清除数据*/
	/*重试*/
};
// 开机引导  语言选择 设置
const uint16_t font_boot_language_setting
{
	/*语言设置*/
};
// 开机引导  语言选择 确认
const uint16_t font_boot_language_confirm
{
	/*取消*/
	/*设置*/
};
// 开机引导  语言选择 确认 long
const uint16_t font_boot_language_confirm_long
{
	/*将语言设为简体中文？*/
};
// 开机引导  使用是方健康手環
const uint16_t font_boot_use_hband
{
	/*使用是方健康手環*/
};
// 开机引导  使用是方健康手環 long
const uint16_t font_boot_use_hband_long
{
	/*通过是方健康手環查看健康状态，管理穿戴设备。*/
};
// 开机引导  H Band
const uint16_t font_boot_hband
{
	/*是方健康手環*/
};
// 开机引导  H Band 忽略 配对
const uint16_t font_boot_ignorepair
{
	/*忽略*/
	/*配对*/
};
// 开机引导  请在 是方健康手環 完成设置
const uint16_t font_boot_setting_for_hband
{
	/*打开是方健康手環添加设备*/
	/*请在是方健康手環完成设置*/
};
// 开机引导  请按侧边按键开始使用
const uint16_t font_boot_start_using
{
	/*请按侧边按键开始使用*/
};
// 开机引导  低电
const uint16_t font_boot_low_power
{
	/*电量过低*/
};
// 开机引导  低电 long 
const uint16_t font_boot_low_power_long
{
	/*请充入足够电量以继续*/
};
// 开机引导  充电中
const uint16_t font_boot_charging
{
	/*充电中*/
	/*暂时无法使用*/
};
// 开机引导  充电完成
const uint16_t font_boot_charge_finish
{
	/*充电完成*/
	/*请断开充电器*/
};




// 主界面  表盘传输中
const uint16_t font_main_in_transit
{
	/*关机*/
	/*表盘传输中*/
	/*取消*/
};
// 主界面  紧急 ECG 测试
const uint16_t font_main_urgent_ecg
{
	/*紧急 ECG 测试*/
	/*重启*/
};




// 下拉  静音模式
const uint16_t font_down_muit
{
	/*静音模式*/
	/*取消*/
	/*开启*/
};
// 下拉  静音模式 long 
const uint16_t font_down_muit_long
{
	/*开启后将不会振动提醒，是否开启？*/
};
// 下拉 星期
const uint16_t font_down_week
{
	/*周一*/
	/*周二*/
	/*周三*/
	/*周四*/
	/*周五*/
	/*周六*/
	/*周日*/
};
// 下拉 月份
const uint16_t font_down_mouth
{
	/*一月*/
	/*二月*/
	/*三月*/
	/*四月*/
	/*五月*/
	/*六月*/
	/*七月*/
	/*八月*/
	/*九月*/
	/*十月*/
	/*十一月*/
	/*十二月*/
};
//上午  下午
const uint16_t font_am_pm
{
	/*上午*/
	/*下午*/
};


//功能列表
const uint16_t font_function
{
	/*运动*/
	/*计步*/
	/*睡眠*/
	/*心率*/
	/*血压*/
	/*ECG*/
	/*血氧*/
	/*呼吸训练*/
	/*通知*/
	/*闹钟*/
	/*秒表*/
	/*计时器*/
	/*找手机*/
	/*女性*/
	/*相机*/
	/*设置*/
	/*天气*/
	/*音乐*/
	/*体温*/
};



//运动 秒表确认
const uint16_t font_sport_stopwatch
{
	/*取消*/
	/*继续*/
};
//运动 秒表确认 long
const uint16_t font_sport_stopwatch_long
{
	/*打开运动将结束秒表计时，是否继续？*/
};
//运动 模式
const uint16_t font_sport_mode
{   
    /*运动*/
	/*户外跑步*/
	/*户外步行*/
	/*室内跑步*/
	/*室内步行*/
	/*徒步*/
	/*踏步机*/
	/*户外骑行*/
	/*室内骑行*/
	/*椭圆机*/
	/*划船机*/
	/*篮球*/
	/*网球*/
	/*足球*/
	/*橄榄球*/
	/*排球*/
	/*羽毛球*/
	/*游泳*/
	/*乒乓球*/
	/*登山*/
	/*高尔夫*/
	/*体操*/
	/*舞蹈*/
	/*瑜伽*/
	/*普拉提*/
	/*太极*/
	/*滑雪*/
	/*高强度间歇运动*/
	/*跳绳*/
};
//运动 提示是否运动
const uint16_t font_sport_tips
{
	/*在跑步吗？*/
	/*在走路吗？*/
	/*户外*/
	/*室内*/
	/*忽略*/
};
//运动 心率区间
const uint16_t font_sport_heart_rate_zone
{
	/*心率区间*/
	/*极限*/
	/*无氧*/
	/*耐力*/
	/*减脂*/
	/*热身*/
};
//运动 已暂停
const uint16_t font_sport_paused
{
	/*已暂停*/
};
//运动 控制
const uint16_t font_sport_ctrl
{
	/*继续*/
	/*暂停*/
	/*结束*/
};
//运动 3s提示
const uint16_t font_sport_3S_tips
{
	/*请勿松手，3s 后将结束运动*/
};
//运动 结束提示
const uint16_t font_sport_end_tips
{
	/*加油，再坚持一下*/
	/*继续*/
	/*结束*/
};
//运动 结束提示 long 
const uint16_t font_sport_end_tips_long
{
	/*现在结束将失去本次记录，是否结束？*/
};
//运动 确认结束
const uint16_t font_sport_end_of_confirmation
{
	/*确认结束运动？*/
	/*继续*/
	/*结束*/
};
//运动 是否结束
const uint16_t font_sport_whether_to_end
{
	/*运动结束了吗？*/
};
//运动 数据不足
const uint16_t font_sport_no_data
{
	/*运动量不足*/
	/*请坚持运动*/
};
//运动 单位
const uint16_t font_sport_unit
{
	/*千卡*/
	/*次/分*/
	/*公里*/
	/*/公里*/
	/*英里*/
	/*/英里*/
};

//计步 
const uint16_t font_step
{
	/*计步*/
	/*步*/
	/*距离*/
	/*公里*/
	/*英里*/
	/*卡路里*/
	/*千卡*/
};
//睡眠 
const uint16_t font_sleep
{
	/*睡眠*/
	/*小时*/
	/*分钟*/
	/*深睡*/
};
//心率 
const uint16_t font_heart
{
	/*心率*/
	/*次/分*/
	/*上次*/
};
//血压 
const uint16_t font_Blood_Pressure
{
	/*血压*/
	/*开始*/
};
//血压 开始
const uint16_t font_BP_last_not_wear_tips
{
	/*血压*/
	/*开始*/
};
//血压  检查手表是否与手腕贴合 long 
const uint16_t font_BP_last_not_wear_tips_long
{
	/*检查手表是否与手腕贴合*/
};
//血压  测试中
const uint16_t font_BP_testing
{
	/*血压*/
};
//血压  测试中 long 
const uint16_t font_BP_testing_long
{
	/*贴合手腕佩戴且表面朝上*/
};
//血压  失败
const uint16_t font_BP_fail
{
	/*血压*/
	/*检测失败*/
	/*重新检测*/
};
//血压  失败 long 
const uint16_t font_BP_fail_long
{
	/*检查手表是否与手腕贴合*/
	/*检测时尽可能保持静止不动*/
};
//血压  成功
const uint16_t font_BP_success
{
	/*血压*/
	/*mmHg*/
	/*未见异常*/
	/*信号弱*/
	/*血压高*/
	/*血压低*/
	/*重新检测*/
};
//血压  成功 long 
const uint16_t font_BP_success_long
{
	/*该检测不适用于医疗用途。*/
	/*检测信号弱，结果仅供参考。*/
	/*如果感到不适，请咨询医生。*/
};




//血氧 
const uint16_t font_spo2
{
	/*血氧*/
	/*开始*/
};
//血氧  
const uint16_t font_spo2_last_not_wear_tips
{
	/*血氧*/
	/*开始*/
};
//血氧  测试中
const uint16_t font_spo2_testing
{
	/*血氧*/
};
//血氧  测试中 long 
const uint16_t font_spo2_testing_long
{
	/*贴合手腕佩戴且表面朝上*/
};
//血氧  失败
const uint16_t font_spo2_fail
{
	/*血氧*/
	/*检测失败*/
	/*重新检测*/
};
//血氧  失败 long 
const uint16_t font_spo2_fail_long
{
	/*检查手表是否与手腕贴合*/
	/*检测时尽可能保持静止不动*/
};
//血氧  成功
const uint16_t font_spo2_success
{
	/*血氧*/
	/*检测完成*/
	/*未见异常*/
	/*信号弱*/
	/*血氧水平低*/
	/*重新检测*/
};
//血氧  成功 long
const uint16_t font_spo2_success_long
{
	/*该检测不适用于医疗用途。*/
	/*检测信号弱，结果仅供参考。*/
	/*如果感到不适，请咨询医生。*/
};









//ECG 
const uint16_t font_ecg_start
{
	/*ECG*/
	/*开始*/
	/*次/分*/
};
//ECG  倒计时
const uint16_t font_ecg_start_countdown
{
	/*ECG*/
};
//ECG  倒计时 long 
const uint16_t font_ecg_start_countdown_long
{
	/*手指放在电极上进行检测*/
};
//ECG  检查手表是否与手腕贴合
const uint16_t font_ecg_last_not_wear_tips
{
	/*ECG*/
	/*开始*/
};
//ECG  检查手表是否与手腕贴合 long 
const uint16_t font_ecg_last_not_wear_tips_long
{
	/*检查手表是否与手腕贴合*/
};
//ECG  测试中
const uint16_t font_ecg_testing
{
	/*确保手指放在电极上*/
};
//ECG  测试中
const uint16_t font_ecg_fail
{
	/*ECG*/
	/*检测失败*/
	/*重新检测*/
};
//ECG  测试成功
const uint16_t font_ecg_success
{
	/*ECG*/
	/*重试*/
	/*保存*/
	/*次/分*/
	/*信号弱*/
	/*心率偏高*/
	/*心率偏低*/
	/*停搏*/
	/*室性早搏*/
	/*心房颤动*/
};
//ECG  测试成功 long 
const uint16_t font_ecg_success_long
{
	/*窦性心律，未见异常*/
	/*该检测不适用于医疗用途。*/
	/*检测信号弱，结果仅供参考。*/
	/*窦性心律不齐*/
	/*阵发性室性心动过速*/
	/*如果感到不适，请咨询医生。*/
};
//ECG  保存确认
const uint16_t font_ecg_save_enter
{
	/*ECG*/
	/*取消*/
	/*保存*/
};
//ECG  保存确认 long
const uint16_t font_ecg_save_enter_long
{
	/*是否保存此次检测结果？*/
	/*仅支持保存三次数据*/
};
//ECG  保存成功
const uint16_t font_ecg_save_success
{
	/*ECG*/
	/*保存成功*/
	/*返回*/
	/*重试*/
};
//ECG  保存成功 long 
const uint16_t font_ecg_save_success_long
{
	/*请前往是方健康手環查看*/
};







//体温
const uint16_t font_body_temperature_tips
{
	/*体温*/
	/*开始*/
};
//体温 long 
const uint16_t font_body_temperature_tips_long
{
	/*请先贴合手腕佩戴 10 分钟*/
};
//体温 测试中
const uint16_t font_body_temperature_testing
{
	/*体温*/
	/*测量中*/
};
//体温  成功
const uint16_t font_body_temperature_success
{
	/*体温*/
	/*检测完成*/
	/*重试*/
	/*皮肤*/
};
//体温 失败
const uint16_t font_body_temperature_fail
{
	/*体温*/
	/*温度异常*/
	/*重试*/
};
//体温 失败 long 
const uint16_t font_body_temperature_fail_long
{
	/*检查手表是否与手腕贴合*/
};





//呼吸
const uint16_t font_breathe
{
	/*呼吸训练*/
	/*分钟*/
	/*次*/
	/*次*/
	/*开始*/
};
//呼吸 提示
const uint16_t font_breathe_tips
{
	/*沉静下来，将注意力放在呼吸上*/
};
//呼吸中
const uint16_t font_breatheing
{
	/*吸气...*/
	/*呼气*/
};
//呼吸 结束
const uint16_t font_breathe_end
{
	/*呼吸训练*/
	/*好样的*/
	/*再来一次*/
};



//天气
const uint16_t font_weather
{
	/*天气*/
	/*明日*/
};
//天气 long 
const uint16_t font_weather_long
{
	/*请打开是方健康手環获取天气*/
};

//历史消息
const uint16_t font_history_message_type
{
	/*来电*/
	/*短信*/
	/*微信*/
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
	/*其他*/
};
//历史消息 无消息
const uint16_t font_history_no_message
{
	/*暂无消息*/
};
//历史消息 全部清除
const uint16_t font_history_message_all_clear
{
	/*通知*/
	/*全部清除*/
};
//历史消息 清除
const uint16_t font_history_message_display
{
	/*通知*/
	/*清除*/
};
//历史消息 清除确认
const uint16_t font_history_message_clear_enter
{
	/*通知*/
	/*是否清除消息？*/
	/*取消*/
	/*清除*/
};

//消息 新消息
const uint16_t font_new_message
{
	/*忽略*/
	/*清除*/
};






//闹钟
const uint16_t font_alarm_add
{
	/*闹钟*/
};
//闹钟 long
const uint16_t font_alarm_add_long
{
	/*请通过是方健康手環添加闹钟*/
};
//闹钟
const uint16_t font_alarm
{
	/*闹钟*/
	/*每日*/
	/*工作日*/
	/*一*/
	/*二*/
	/*三*/
	/*四*/
	/*五*/
	/*六*/
	/*日*/
	/*过期*/
};
//闹钟
const uint16_t font_alarm_display
{
	/*稍后提醒*/
	/*关闭*/
};



//计时器
const uint16_t font_timer
{
	/*计时器*/
	/*分钟*/
	/*小时*/
	/*自定义*/
};
//计时器 选择
const uint16_t font_timer_choose
{
	/*计时器*/
	/*自定义*/
	/*还原*/
	/*开始*/
};
//计时器 计时中
const uint16_t font_timering
{
	/*计时器*/
	/*自定义*/
	/*还原*/
	/*暂停*/
};	
//计时器 计时中
const uint16_t font_timer_paused
{
	/*已暂停*/
	/*还原*/
	/*继续*/
};
//计时器 结束
const uint16_t font_timer_end
{
	/*计时器*/
	/*自定义*/
	/*计时完成*/
	/*停止*/
	/*重复*/
};


//秒表
const uint16_t font_stopwatch
{
	/*秒表*/
	/*还原*/
	/*开始*/
};
//秒表 进行中
const uint16_t font_stopwatching
{
	/*秒表*/
	/*还原*/
	/*暂停*/
};
//秒表 已暂停
const uint16_t font_stopwatch_paused
{
	/*已暂停*/
	/*还原*/
	/*继续*/
};



//音乐
const uint16_t font_music
{
	/*音乐*/
	/*暂无音乐*/
	/*设置*/
};
//音乐 long
const uint16_t font_music_long
{
	/*请连接手机*/
	/*正在获取歌曲信息*/
	/*信息获取失败*/
};


//女性
const uint16_t font_femal_message
{
	/*女性*/
	/*知道了*/
};
//女性
const uint16_t font_femal
{
	/*请到是方健康手環设置*/
};


//相机 蓝牙未连接
const uint16_t font_camera_disconnect
{
	/*蓝牙未连接*/
	/*请检查蓝牙状态*/
};
//相机  拍照中
const uint16_t font_cameraing
{
	/*相机*/
};
//找手机 蓝牙未连接
const uint16_t font_find_phone_disconnect
{
	/*找手机*/
	/*蓝牙未连接*/
	/*请检查蓝牙状态*/
};
//找手机 准备
const uint16_t font_find_phone_ready
{
	/*即将让手机响铃*/
};
//找手机中
const uint16_t font_find_phone_ing
{
	/*正在响铃*/
};





//设置
const uint16_t font_setting
{
	/*设置*/
	/*屏幕与显示*/
	/*健康与监测*/
	/*密码设置*/
	/*开关设置*/
	/*消息设置*/
	/*语言设置*/
	/*是方健康手環*/
	/*帮助与提示*/
	/*系统设置*/
};
//屏幕与显示
const uint16_t font_screen_and_display
{
	/*屏幕与显示*/
	/*屏幕亮度*/
	/*亮屏时长*/
	/*功能界面*/
	/*网格视图*/
	/*列表视图*/
};
//健康与监测
const uint16_t font_health_and_monitoring
{
	/*健康与监测*/
	/*心脏*/
	/*心率监测*/
	/*心率警报*/
	/*血压监测*/
	/*血压警报*/
	/*血氧*/
	/*夜间监测*/
	/*低氧警报*/
	/*睡眠*/
	/*全天监测*/
	/*体温*/
	/*全天监测*/
	/*体温警报*/
	/*呼吸暂停监测*/
};
//健康与监测 long
const uint16_t font_health_and_monitoring_long
{
	/*「呼吸暂停监测」功能需要同时开启血氧「夜间监测」使用*/
};
//密码
const uint16_t font_password_setting
{
	/*密码设置*/
	/*打开密码*/
	/*关闭密码*/
	/*更改密码*/
	/*手腕检测*/
};
//密码 long 
const uint16_t font_password_setting_long
{
	/*摘下手表时将自动锁定手表*/
};
//开关设置
const uint16_t font_switch_setting
{
	/*开关设置*/
	/*成就提醒*/
	/*久坐提醒*/
	/*断连提醒*/
	/*翻腕亮屏*/
	/*运动识别*/
};
//开关设置 long 
const uint16_t font_switch_setting_long
{
	/*开启后可识别步行或跑步运动*/
};
//消息设置
const uint16_t font_message_settings
{
	/*消息设置*/
	/*来电*/
	/*短信*/
	/*微信*/
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
	/*其他*/
};
//帮助与提示
const uint16_t font_help_and_tips
{
	/*是方健康手環*/
	/*帮助与提示*/
	/*屏幕*/
	/*按键*/
	/*使用手册*/
};
//帮助与提示 long 
const uint16_t font_help_and_tips_long
{
	/*扫描上方二维码，获取帮助*/
};
//系统设置
const uint16_t font_system_settings
{
	/*系统设置*/
	/*MAC*/
	/*版本*/
	/*BT_V*/
	/*清除数据*/
	/*关机*/
	/*连接新手机*/
};
//清除数据提示
const uint16_t font_clear_data_tips
{
	/*取消*/
	/*清除*/
};
//清除数据提示 long 
const uint16_t font_clear_data_tips_long
{
	/*清除后数据将无法恢复，是否清除？*/
};
//清除数据中
const uint16_t font_clear_data_ing
{
	/*正在清除*/
};
//连接新手机
const uint16_t font_connect_a_new_phone
{
	/*继续*/
	/*取消*/
};
//连接新手机 long
const uint16_t font_connect_a_new_phone_long
{
	/*将断开当前连接的手机，个人数据不会丢失。是否继续？*/
	/*请在手机端解锁并取消与手表的配对*/
};





//提醒
//电量过低
const uint16_t font_battery_is_low
{
	/*电量过低*/
};
//蓝牙断开
const uint16_t font_bluetooth_disconnected
{
	/*蓝牙断开*/
};
//好样的
const uint16_t font_good_job
{
	/*好样的*/
};
//起来活动啦！
const uint16_t font_sedentary
{
	/*起来活动啦！*/
};
//心率低
const uint16_t font_low_heart_rate
{
	/*心率偏低*/
	/*次/分*/
};
//心率低 long 
const uint16_t font_low_heart_rate_long
{
	/*如果感到不适，请咨询医生。*/
};
//心率高
const uint16_t font_high_heart_rate
{
	/*心率偏高*/
	/*次/分*/
};
//血压低
const uint16_t font_low_BP
{
	/*血压低*/
	/*mmHg*/
};
//血压高
const uint16_t font_high_BP
{
	/*血压高*/
	/*mmHg*/
};
//血氧提示
const uint16_t font_low_spo2
{
	/*血氧水平低*/
};
//来电提示
const uint16_t font_call
{
	/*已静音*/
	/*已挂断*/
};
//老化 提示
const uint16_t font_ageing_tips
{
	/*继续*/
	/*退出*/
	/*老化测试*/
};
//老化 提示 long
const uint16_t font_ageing_tips_long
{
	/*是否退出老化模式？*/
};
//老化退出
const uint16_t font_ageing_quit
{
	/*老化时长*/
	/*循环次数*/
	/*完成*/
	/*未完成*/
	/*测试结果*/
};
#endif


