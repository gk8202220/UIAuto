#include "VpWatchCode.h"
#include <QDebug>
//VpWatchCode::VpWatchCode(QObject *parent)
//	: QObject(parent)
//{
//}

VpWatchCode::~VpWatchCode()
{
}

QString VpWatchCode::UI_time(QString title)
{
    QString code_text;
    code_text.append("\n//***** 时间 ****//");
    code_text.append(setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[hour / 10 % 10 % 3],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    code_text.append(setPostionFun + title.toLower() + "_coord[1][0],icon_16_" + title.toLower() + "_coord[1][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[hour % 10],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    code_text.append(setPostionFun + title.toLower() + "_coord[2][0],icon_16_" + title.toLower() + "_coord[2][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[minute / 10 % 6],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    code_text.append(setPostionFun + title.toLower() + "_coord[3][0],icon_16_" + title.toLower() + "_coord[3][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[minute % 10],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    return code_text;
}
QString VpWatchCode::UI_week(QString title, QString title_en)
{
    QString code_text;
    code_text.append("\n//***** 星期 ****//");
    code_text.append("if(language == 0)\n{");
    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[((week >= 1)?(week-1):week) % 7],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    code_text.append("}\nelse\n{");
    code_text.append("\t" + setPostionFun + title_en.toLower() + "_coord[0][0],icon_16_" + title_en.toLower() + "_coord[0][1],");
    code_text.append("\t\tICON_" + title_en.toUpper() + "_WIDE," + "ICON_" + title_en.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title_en.toLower() + "_addr[((week >= 1)?(week-1):week) % 7],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");
    return code_text;

}QString VpWatchCode::UI_week(QString title)
{
    QString code_text;
    code_text.append("\n//***** 星期 ****//");
    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[((week >= 1)?(week-1):week) % 7],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    return code_text;

}

//计步数
QString VpWatchCode::UI_Step(QString title)
{
    QString code_text;
    code_text.append("\n//***** 计步 ****//");
    if (CodeIsOld())
    {
        code_text.append("uint32_t step_temp = step_cnt;");
        code_text.append("if(step_temp > 99999)");
        code_text.append("{");
        code_text.append("   step_temp = 99999;");
        code_text.append("}");
        code_text.append("uint8_t step_data[5]= {0};");
        code_text.append("step_data[0] = (step_temp / 10000) %10;");
        code_text.append("step_data[1] = (step_temp / 1000) %10;");
        code_text.append("step_data[2] = (step_temp / 100) %10;");
        code_text.append("step_data[3] = (step_temp / 10) %10;");
        code_text.append("step_data[4] = step_temp  %10;");
    }

    code_text.append("for(uint8_t i = 0;i < 5; i++)");
    code_text.append("{");

    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[step_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");

    return code_text;
}

QString VpWatchCode::UI_blue(QString title)
{
    QString code_text;
    code_text.append("\n//***** 蓝牙 ****//");
    code_text.append(setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[ble_status % 2],ICON_" + title.toUpper() + "_SIZE);");
    return code_text;
}

QString VpWatchCode::UI_heart(QString title)
{
    QString code_text;
    QString dot;
 /*
 临时屏蔽
  for (int i = 0; i < iconTitleList.count(); i++)
    {

        QString name = iconTitleList.value(i);
        if (name.contains(title) && name.contains("DOT"))
        {
            dot = name;
        }
    }*/
    code_text.append("\n//***** 心率 ****//");

    code_text.append("uint8_t heart_tmp = heart;\n");
    code_text.append("if(heart_tmp == 0)\n{");
    code_text.append("\tfor(uint8_t i = 0;i<3;i++)");
    code_text.append("\t{");

    if (!dot.isEmpty())
    {
        //显示 ---
        code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
        code_text.append("\t\t\tICON_" + dot.toUpper() + "_WIDE," + "ICON_" + dot.toUpper() + "_HIGH);");
        code_text.append("\t\t" + WriteDataFun + dot.toLower() + "_addr[0],ICON_" + dot.toUpper() + "_SIZE);");

    }
    else {
        code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
        code_text.append("\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
        code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[0],ICON_" + title.toUpper() + "_SIZE);");


    }
    code_text.append("\t}");
    code_text.append("}");

    code_text.append("else\n{");
    if (CodeIsOld())
    {
        code_text.append("\tif(heart_tmp > 255)\n\t{\n\t\theart_tmp = 255;\n");
        code_text.append("\t}");

        code_text.append("\t\tuint8_t heart_data[3]= {0};");
        code_text.append("\t\theart_data[0] = (heart_tmp / 100) %10;");
        code_text.append("\t\theart_data[1] = (heart_tmp / 10) %10;");
        code_text.append("\t\theart_data[2] = heart_tmp %10;");
    }

    code_text.append("\tfor(uint8_t i = 0;i<3;i++)");
    code_text.append("\t{");
    code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[heart_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\t}");
    code_text.append("}");
    return code_text;

}

QString VpWatchCode::UI_data(QString title)
{
    QString code_text;
    code_text.append("\n//***** 月份 ****//");
    code_text.append(setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[month / 10 % 10],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    code_text.append(setPostionFun + title.toLower() + "_coord[1][0],icon_16_" + title.toLower() + "_coord[1][1],");
    code_text.append("\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[month % 10],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\n//*****day****//");
    code_text.append(setPostionFun + title.toLower() + "_coord[2][0],icon_16_" + title.toLower() + "_coord[2][1],");
    code_text.append("\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[day / 10 % 10],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    code_text.append(setPostionFun + title.toLower() + "_coord[3][0],icon_16_" + title.toLower() + "_coord[3][1],");
    code_text.append("\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append(WriteDataFun + title.toLower() + "_addr[day % 10],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("");
    return code_text;
}
//卡路里
QString VpWatchCode::UI_calories(QString title)
{
    QString code_text;
    code_text.append("\n/***** 卡路里 ****/");
    if (CodeIsOld())
    {

        code_text.append("uint32_t calories_temp = calories_cnt;");
        code_text.append("if(calories_temp > 9999)");
        code_text.append("{");
        code_text.append("   calories_temp = 9999;");
        code_text.append("}");
        code_text.append("uint8_t calories_data[4]= {0};");
        code_text.append("calories_data[0] = (calories_temp / 1000) %10;");
        code_text.append("calories_data[1] = (calories_temp / 100) %10;");
        code_text.append("calories_data[2] = (calories_temp / 10) %10;");
        code_text.append("calories_data[3] = calories_temp  %10;");
    }
    code_text.append("for(uint8_t i = 0;i < 4; i++)");
    code_text.append("{");
    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[calories_data[i] ],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");
    return code_text;
}
//里程
QString VpWatchCode::UI_distance(QString title)
{
    QString code_text;
    code_text.append("\n/***** 里程 ****/");
    if (CodeIsOld())
    {
        code_text.append("uint32_t distance_temp = 0;");
        code_text.append("\tif(distance_cnt >= 99.9f)\n\t{\n\tdistance_temp = 999;\n");
        code_text.append("\t}");
        code_text.append("\telse ");
        code_text.append("\t{");
        code_text.append("\t     distance_temp = (uint32_t)(distance_cnt* 10);");
        code_text.append("\t}");
        code_text.append("\tuint8_t distance_data[3]= {0};");
        code_text.append("\tdistance_data[0] = (distance_temp / 100) %10;");
        code_text.append("\tdistance_data[1] = (distance_temp / 10) %10;");
        code_text.append("\tdistance_data[2] = distance_temp %10;");
    }

    code_text.append("\tfor(uint8_t i = 0;i<3;i++)");
    code_text.append("\t{");
    code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\t\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[distance_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\t}");
    return code_text;

}

bool VpWatchCode::CodeIsOld()
{
    return false;
}

QString VpWatchCode::GenerateAddrArry(QStringList images)
{
    QString gui_flash_addr;
    for each (image_info_t image_info in images)
    {

        //qDebug() << "ICON_" + image_info.name.toUpper() + "_ADDR  " + QString::number(image_addr_count);
        gui_flash_addr.append("#define ICON_" + image_info.name.toUpper() + "_ADDR  " + QString::number(image_addr_count));
        gui_flash_addr.append("\n");
        //qDebug() << ">>>>>>>" << image_addr_count;
        image_addr_count += image_info.size;
    }
    return gui_flash_addr;
}


QString VpWatchCode::UI_AMPM(QString title)
{
    QString code_text;
    code_text.append("\n/***** 上下午 ****/");
    code_text.append("if(language == 0)");
    code_text.append("{");
    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");

    code_text.append("\tif(am_pm == GUI_TIME_FORMAT_AM)");
    code_text.append("\t{");
    code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[0],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\t}");
    code_text.append("\telse if(am_pm == GUI_TIME_FORMAT_PM)");
    code_text.append("\t{");
    code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[1],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\t}");
    code_text.append("\telse if(am_pm == GUI_TIME_FORMAT_STANDARD)");
    code_text.append("\t{");
    code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[4],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\t}");
    code_text.append("}");
    code_text.append("else");
    code_text.append("{");
    code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\tif(am_pm == GUI_TIME_FORMAT_AM)");
    code_text.append("\t{");
    code_text.append("\t\t\t" + WriteDataFun + title.toLower() + "_addr[2],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\t}");
    code_text.append("\telse if(am_pm == GUI_TIME_FORMAT_PM)");
    code_text.append("\t{");
    code_text.append("\t\t\t" + WriteDataFun + title.toLower() + "_addr[3],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\t}");
    code_text.append("\telse if(am_pm == GUI_TIME_FORMAT_STANDARD)");
    code_text.append("\t{");
    code_text.append("\t\t\t" + WriteDataFun + title.toLower() + "_addr[4],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("\t}");
    code_text.append("}");
    return code_text;

}

QString VpWatchCode::UI_one(QString title, int count)
{
    QString code_text;
    code_text.append("\n\t\t/*****" + title + " ****/");
    code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\t  ICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    if (count > 1)
    {
        //动图
        QString num1 = QString::number(count);
        code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[index % " + num1 + "],ICON_" + title.toUpper() + "_SIZE);\n");
    }
    else
    {
        code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[0],ICON_" + title.toUpper() + "_SIZE);\n");

    }

     return code_text;
}


QString VpWatchCode::UI_charge(QString title)
{
    QString code_text;
    code_text.append("\n/***** 充电 ****/");
    code_text.append("    if(charge == BATTERRY_IS_CHARGING)");
    code_text.append("    {");
    code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[index % 5],ICON_" + title.toUpper() + "_SIZE);\n");
    code_text.append("    }");
    code_text.append("    else");
    code_text.append("    {");
    code_text.append("        if(battery_level == 0)");
    code_text.append("        {");
    code_text.append("            if(index % 4 == 1)");
    code_text.append("            {");
    code_text.append("\t\t\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t\t\t" + WriteDataFun + title.toLower() + "_addr[0],ICON_" + title.toUpper() + "_SIZE);\n");
    code_text.append("            }");
    code_text.append("            else if(index % 4 == 3)");
    code_text.append("            {");
    code_text.append("\t\t\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t\t\t" + WriteDataFun + title.toLower() + "_addr[5],ICON_" + title.toUpper() + "_SIZE);\n");

    code_text.append("            }");
    code_text.append("        }");
    code_text.append("        else");
    code_text.append("        {");

    code_text.append("\t\t\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t\t\t" + WriteDataFun + title.toLower() + "_addr[battery_level],ICON_" + title.toUpper() + "_SIZE);\n");

    code_text.append("        }");
    code_text.append("    }");

    return code_text;
}

QString VpWatchCode::UI_uint(QString title)
{
    QString code_text;
    code_text.append("\n\t\t/***** 单位 ****/");
    code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\t  ICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[language % 2],ICON_" + title.toUpper() + "_SIZE);\n");
    return code_text;
}
QString VpWatchCode::UI_Women(QString title)
{
    QString code_text;
    code_text.append("\n\t\t/***** 女性 ****/");
    code_text.append("\t\t" + setPostionFun + title.toLower() + "_coord[0][0],icon_16_" + title.toLower() + "_coord[0][1],");
    code_text.append("\t\t\t\t  ICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t\t" + WriteDataFun + title.toLower() + "_addr[menstrual % 5],ICON_" + title.toUpper() + "_SIZE);\n");
    return code_text;
}
//血压
QString VpWatchCode::UI_BP(QString title)
{
    QString code_text;
    code_text.append("\n//***** 血压 ****//");
    code_text.append("uint8_t bp_data[6]= {0};");
    code_text.append("bp_data[0] = (bp_sp / 100)% 10;");
    code_text.append("bp_data[1] = (bp_sp / 10)% 10;");
    code_text.append("bp_data[2] =  bp_sp % 10;");

    code_text.append("bp_data[3] = (bp_dp / 100)% 10;");
    code_text.append("bp_data[4] = (bp_dp / 10)% 10;");
    code_text.append("bp_data[5] = bp_dp % 10;");

    code_text.append("for(uint8_t i = 0;i < 6; i++)");
    code_text.append("{");

    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[bp_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");
    return code_text;
}
//显示三位的睡眠
QString VpWatchCode::UI_Sleep(QString title)
{
    QString code_text;
    code_text.append("\n//***** 睡眠三位  ****//");
    code_text.append("uint8_t sleep_hours = time / 60;");
    code_text.append("uint8_t sleep_minutes = 10 * (time % 60 / 60.0f);");
    code_text.append("uint32_t disp_sleep_buf1 = sleep_hours*10 + sleep_minutes;");



    code_text.append("uint8_t light_sleep_hours = light_time / 60;");
    code_text.append("uint8_t light_sleep_minutes = 10 * (light_time % 60 / 60.0f);");
    code_text.append("uint32_t disp_light_sleep_buf1 = light_sleep_hours*10 + light_sleep_minutes;");


    code_text.append("uint8_t deep_sleep_hours = deep_time / 60;");
    code_text.append("uint8_t deep_sleep_minutes = 10 * (deep_time % 60 / 60.0f);");
    code_text.append("uint32_t disp_deep_sleep_buf1 = deep_sleep_hours*10 + deep_sleep_minutes;");

    code_text.append("if((disp_sleep_buf1 - disp_light_sleep_buf1 - disp_deep_sleep_buf1) != 0)");
    code_text.append("{");
    code_text.append("    disp_deep_sleep_buf1 = disp_sleep_buf1 - disp_light_sleep_buf1;");
    code_text.append("}");
    code_text.append("\n//***** Sleep ****//");
    code_text.append("uint8_t sleep_data[3]= {0};");
    code_text.append("sleep_data[0] = (disp_sleep_buf1 / 100)% 10;");
    code_text.append("sleep_data[1] = (disp_sleep_buf1 /10 )% 10;");

    code_text.append("sleep_data[2] = disp_sleep_buf1 % 10;");

    code_text.append("for(uint8_t i = 0;i < 3; i++)");
    code_text.append("{");

    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[sleep_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");

    code_text.append("\n//***** deep Sleep ****//");
    code_text.append("uint8_t deep_sleep_data[3]= {0};");
    code_text.append("deep_sleep_data[0] = (disp_deep_sleep_buf1 / 100)% 10;");
    code_text.append("deep_sleep_data[1] = (disp_deep_sleep_buf1 / 10) % 10;");

    code_text.append("deep_sleep_data[2] = disp_deep_sleep_buf1 % 10;");

    code_text.append("for(uint8_t i = 0;i < 3; i++)");
    code_text.append("{");

    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[deep_sleep_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");
    code_text.append("\n//***** light Sleep ****//");
    code_text.append("uint8_t light_sleep_data[3]= {0};");
    code_text.append("light_sleep_data[0] = (disp_light_sleep_buf1 / 100)% 10;");
    code_text.append("light_sleep_data[1] = (disp_light_sleep_buf1 / 10) % 10;");

    code_text.append("light_sleep_data[2] = disp_light_sleep_buf1  % 10;");

    code_text.append("for(uint8_t i = 0;i < 3; i++)");
    code_text.append("{");

    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[light_sleep_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");
    return code_text;
}
//显示4位的睡眠
QString VpWatchCode::UI_Sleep_4(QString title)
{
    QString code_text;
    code_text.append("\n//***** 睡眠 4位 ****//");
    if (CodeIsOld())
    {

        code_text.append("uint8_t sleep_hours = time / 60;");
        code_text.append("uint8_t sleep_minutes = time % 60;");
        code_text.append("uint8_t deep_sleep_hours = deep_time / 60;");
        code_text.append("uint8_t deep_sleep_minutes = deep_time % 60;");
        code_text.append("uint8_t light_sleep_hours = light_time / 60;");
        code_text.append("uint8_t light_sleep_minutes = light_time % 60;");


        code_text.append("uint8_t sleep_data[4]= {0};");
        code_text.append("sleep_data[0] = (sleep_hours / 10)% 10;");
        code_text.append("sleep_data[1] =  sleep_hours % 10;");
        code_text.append("sleep_data[2] = (sleep_minutes / 10)% 10;");
        code_text.append("sleep_data[3] = sleep_minutes % 10;");
    }

    code_text.append("for(uint8_t i = 0;i < 4; i++)");
    code_text.append("{");

    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[sleep_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");
    if (CodeIsOld())
    {
        code_text.append("\n//***** deep Sleep ****//");
        code_text.append("uint8_t deep_sleep_data[4]= {0};");
        code_text.append("deep_sleep_data[0] = (deep_sleep_hours / 10)% 10;");
        code_text.append("deep_sleep_data[1] =  deep_sleep_hours % 10;");
        code_text.append("deep_sleep_data[2] = (deep_sleep_minutes / 10)% 10;");
        code_text.append("deep_sleep_data[3] = deep_sleep_minutes % 10;");
    }
    code_text.append("for(uint8_t i = 0;i < 4; i++)");
    code_text.append("{");

    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[deep_sleep_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");

    if (CodeIsOld())
    {
        code_text.append("\n//***** light Sleep ****//");
        code_text.append("uint8_t light_sleep_data[4]= {0};");
        code_text.append("light_sleep_data[0] = (light_sleep_hours / 10)% 10;");
        code_text.append("light_sleep_data[1] =  light_sleep_hours % 10;");
        code_text.append("light_sleep_data[2] = (light_sleep_minutes / 10)% 10;");
        code_text.append("light_sleep_data[3] = light_sleep_minutes % 10;");
    }
    code_text.append("for(uint8_t i = 0;i < 4; i++)");
    code_text.append("{");

    code_text.append("\t" + setPostionFun + title.toLower() + "_coord[i][0],icon_16_" + title.toLower() + "_coord[i][1],");
    code_text.append("\t\tICON_" + title.toUpper() + "_WIDE," + "ICON_" + title.toUpper() + "_HIGH);");
    code_text.append("\t" + WriteDataFun + title.toLower() + "_addr[light_sleep_data[i]],ICON_" + title.toUpper() + "_SIZE);");
    code_text.append("}");
    return code_text;

}
