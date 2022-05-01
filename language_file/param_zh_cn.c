#include "param.h"
#if SUPPORT_EN
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
// 开机引导  通信
const uint16_t font_boot_Communication
{
	/*通信*/
};
// 开机引导  请打开手机蓝牙连接
const uint16_t font_boot_phone_to_connect
{
	/*请打开手机蓝牙连接*/
};
// 开机引导  连接后 可通过手表进行通话
const uint16_t font_boot_connected_Communication
{
	/*连接后，可通过手表进行通话*/
};
// 开机引导  通信中
const uint16_t font_boot_communicating
{
	/*通信中*/
};
// 开机引导  语言选择 确认 long 
const uint16_t font_boot_language_confirm_long
{
	/*将语言设为简体中文？*/
};
// 开机引导  使用 H Band
const uint16_t font_boot_use_hband
{
	/*使用 H Band*/
};
// 开机引导  使用 H Band long
const uint16_t font_boot_use_hband_long
{
	/*通过 H Band 查看健康状态，管理穿戴设备。*/
};
// 开机引导  H Band
const uint16_t font_boot_hband
{
	/*H Band*/
};
// 开机引导  H Band 忽略 配对
const uint16_t font_boot_ignorepair
{
	/*忽略*/
	/*配对*/
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
// 开机引导  连接成功
const uint16_t font_boot_connected
{
	/*连接成功*/
};
// 开机引导  下载 H Band
const uint16_t font_boot_download
{
	/*使用手机扫码下载 H Band，并配对手表：*/
};
// 开机引导  关于设备
const uint16_t font_boot_about
{
	/*关于设备*/
};
// 开机引导  设备名称
const uint16_t font_boot_name
{
	/*设备名称*/
};
// 开机引导  配对成功
const uint16_t font_boot_pair_success
{
	/*配对成功*/
};

// 主界面  表盘传输中
const uint16_t font_main_in_transit
{
	/*关机*/
	/*表盘传输中*/
	/*取消*/
};

// 下拉  静音模式
const uint16_t font_down_muit
{
	/*取消*/
	/*开启*/
	/*继续*/
	/*通信*/
	/*免打扰*/
	/*通信中*/
	/*通信已连接*/
	/*断开连接*/
};
// 下拉  静音模式 long 
const uint16_t font_down_muit_long
{
	/*免打扰模式开启后将不会振动提醒，是否开启？*/
	/*通信状态下，耳机将暂停使用，是否继续？*/
	/*通信状态下，音乐将暂停播放，是否继续？*/
	/*请通过手机蓝牙连接*/
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
	/*天气*/
	/*拨号*/
	/*联系人*/
	/*通话记录*/
	/*消息*/
	/*闹钟*/
	/*秒表*/
	/*计时器*/
	/*音乐*/
	/*找手机*/
	/*女性*/
	/*相机*/
	/*计算器*/
	/*语音助手*/
	/*设置*/
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
	/*登山*/
	/*舞蹈*/
	/*瑜伽*/
	/*HIIT*/
	/*跳绳*/
	/*攀岩*/
	/*竞技*/
	/*球类*/
	/*健身游戏*/
	/*健身*/
	/*自由活动*/
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
//运动 结束提示 long 
const uint16_t font_sport_end_tips_long
{
	/*确认结束运动？*/
};
//运动 确认结束
const uint16_t font_sport_end_of_confirmation
{
	/*确认结束运动？*/
	/*继续*/
	/*结束*/
};
//运动 数据不足
const uint16_t font_sport_no_data
{
	/*无数据*/
};
//运动 单位
const uint16_t font_sport_unit
{
	/*千卡*/
	/*次/分*/
	/*步*/
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
	/*h*/
	/*m*/
	/*深睡*/
	/*浅睡*/
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
	/*点击下方按钮开始测量*/
};
//血压无数据 
const uint16_t font_Blood_Nodata
{
	/*暂无数据*/
};
//血压  开始
const uint16_t font_BP_last_not_wear_tips_en
{
	/*血压*/
	/*开始*/
};

//血压  测试中
const uint16_t font_BP_testing
{
	/*血压*/
	/*测量中*/
};
//血压  测试中 long 
const uint16_t font_BP_testing_long
{
	/*请保持静止并戴紧手表*/
};
//血压  失败
const uint16_t font_BP_fail
{
	/*血压*/
	/*测量失败*/
	/*重试*/
};
//血压  失败 long 
const uint16_t font_BP_fail_long
{
	/*请保持静止并戴紧手表*/
};
//血压  成功
const uint16_t font_BP_success
{
	/*血压*/
	/*测量成功*/
	/*mmHg*/
	/*重试*/
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
	/*请打开 H Band 获取天气*/
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
	/*无消息*/
};

//历史消息 删除
const uint16_t font_history_message_display
{
	/*消息*/
	/*删除*/
};
//历史消息 清除确认
const uint16_t font_history_message_clear_enter
{
	/*消息*/
	/*是否删除消息？*/
	/*取消*/
	/*删除*/
};

//闹钟
const uint16_t font_alarm_add
{
	/*闹钟*/
};
//闹钟 long
const uint16_t font_alarm_add_long
{
	/*请通过 H Band 添加闹钟*/
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
};
//闹钟
const uint16_t font_alarm_display
{
	/*稍后提醒*/
	/*关闭*/
};
//秒表
const uint16_t font_Stopwatch
{
	/*秒表*/
};


//计时器 计时中
const uint16_t font_timering
{
	/*计时器*/
	/*还原*/
	/*暂停*/
};	
//计时器 暂停
const uint16_t font_timer_paused
{
	/*还原*/
	/*继续*/
	/*开始*/
};
//计时器 结束
const uint16_t font_timer_end
{
	/*计时器*/
	/*计时完成*/
	/*重复*/
};

//音乐
const uint16_t font_music
{
	/*音乐*/
	/*暂无音乐*/
	/*音量*/
	/*设置*/
};
//音乐 long
const uint16_t font_music_long
{
	/*请连接手机*/
	/*请通过 USB 添加音乐*/
	/*正在获取歌曲信息*/
	/*信息获取失败*/
};
//音乐 播放模式
const uint16_t font_music_mode
{
	/*顺序播放*/
	/*单曲播放*/
	/*随机播放*/
};
//音乐 音乐类型
const uint16_t font_music_class
{
	/*设置*/
	/*手机音乐*/
	/*手表音乐*/
	/*蓝牙耳机*/
};
//音乐 状态
const uint16_t font_state
{
	/*未连接*/
	/*已连接*/
	/*搜索*/
	/*搜索中*/
	/*未发现蓝牙耳机*/
	/*重试*/
	/*搜索完成*/
	/*连接中*/
	/*连接失败*/
	/*已连接*/
	/*连接*/
	/*断开连接*/
	/*取消配对*/
	/*连接已断开*/
	/*配对已取消*/
};

//语音助手
const uint16_t font_voice
{
	/*语音助手*/
	/*连接中*/
	/*连接失败*/
	/*我在听...*/
	/*蓝牙信号弱*/
};
//语音助手
const uint16_t font_voice_long
{
	/*使用此功能，耳机将暂停使用。是否继续？*/
};


//相机
const uint16_t font_camera_disconnect
{
	/*相机*/
	/*摇一摇*/
	/*蓝牙未连接*/	
};

//找手机 蓝牙未连接
const uint16_t font_find_phone_disconnect
{
	/*找手机*/
	/*蓝牙未连接*/
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
	/*亮度调节*/
	/*亮屏时长*/
	/*开关设置*/
	/*下载 H Band*/
	/*表盘设置*/
	/*消息设置*/
	/*语言设置*/
	/*关于设备*/
	/*清除数据*/
	/*关机*/
};

//设置-
const uint16_t font_switch_setting
{
	/*心率监测*/
	/*血压监测*/
	/*心率警报*/
	/*断连提醒*/
	/*翻腕亮屏*/
	/*久坐提醒*/

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

//消息设置 清除数据
const uint16_t font_erase
{
	/*取消*/
	/*清除*/

};
//消息设置 清除数据
const uint16_t font_erase_long
{
	/*清除后，所有数据将无法恢复，是否清除？*/
};
//消息设置 清除数据
const uint16_t font_setting_tips
{
	/*电量过低*/
	/*起来活动啦！*/
	/*蓝牙断开*/
	/*恭喜你完成目标*/
};


//系统设置
const uint16_t font_system_settings
{
	/*系统设置*/
	/*设备名称*/
	/*关于设备*/
	/*MAC*/
	/*版本*/
	/*BT_V*/
	/*清除数据*/
	/*关机*/
	/*连接新手机*/
};

//连接新手机
const uint16_t font_connect_a_new_phone
{
	/*继续*/
	/*取消*/
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

//起来活动啦！
const uint16_t font_sedentary
{
	/*起来活动啦！*/
};


//来电
const uint16_t font_call
{
	/*拨号*/
	/*联系人*/
	/*通话记录*/
	/*无记录*/
	/*音量*/
	/*未知号码*/
	/*连接中*/
	/*挂断*/
	/*接听*/
	/*连接失败*/
	/*请在手机上接听*/
	/*拨号中*/
	/*静音*/
	/*已静音*/
	/*取消静音*/
	/*蓝牙信号弱*/
	/*已挂断*/
	/*取消*/
	/*继续*/
};
//来电
const uint16_t font_call_long
{
	/*此功能需要连接手机蓝牙使用，是否进入通信模式？*/
	/*使用此功能，音乐将暂停播放。是否继续？*/
	/*使用此功能，耳机将暂停使用。是否继续？*/
	/*请通过 H Band 添加常用联系人*/
};
//来电提示
const uint16_t font_call
{

	/*已静音*/
	/*已挂断*/
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


