#include "CodeJson.h"
#include "Language.h"
#include "WatchView.h"
/*
* 创建时间： 2022-05-04
* 作者：朱振展
* 描述: 1.用于将手表的界面参数生成json格式，
* 2.解析json文件显示手表的界面
* 
*/
CodeJson::CodeJson(QObject *parent)
	: QObject(parent)
{
}

CodeJson::~CodeJson()
{
}

void CodeJson::FontParamToJson(QMap<QString, ComponnetsItem> *items_map)
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
	Language *language = Language::GetInstance();
	QJsonObject page_obj;
	QString page = "界面";// font_page->Page;
	if (language_root_obj.contains(page))
	{
		page_obj = language_root_obj.value(page).toObject();
	}

	QJsonObject item_obj;
	for each (QString  id in items_map->keys())
	{
		/* 获取每一个控件*/
		ComponnetsItem item = items_map->value(id);
		QString item_fomat = item.fomat; //类型
		//QJsonObject item_obj;
		if (item_fomat == COMPONNET_FORMAT_TEXT)
		{
			/*文本*/
			QJsonObject item_text_obj;
			QStringList text_id = item.element_list;
			int width = item.size.width();
			int height = item.size.height();
			int x = item.point.x();
			int y = item.point.y();
			int font_size = item.font.param.font_size; //文字大小
			QString font_family = item.font.param.family;
			/*  每个具体的国家需要的参数：x, y, font_size, lingHeight*/
			//if (item.text_point.contains(current_lan))
			item_text_obj.insert("id", id);
			item_text_obj.insert("width", width);
			item_text_obj.insert("height", height);
			item_text_obj.insert("x", x);
			item_text_obj.insert("y", y);
			item_text_obj.insert("font_size", font_size);
			item_text_obj.insert("font_family", font_family);
			QJsonObject all_lan_text_obj;
			for each (Language_e current_lan in item.text_point.keys())
			{
				//如果当前的语言有对应的坐标
				language_offset text_point;
				text_point = item.text_point.value(current_lan);
				int x = text_point.x;
				int y = text_point.y;
				int lineHeight = text_point.lineHeight;
				int spacing = text_point.spacing;
				QStringList text_list = language->GetText(text_id, current_lan);
				QJsonArray text_array = QJsonArray::fromStringList(text_list);
				QJsonObject lan_text_obj;
				lan_text_obj.insert("lineHeight", lineHeight);
				lan_text_obj.insert("spacing", spacing);
				lan_text_obj.insert("x", x);
				lan_text_obj.insert("y", y);
				lan_text_obj.insert("text", text_array);
				QString lan_str = language->LanToString(current_lan);
				all_lan_text_obj.insert(lan_str, lan_text_obj);
			}
			
			item_text_obj.insert("language", all_lan_text_obj);
			//item_obj.insert("Text", item_text_obj);
			item_obj.insert("Text:"+ id, item_text_obj);
			
			
			/* 一个控件ID 对应QStringList ,一个QString 有相对应的多国语言 */
		}
		else if (item_fomat == COMPONNET_FORMAT_BETTARY)
		{
			QJsonObject item_label_obj;
			QStringList element_list = item.element_list;
			int width = item.size.width();
			int height = item.size.height();
			int x = item.point.x();
			int y = item.point.y();
			item_label_obj.insert("id", id);
			item_label_obj.insert("width", width);
			item_label_obj.insert("height", height);
			item_label_obj.insert("x", x);
			item_label_obj.insert("y", y);
			QJsonArray element_arry;
			for each (QString element in element_list)
			{
				element_arry.append(element);
			}
			item_label_obj.insert("element", element_arry);
			item_obj.insert("Bettary" + id, item_label_obj);
		}

	}
	qDebug() << item_obj;
}
