#include "Language.h"
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <QPixmap>
#include <QPainter>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QJsonParseError>
#include "readexcel.h"
void Language::SaveJsonFile()
{
	
	QJsonDocument doc;
	doc.setObject(language_root_obj);
	if (language_json_file_path.isEmpty())
	{
		language_json_file_path = language_path.append("/language_param.json");
	}
	
	QFile file(language_json_file_path);
	if (!file.open(QIODevice::WriteOnly))
	{
		qDebug() << "open file error!" << language_json_file_path;
		return;
	}
	file.write(doc.toJson());
	file.close();
}
//Language::Language(QObject *parent)
//	: QObject(parent)
//{
//	 lang_file_list = {"param_zh_cn.c","param_en.c","param_ja.c", "param_ko.c",  "param_de_de.c","param_ru.c", 
//								 "param_es_es.c","param_it_it.c","param_fr_fr.c","param_pt_pt.c","param_zh_hk.c" ,"param_pl.c","param_tur.c",
//								 "param_cs.c","param_hu.c","param_el.c","param_ro.c","param_sk.c","param_id.c","param_pt_br.c",
//								 "param_hr.c","param_lt.c","param_uk.c","param_ar_ae.c","param_vi.c" };
//	 language_type_list = { "chinese", "enaglish", "japanese", "korean", "german", "russian", "spanish",
//"italiarn", "french", "vietnamese", "portuguese_pt", "portuguese_br", "traditional,"
//"polish", "czech", "ukraine", "hungary", "turkey", "indonesia", "romania", "slovakia", "croatia",
//"lithuania", "greece", "arae", "sv", "nlnl", };
//
//}

Language::~Language()
{
}

QJsonObject Language::GetTextAarry(QString file_path)
{
	QJsonObject AllTextJsonObject;
	QFile file(file_path);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "open file error!" << file_path;
		//return o;
	}
	QString text_key;
	QJsonArray text_array;
	
	
	while (!file.atEnd())
	{
		QByteArray file_data = file.readLine();
		QString current_text(file_data);
		if (current_text.contains("const"))
		{
			//获取当前的翻译项
			QStringList text_split = current_text.split(" ");
			if (text_split.size() > 2)
			{
				//qDebug() << text_split[2];
				text_key = text_split[2];
			}
			

			
		}
		else if (current_text.contains("/*"))
		{
			//具体文本内容
			QStringList text_split = current_text.split("*");
			if (text_split.size() > 2)
			{
				//qDebug() << text_split[1];
				QString text = text_split[1];
				text_array.append(text);
			}
		}
		else if (current_text.contains("};"))
		{
			//结束当前的翻译项
			AllTextJsonObject.insert(text_key, text_array);
			//清空数组
			int size = text_array.size();
			for (int i = 0; i < size; i++)
			{
				text_array.removeFirst();
			}
		}
	}
	qDebug() << AllTextJsonObject.keys();
	return AllTextJsonObject;
}
void Language::GenerateCode(font_t *font)
{
	//QString code_str;
	//code_str.append("void  ");
	//code_str.append(font->title);
	//code_str.append("(void)");
	//code_str.append("{");
	//code_str.append("	//偏移结构体");
	//code_str.append("font_offset  coord = {");
	//code_str.append("	.chinese = {0,0}");
	//code_str.append("};");
	//	
	////显示参数结构体
	//code_str.append("multilanguage_word_wrap_t currency_word_warp_s =");
	//code_str.append("{");
	//		
	//code_str.append(".line_spacing = "+QString::number(1) + ",     //换行间距");
	//code_str.append(".invl = 0,     //文字间隔");
	//code_str.append(".show_bg = false,     //背景融合");
	//	

	//code_str.append("};");
	//code_str.append("uint16_t color[] = //字库颜色表");
	//code_str.append("{");
	//code_str.append("LCD_COLOR_WHITE,");
	//code_str.append("};");
	//code_str.append("language_offset coord = language_get_offset(offset);");
	//code_str.append("currency_word_warp_s.start_x = coord.offset_x;");
	//code_str.append("currency_word_warp_s.start_y = coord.offset_y;");

	//code_str.append("currency_word_warp_s.color = color[0];");

	//code_str.append("Font_ShowString(&currency_word_warp_s, font_boot_setting_for_hband_addr(0));");

}

void Language::TextGenerateImage(QString text, int font_size, QString font_family, QString file_name)
{
	QFont font;
	font.setPixelSize(font_size);
	font.setFamily(font_family);
	QFontMetrics me(font);
	QRect rec = me.boundingRect(text);
	int label_h = rec.height();
	int label_w = rec.width();


	QPixmap pix(label_w, label_h);
	pix.fill(QColor(Qt::black));
	QPainter painter;
	
	painter.begin(&pix);
	if (!text.isEmpty())
	{

	
		painter.setPen(QColor(255, 255, 255));
		painter.setFont(font);
		painter.drawText(0, font_size - 2, text);
	}
	painter.end();
	pix.save(file_name);

}

void Language::TextGenerateImage(QStringList text_list, int font_size, QString font_family)
{
	int text_count = text_list.count();
	QString file_name = "./TextImage/icon_text_";
	for (int i = 0; i < text_count; i++)
	{
		file_name.append(QString::number(i));
		file_name.append(".bmp");
		TextGenerateImage(text_list.at(i), font_size, font_family, file_name);
	}
}

void Language::SetLanguageFile(QString file_path)
{
	//解析不同名字的语言文件，获取对象
	// for each (QString file  in file_path)
	
	{
	    QFileInfo lan_file(file_path);
		qDebug() << lan_file.fileName();
		language_path = lan_file.absolutePath();//保持语言文件的路径
		language_file.insert(lan_file.fileName(), this->GetTextAarry(file_path));
	}
	
}

QJsonObject Language::GetLanuageFile(Language_e lan)
{
	QString select =  lang_file_list.at(lan);
	qDebug() << select;
	return language_file.value(select);
}
#define KEY_FONT_SIZE			 "fontSize"
#define KEY_FONT_X				 "x"
#define KEY_FONT_Y				 "y"
#define KEY_FONT_WIDTH			 "width"
#define KEY_FONT_HEIGHT			 "height"
#define KEY_FONT_COLOR			 "color"
#define KEY_FONT_TEXT			 "text"
#define KEY_FONT_AlignMent		 "Alignment"
#define KEY_FONT_FAMILY			 "family"
#define KEY_FONT_LETTERSPACING   "letterSpacing" //字间隔
#define KEY_FONT_LINEHEIGHT		 "lineHeight" //行间隔
#define KEY_FONT_COLOR			 "color" //颜色
#define KEY_FONT_SHOWBG			 "showBg" //行间隔

void Language::FontParamToJson(QMap<Language_e, font_t> *language_font_map, Font_page_t* font_page)
{
	//json的格式形式
	/*
		title:{
			text: 
			{
				param:{
			     
					 }
				english:{
				}
				china:{
				}
				...
			}
			
		}
	language_root_obj ->page_obj -> text_obj
	*/
	QJsonObject page_obj;
	QString page = font_page->Page;
	if (language_root_obj.contains(page))
	{
		page_obj = language_root_obj.value(page).toObject();
	}

	QJsonObject text_obj;

	
	font_t font = language_font_map->value(chinese);
	QString title = font_page->title;
	QString text = font_page->text;
	
	
	if (page_obj.contains(title))
	{
		text_obj = page_obj.value(title).toObject();
	}

	//填写通用参数
	QJsonObject param_obj;
	if (text_obj.contains(text))
	{
		param_obj = text_obj.value(text).toObject();
	}

	font_coodr coodr;

	
	if (text_obj.contains("param"))
	{
		param_obj = text_obj.value("param").toObject();
	}

	bool show_bg = font.param.show_bg;
	int color = font.param.color;
	QString family = font.param.family;
	int font_size = font.param.font_size;
	QJsonObject global_param_obj;
	global_param_obj.insert(KEY_FONT_SHOWBG, show_bg);
	global_param_obj.insert(KEY_FONT_COLOR, color);
	global_param_obj.insert(KEY_FONT_FAMILY, color);
	global_param_obj.insert(KEY_FONT_SIZE, font_size);
	param_obj.insert("param", global_param_obj);
	QJsonObject language_coord_obj;
	for each (Language_e lan in language_font_map->keys())
	{

	
		/* 填写各个国家的位置 */
		QJsonObject coord_obj;
		font_param_t coodr = language_font_map->value(lan).param;
		QString language_type = language_type_list.at(lan);
		if (language_coord_obj.contains(language_type))
		{
			coord_obj = language_coord_obj.value(language_type).toObject();
		}
		int x = coodr.x;
		int y = coodr.y;
		qDebug() << x << y << text;
		int letterSpacing = coodr.spacing;
		int font_size = coodr.font_size;
		int lineHeight = coodr.lineHeight;
		coord_obj.insert(KEY_FONT_X, x);
		coord_obj.insert(KEY_FONT_Y, y);
		coord_obj.insert(KEY_FONT_SIZE, font_size);
		coord_obj.insert(KEY_FONT_LINEHEIGHT, lineHeight);
	
		if (letterSpacing != 0)
		{
			coord_obj.insert(KEY_FONT_LETTERSPACING, letterSpacing);
		}
	
		language_coord_obj.insert(language_type, coord_obj);



	}
	param_obj.insert("language", language_coord_obj);
	text_obj.insert(text, param_obj);
	page_obj.insert(title, text_obj);
	language_root_obj.insert(page, page_obj);
	qDebug() << language_root_obj;
	SaveJsonFile();
	
}

void Language::SetParamJsonFile(QString path)
{
	language_json_file_path = path;
	QFile file(path);
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "open file error!" << path;
		return;
	}
	QByteArray fileData = file.readAll();
	file.close();
	QJsonParseError  json_error;
	//json读取格式
	QJsonDocument json(QJsonDocument::fromJson(fileData, &json_error));
	if (json_error.error != QJsonParseError::NoError)
	{
		qDebug() << "json error!" << json_error.error;
		return;
	}
	language_root_obj = json.object();
}

void Language::DarwText(QPainter* painter, font_t* font_text)
{
	QFont font;
	QString draw_text = font_text->title;
	int x = font_text->param.x;
	int y = font_text->param.y;
	int font_size = font_text->param.font_size;
	QString family = font_text->param.family;
	font.setFamily(family);
	font.setPixelSize(font_size);
	font.setPixelSize(font_size);
	font.setFamily(family);
	QFontMetrics me(font);
	QRect rec = me.boundingRect(draw_text);
	y -= rec.y();
	if (!draw_text.isEmpty())
	{
		//int set_y = text_display.param.y + label_y;
		//paint.setPen(QColor(255, 255, 255));
		//paint.setFont(font);
		//paint.drawText(text_display.param.x + label_x, set_y, text_display.text);
		painter->setPen(QColor(255, 255, 255));
		painter->setFont(font);
		painter->drawText(x, y, draw_text);
		
		//painter->drawRect(x, y + rec.y(), rec.width(), rec.height());
	}
}


void Language::CalculatePoint(font_t font, QMap<Language_e, font_t>* language_font_map)
{
	/* 计算各个国家的位置*/
	for (int i = 0; i < 3 - 1; i++)
	{
		language_font_map->insert((Language_e)i, font);
	}
}

font_t* Language::GetParam(Language_e language)
{
	if (language_font_map.size() > 0)
	{
		return &language_font_map.value(language);
	}
	return nullptr;
}

void Language::GetPageFontParam(QMap<Language_e, font_t>* language_font_map, Font_page_t* font_page)
{

	QString page = font_page->Page;
	/*界面*/
	if (language_root_obj.contains(page))
	{
		QJsonObject page_obj;
		page_obj = language_root_obj.value(page).toObject();

		for each (QString title in page_obj.keys())
		{
			QJsonObject text_obj = page_obj.value(title).toObject();

			if (text_obj.contains("param"))
			{
				
				QJsonObject global_param_obj;
				QJsonObject param_obj = text_obj.value("param").toObject();
				bool show_bg = param_obj.value(KEY_FONT_SHOWBG ).toBool();
				int color = param_obj.value(KEY_FONT_COLOR).toInt();
				QString family = param_obj.value(KEY_FONT_FAMILY).toString();
				int font_size = param_obj.value(KEY_FONT_SIZE).toInt();

			/*	font.param.show_bg;
				font.param.color;
				font.param.family;
				font.param.font_size;*/
			}

		}


	}



}

void Language::SetLanguageFileExcel(QString excel_file)
{
	readexcel* excel = new readexcel(this);
	excel->read(excel_file, language_excel_list);
	//获取ID
	int row_count = language_excel_list.count(); //总行数
	for (int row = 0; row < row_count; row++)
	{
		//qDebug() << language_excel_list.at(row).at(1);
		//int count = language_excel_list.
		int column_count = language_excel_list.at(row).count();//总列数
		QString id = language_excel_list.at(row).at(0).toString();
		QMap<Language_e, QString> lan_text;
		for (int column = 1; column < column_count; column++)
		{
			QString text = language_excel_list.at(row).at(column).toString();
			Language_e lan = (Language_e)(column - 1);	
			lan_text.insert(lan, text);
		}
		id_texts_map.insert(id, lan_text);
		QString text = language_excel_list.at(row).at(1).toString();
		//id_text_map.insert(id, text);
		text_id_list.append(id);
		 
	}
	//获取中文
	qDebug() << id_texts_map.values();
}

QRect Language::GetTextRect(QString text, int font_size, QString font_family)
{
	QFont font;
	font.setPixelSize(font_size);
	font.setFamily(font_family);
	QFontMetrics me(font);
	QRect rec = me.boundingRect(text);
	int label_h = rec.height();
	int label_w = rec.width();
	return rec;
}

QString Language::GetText(QString id, Language_e lan)
{
	QString Text = id_texts_map.value(id).value(lan);
	return Text;
}

QStringList Language::GetText(QStringList id_list, Language_e lan)
{
	QStringList text_list;
	for each (QString id in id_list)
	{
		QString Text = id_texts_map.value(id).value(lan);
		text_list.append(Text);
	}
	return text_list;
}

QString Language::GetText(QString id)
{
	QString text = GetText(id, lan_type);
	return text;
}

void Language::SetLanguage(Language_e lan)
{
	lan_type = lan;
}

QString Language::LanToString(Language_e lan)
{
	QString language_type;
	if (lan < language_type_list.count())
	{
		language_type = language_type_list.at(lan);
	} 
	return language_type;
}

QStringList Language::GetText(QStringList id_list)
{
	QStringList text_list = GetText(id_list, lan_type);
	return text_list;
}



