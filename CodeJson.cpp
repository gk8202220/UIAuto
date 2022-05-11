#include "CodeJson.h"
#include "Language.h"
#include "WatchView.h"
#include "Utils.h"

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
	vpWatchCode = VpWatchCode::getInstance();
	imageBinFun = new ImageBinFun();
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
	code_string.clear();
	code_addr_arry.clear();
	Language *language = Language::GetInstance();
	QJsonArray page_obj;
	QString page = "����";// font_page->Page;
	if (language_root_obj.contains(page))
	{
		page_obj = language_root_obj.value(page).toArray();
	}

	//QJsonObject item_obj;
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
			item_text_obj.insert("format", item_fomat);
			//item_obj.insert("Text", item_text_obj);
			//page_obj.("Text:"+ id, item_text_obj);
			page_obj.append(item_text_obj);
			
			/* һ���ؼ�ID ��ӦQStringList ,һ��QString �����Ӧ�Ķ������ */
		}
		else //if (item_fomat == COMPONNET_FORMAT_BETTARY)
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
			item_label_obj.insert("format", item_fomat);
			//page_obj.insert("Bettary" + id, item_label_obj);
			page_obj.append(item_label_obj);
			code_string+=GenerateCode(item_fomat, element_list);
			//��ȡ�����б�
			vpWatchCode->GenerateAddrArry(element_list);
			//·����ȡ����
			QStringList name_list = Utils::GetBaseName(element_list);
			QStringList title_list;
			title_list = imageBinFun->GetImageTitleList(name_list);
			//���ɵ�ַ����
			code_addr_arry += vpWatchCode->GenerateAddrArry(title_list);
		}
		
	}
	
	//page_obj.insert("����", item_obj);
	language_root_obj.insert("����", page_obj);
	
	qDebug() << code_string;
	//JsonToCode(language_root_obj);
	
}

void CodeJson::JsonToCode(QJsonObject language_root_obj)
{
	for each (QString page in language_root_obj.keys())
	{
		QJsonArray Page_Obj = language_root_obj.value(page).toArray();
		int  length = Page_Obj.count();
		for (size_t i = 0; i < length; i++)
		{
			
			QJsonObject element_obj = Page_Obj.at(i).toObject();
			for each (QString var in element_obj.keys())
			{
				qDebug() << var << element_obj.value(var);
			} ;
		/*	if (item == "format")
			{
				qDebug() << value.toString();
			}
			else if (item == "format")
			{

			}*/
		}
	}
	
}

QString CodeJson::GenerateCode(QString type, QStringList element_list)
{
	QString code;
	if (element_list.isEmpty())return code;
	QString path  = element_list.at(0);
	QString image_name = Utils::GetBaseName(path);
	//ͨ���ļ���ȡ����
	IMAGE_FORMAT image_format;
	QString title = imageBinFun->getImageFormat(image_name, &image_format);
	if(type == COMPONNET_FORMAT_BG)
	{				
		code = vpWatchCode->UI_one(title, element_list.count());
	}
	else if (type == COMPONNET_FORMAT_BETTARY)
	{
		code = vpWatchCode->UI_one(title, element_list.count());
	}
	else if (type == COMPONNET_FORMAT_CALORIES)
	{
		code = vpWatchCode->UI_calories(title);
	}
	else if (type == COMPONNET_FORMAT_HOUR)
	{
		code = vpWatchCode->UI_time(title);
	}
	else if (type == COMPONNET_FORMAT_MINUTE)
	{
		code = vpWatchCode->UI_time(title);
	}
	else if (type == COMPONNET_FORMAT_SECOND)
	{
		code = vpWatchCode->UI_time(title);
	}
	else if (type == COMPONNET_FORMAT_YEAR)
	{
		code = vpWatchCode->UI_data(title);
	}
	else if (type == COMPONNET_FORMAT_MONTH)
	{
		code = vpWatchCode->UI_data(title);
	}
	else if (type == COMPONNET_FORMAT_DAY)
	{
		code = vpWatchCode->UI_data(title);
	}
	else if (type == COMPONNET_FORMAT_WEEK)
	{
		code = vpWatchCode->UI_week(title);
	}
	else if (type == COMPONNET_FORMAT_HEART)
	{
		code = vpWatchCode->UI_heart(title);
	}
	else if (type == COMPONNET_FORMAT_SLEEP)
	{
		code = vpWatchCode->UI_Sleep(title);
	}
	else if (type == COMPONNET_FORMAT_BP)
	{
		code = vpWatchCode->UI_BP(title);
	}
	else if (type == COMPONNET_FORMAT_DISTANCE)
	{
		code = vpWatchCode->UI_distance(title);
	}
	else if (type == COMPONNET_FORMAT_BLE)
	{
		code = vpWatchCode->UI_blue(title);
	}
	else if (type == COMPONNET_FORMAT_BUTTON)
	{
		code = vpWatchCode->UI_one(title, element_list.count());
	}
	else if (type == COMPONNET_FORMAT_LABEL)
	{
		code = vpWatchCode->UI_one(title, element_list.count());
	}
	

	return code;

}

QString CodeJson::GetCode()
{
	
	return code_string;
}

QString CodeJson::GetCodeAddrArry()
{
	return code_addr_arry;
}
