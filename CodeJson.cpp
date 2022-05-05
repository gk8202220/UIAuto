#include "CodeJson.h"
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
	QJsonObject page_obj;
	QString page = "界面";// font_page->Page;
	if (language_root_obj.contains(page))
	{
		page_obj = language_root_obj.value(page).toObject();
	}

	QJsonObject text_obj;
	for each (QString  id in items_map->keys())
	{
		/* 获取每一个控件*/
		ComponnetsItem item = items_map->value(id);
		QString item_fomat = item.fomat; //类型
		if (item_fomat == "Text")
		{
			/*文本*/
			QString text = item.text; 
			int width = item.size.width();
			int height = item.size.height();
			int x = item.point.x();
			int y = item.point.y();
			int font_size = item.font.param.font_size; //文字大小
			QString font_family = item.font.param.family;
			/*  每个具体的国家需要的参数：x, y, font_size, lingHeight*/

			/* 一个控件ID 对应QStringList ,一个QString 有相对应的多国语言*/
		}
	}
	
}
