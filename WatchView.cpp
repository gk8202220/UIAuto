#pragma execution_character_set("UTF-8")
#include "WatchView.h"

WatchView::WatchView(QObject *parent)
	: QObject(parent)
{
	 component_list = { "背景", "文本", "电池","时" ,"分", "秒" ,"年","月" ,"日","星期","心率","卡路里",\
	"睡眠", "血压","里程", "步数", "蓝牙","按钮","标签" };
	 component_id_list = { COMPONNET_FORMAT_BG, COMPONNET_FORMAT_TEXT,COMPONNET_FORMAT_BETTARY,COMPONNET_FORMAT_HOUR,\
		COMPONNET_FORMAT_MINUTE, COMPONNET_FORMAT_SECOND, COMPONNET_FORMAT_YEAR, COMPONNET_FORMAT_MONTH, COMPONNET_FORMAT_DAY,\
		COMPONNET_FORMAT_WEEK, COMPONNET_FORMAT_HEART, COMPONNET_FORMAT_CALORIES,\
		COMPONNET_FORMAT_SLEEP, COMPONNET_FORMAT_BP, COMPONNET_FORMAT_DISTANCE, COMPONNET_FORMAT_STEP, COMPONNET_FORMAT_BLE, COMPONNET_FORMAT_BUTTON, COMPONNET_FORMAT_LABEL };
	 int count = component_list.size();
	 for (int i = 0; i < count; i++)
	 {
		 componnet_id_map.insert(component_list.at(i), component_id_list.at(i));
	 }
	 qDebug() << componnet_id_map;
	 digit_string_map.insert(0, "个位数");
	 digit_string_map.insert(1, "十位数");
	 digit_string_map.insert(2, "百位数");
	 digit_string_map.insert(3, "千位数");
	 digit_string_map.insert(4, "万位数");
}

WatchView::~WatchView()
{
}

int WatchView::Height(QString id)
{
	SetCurrentItem(id);
	return current_item->size.height();
}

int WatchView::Width(QString id)
{
	SetCurrentItem(id);
	return  current_item->size.width();
}

int WatchView::FontSize(QString id)
{
	SetCurrentItem(id);
	return current_item->font.param.font_size;
}

int WatchView::Spacing(QString id)
{
	SetCurrentItem(id);
	return current_item->font.param.spacing;
}

int WatchView::LineHeight(QString id)
{
	SetCurrentItem(id);
	return current_item->font.param.lineHeight;
}

int WatchView::X(QString id)
{
	//SetCurrentItem(id);
	QPoint point = GetPoint(id);
	return point.x();
}

int WatchView::Y(QString id)
{
	SetCurrentItem(id);
	return current_item->point.y();
	
}

int WatchView::interval(QString id)
{
	SetCurrentItem(id);
	return current_item->interval;
}

QString WatchView::Fomat(QString id)
{
	SetCurrentItem(id);
	return current_item->fomat;
}

QStringList WatchView::GetElementList(QString id)
{
	SetCurrentItem(id);
	return current_item->element_list;
}


void WatchView::SetCurrentItem(QString id)
{
	view_items_map = &Page_view_items_map.value(current_page_id);

	if (view_items_map->contains(id))
	{
		current_item = &view_items_map->value(id);
	}
	

}

COMPONNET_TYPE_E WatchView::Type(QString id)
{
	COMPONNET_TYPE_E type = COMPONNET_TYPE_GENERAL;
	QString fomat = this->Fomat(id);
	if (fomat == COMPONNET_FORMAT_TEXT)
	{
		type = COMPONNET_TYPE_TEXT;

	}
	else if (fomat == COMPONNET_FORMAT_CALORIES || fomat == COMPONNET_FORMAT_HOUR || fomat == COMPONNET_FORMAT_MINUTE
		|| fomat == COMPONNET_FORMAT_SECOND || fomat == COMPONNET_FORMAT_YEAR || fomat == COMPONNET_FORMAT_MONTH
		|| fomat == COMPONNET_FORMAT_DAY || fomat == COMPONNET_FORMAT_BP || fomat == COMPONNET_FORMAT_STEP
		|| fomat == COMPONNET_FORMAT_HEART || fomat == COMPONNET_FORMAT_DISTANCE
		|| fomat == COMPONNET_FORMAT_SLEEP)
	{
		type = COMPONNET_TYPE_NUMBER;
	}
	return type;
}


QPoint WatchView::GetPoint(QString id, Language_e lan)
{
	SetCurrentItem(id);
	QPoint point;
	if (current_item->fomat == "Text")
	{
		if (current_item->text_point.contains(lan))
		{
			//如果当前的语言有对应的坐标
			language_offset	text_point = current_item->text_point.value(lan);
			point.setX(text_point.x);
			point.setY(text_point.y);

			//      qDebug() << "id" << id << "updata" << text_point.x << current_lan;
		}
		else
		{
			
			point = current_item->point;
		}
	}
	else
	{
		point = current_item->point;
	}
	
	return point;
}

QPoint WatchView::GetPoint(QString id)
{
	SetCurrentItem(id);
	QPoint point = current_item->point;
	return point;
}

QMap<int, QPoint>* WatchView::GetPoints(QString id)
{
	SetCurrentItem(id);
	return &current_item->points;
}

QString WatchView::GetPriview(QString id)
{
	SetCurrentItem(id);
	return current_item->current_element;
}

QString WatchView::Family(QString id)
{
	SetCurrentItem(id);
	return current_item->font.param.family;
}

void WatchView::AppendItem(QString id, ComponnetsItem item)
{
	view_items_map = &Page_view_items_map.value(current_page_id);
	view_items_map->insert(id, item);
}

QMap<int, QStringList>* WatchView::GetElementLists(QString id)
{
	SetCurrentItem(id);
	return &current_item->element_lists;
}



QStringList *WatchView::GetViewId(QString page_id)
{
	if (SelectPage(page_id))
	{
		return &view_items_map->keys();
	}
	return nullptr;
	
}

bool WatchView::contains(QString id)
{
	return view_items_map->contains(id);
}

ComponnetsItem WatchView::GetCurrentItem(QString id)
{
	return view_items_map->value(id);
}

int WatchView::Count()
{
	if (view_items_map == nullptr)
	{
		return 0;
	}
	view_items_map = &Page_view_items_map.value(current_page_id);
	
	int count = view_items_map->count();
	qDebug() << count;
	return count;
}

QString WatchView::GetComponnetType(QString type)
{
	return componnet_id_map.value(type);
}

bool WatchView::SelectPage(QString page_id)
{
	current_page_id = page_id;
	if (!Page_view_items_map.isEmpty())
	{
		if (Page_view_items_map.contains(page_id))
		{
			view_items_map = &Page_view_items_map.value(page_id);
		
			return true;
		}
		
	}
	return false;
}

bool WatchView::AppendPage()
{
	QMap<QString, ComponnetsItem> view_items;
	
	int count = Page_view_items_map.count() + 1;
	QString page_id = QString::number(count);
	current_page_id = page_id;
	Page_view_items_map.insert(page_id,  view_items);
	return SelectPage(page_id);
}

bool WatchView::RemovePage(QString page_id)
{
	if (!Page_view_items_map.isEmpty())
	{
		if (Page_view_items_map.contains(page_id))
		{
			Page_view_items_map.remove(page_id);
			return true;
		}

	}
	return false;
}

QString WatchView::CurrentPageId()
{
	return current_page_id;
}

QMap<QString, ComponnetsItem>* WatchView::GetPage(QString page_id)
{
	SelectPage(page_id);
	return view_items_map;
}

int WatchView::Digit(QString fomat)
{
	int digit = 2;
	if (fomat == COMPONNET_FORMAT_HOUR || fomat == COMPONNET_FORMAT_MINUTE
		|| fomat == COMPONNET_FORMAT_SECOND || fomat == COMPONNET_FORMAT_DAY
		 || fomat == COMPONNET_FORMAT_MONTH)
	{
		digit = 2;
	}
	else if (fomat == COMPONNET_FORMAT_BP || fomat == COMPONNET_FORMAT_HEART
		|| fomat == COMPONNET_FORMAT_DISTANCE
		|| fomat == COMPONNET_FORMAT_SLEEP)
	{
		digit = 3;
	}
	else if (fomat == COMPONNET_FORMAT_CALORIES || fomat == COMPONNET_FORMAT_YEAR)
	{
		digit = 4;
	}
	else if (fomat == COMPONNET_FORMAT_STEP)
	{
		digit = 5;
	}
	return digit;
}

QString WatchView::DigitToString(int digit)
{
	return digit_string_map.value(digit);
}

int WatchView::DigitToInt(QString digit)
{
	
	return digit_string_map.key(digit);
}
