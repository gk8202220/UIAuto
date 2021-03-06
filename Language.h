#pragma once

#include <QObject>
#include <QJsonObject>
#include <QPainter>
typedef struct
{
    uint8_t        alignment;      //对齐方式   0左对齐   1居中      其他:右对齐
    int              x;            //起始y坐标
    int              y;            //起始y坐标
    uint16_t       height;         //高度
    uint16_t       width;          //宽度
    bool           middle;         //搭配居中时使用

    uint16_t       color;          //文字颜色
    uint16_t       backcolor;      //背景颜色
    bool           show_bg;        //背景融合
    uint8_t        font_size;      //字号  
    QString        family;         //字体
    uint8_t        spacing;        //文字间隔
    uint8_t        lineHeight;     //行间隔
}font_param_t;
typedef struct
{
    uint16_t x;
    uint16_t y;
    //QString text;
    uint8_t spacing;        //文字间隔
    //uint8_t font_size;      //字号  
    uint8_t lineHeight;     //行间隔
   
}language_offset;
typedef struct
{
    language_offset chinese;           //中文
    language_offset enaglish;          //英文
    language_offset japanese;          //日语
    language_offset korean;            //韩语
    language_offset german;            //德语
    language_offset russian;           //俄语
    language_offset spanish;           //西班牙语
    language_offset italiarn;          //意大利语
    language_offset french;            //法语
    language_offset vietnamese;        //越南语
    language_offset portuguese_pt;        //葡萄牙语 葡萄牙
    language_offset portuguese_br;        //葡萄牙语  巴西
    language_offset traditional;       //繁体
    language_offset polish;            //波兰语
    language_offset czech;             //捷克语
    language_offset ukraine;           //乌克兰
    language_offset hungary;           //匈牙利
    language_offset turkey;            //土耳其
    language_offset indonesia;         //印度尼西亚
    language_offset romania;           //罗马尼亚
    language_offset slovakia;          //斯洛伐克
    language_offset croatia;           //克罗地亚
    language_offset lithuania;         //立陶宛
    language_offset greece;            //希腊
    language_offset arae;              //阿拉伯
    language_offset sv;              //瑞典
    language_offset nlnl;              //荷兰
}font_coodr;
typedef struct
{
    //int id;  
    font_param_t param;
    QString title;
    QString id;
    
}font_t;

typedef enum
{
    chinese,           //中文
    enaglish,          //英文
    japanese,          //日语
    korean,            //韩语
    german,            //德语
    russian,           //俄语
    spanish,           //西班牙语
    italiarn,          //意大利语
    french,            //法语
    vietnamese,        //越南语
    portuguese_pt,        //葡萄牙语 葡萄牙
    portuguese_br,        //葡萄牙语  巴西
    traditional,       //繁体
    polish,            //波兰语
    czech,             //捷克语
    ukraine,           //乌克兰
    hungary,           //匈牙利
    turkey,            //土耳其
    indonesia,         //印度尼西亚
    romania,           //罗马尼亚
    slovakia,          //斯洛伐克
    croatia,           //克罗地亚
    lithuania,         //立陶宛
    greece,            //希腊
    arae,              //阿拉伯
    sv,              //瑞典
    nlnl,              //荷兰
    MAX_LANGUAGE,     //最大的
}Language_e;

typedef struct
{
    QString Page; //界面
    QString title; //标题选项
    QString text; //文字

}Font_page_t;

class Language : public QObject
{
	Q_OBJECT
private:
    QMap<QString, QJsonObject> language_file;
    QStringList lang_file_list;
    QString language_path; //路径
    QJsonObject language_root_obj; // 所有参数的json文件对象
    QString language_json_file_path; // 所有参数的json文件对象
    void SaveJsonFile(); //保持json文件
    QStringList language_type_list = { "chinese", "enaglish", "japanese", "korean", "german", "russian", "spanish",
"italiarn", "french", "vietnamese", "portuguese_pt", "portuguese_br", "traditional,"
"polish", "czech", "ukraine", "hungary", "turkey", "indonesia", "romania", "slovakia", "croatia",
"lithuania", "greece", "arae", "sv", "nlnl", };
    QList<QList<QVariant> > language_excel_list;
    Language_e lan_type;
public:
	//Language(QObject *parent);
	~Language();
    static Language* GetInstance()
    {
        //if (instance == nullptr)
        //{
        static Language instance;
            //instance = new Language();
       // }
        return &instance;
    }
	QJsonObject GetTextAarry(QString file_path); //从文件中获取文字
    void GenerateCode(font_t* font);
    void TextGenerateImage(QString text, int font_size, QString font_family, QString file_name); //文字生成切图
    void TextGenerateImage(QStringList text_list, int font_size, QString font_family); //文字生成切图
    void SetLanguageFile(QString file_path); //设置语言文件
    QJsonObject GetLanuageFile(Language_e lan); //获取语言文件

    void FontParamToJson(QMap<Language_e, font_t>* language_font_map, Font_page_t* font_page); //文字的参数转化为json的格式
    void SetParamJsonFile(QString path); //设置参数的json文件有些已经制作好的，可以直接读取
    void DarwText(QPainter* painter, font_t* font_text); //绘制文字
    
    void CalculatePoint(font_t font, QMap<Language_e, font_t> *language_font_map);
    font_t* GetParam(Language_e language);
    QMap<Language_e, font_t> language_font_map; //语言和对应文字的参数
    void GetPageFontParam(QMap<Language_e, font_t>* language_font_map, Font_page_t* font_page); //从json中过去界面的参数

    void SetLanguageFileExcel(QString excel_file); //读取翻译文件,来自excel表格
    QStringList text_id_list; //所有文字的ID列表
    QMap<QString, QMap<Language_e, QString> >id_texts_map; //ID和对应的所有国家文字
    QRect GetTextRect(QString text, int font_size, QString font_family); //获取文本的范围
    QString GetText(QString id, Language_e lan); //通过ID和对应的语言获取到文字
    QStringList GetText(QStringList id_list, Language_e lan); //通过ID和对应的语言获取到文字
    QString GetText(QString id);
    QStringList GetText(QStringList id_list); //通过ID和对应的语言获取到文字
    void SetLanguage(Language_e lan); //设置语言
    QString LanToString(Language_e lan); //获取对应的字符串
   
};
