#include "CodeJson.h"
/*
* ����ʱ�䣺 2022-05-04
* ���ߣ�����չ
* ����: 1.���ڽ��ֱ�Ľ����������json��ʽ��
* 2.����json�ļ���ʾ�ֱ�Ľ���
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
	//json�ĸ�ʽ��ʽ
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
	QString page = "����";// font_page->Page;
	if (language_root_obj.contains(page))
	{
		page_obj = language_root_obj.value(page).toObject();
	}

	QJsonObject text_obj;
	for each (QString  id in items_map->keys())
	{
		/* ��ȡÿһ���ؼ�*/
		ComponnetsItem item = items_map->value(id);
		QString item_fomat = item.fomat; //����
		if (item_fomat == "Text")
		{
			/*�ı�*/
			QString text = item.text; 
			int width = item.size.width();
			int height = item.size.height();
			int x = item.point.x();
			int y = item.point.y();
			int font_size = item.font.param.font_size; //���ִ�С
			QString font_family = item.font.param.family;
			/*  ÿ������Ĺ�����Ҫ�Ĳ�����x, y, font_size, lingHeight*/

			/* һ���ؼ�ID ��ӦQStringList ,һ��QString �����Ӧ�Ķ������*/
		}
	}
	
}
