#include "CodeJson.h"
#include "Language.h"
#include "WatchView.h"
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
	Language *language = Language::GetInstance();
	QJsonObject page_obj;
	QString page = "����";// font_page->Page;
	if (language_root_obj.contains(page))
	{
		page_obj = language_root_obj.value(page).toObject();
	}

	QJsonObject item_obj;
	for each (QString  id in items_map->keys())
	{
		/* ��ȡÿһ���ؼ�*/
		ComponnetsItem item = items_map->value(id);
		QString item_fomat = item.fomat; //����
		//QJsonObject item_obj;
		if (item_fomat == COMPONNET_FORMAT_TEXT)
		{
			/*�ı�*/
			QJsonObject item_text_obj;
			QStringList text_id = item.element_list;
			int width = item.size.width();
			int height = item.size.height();
			int x = item.point.x();
			int y = item.point.y();
			int font_size = item.font.param.font_size; //���ִ�С
			QString font_family = item.font.param.family;
			/*  ÿ������Ĺ�����Ҫ�Ĳ�����x, y, font_size, lingHeight*/
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
				//�����ǰ�������ж�Ӧ������
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
			
			
			/* һ���ؼ�ID ��ӦQStringList ,һ��QString �����Ӧ�Ķ������ */
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
