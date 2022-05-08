#pragma execution_character_set("UTF-8")
#include "WatchView.h"

WatchView::WatchView(QObject *parent)
	: QObject(parent)
{
	 component_list = { "背景", "文本", "电池","时" , tr("秒") ,"年","月" ,"日","星期","心率","卡路里",\
	"睡眠", "血压","里程", "蓝牙","按钮","标签" };
	 component_id_list = { COMPONNET_FORMAT_BG, COMPONNET_FORMAT_TEXT,COMPONNET_FORMAT_BETTARY,COMPONNET_FORMAT_HOUR,\
		COMPONNET_FORMAT_MINUTE, COMPONNET_FORMAT_SECOND, COMPONNET_FORMAT_YEAR, COMPONNET_FORMAT_MONTH, COMPONNET_FORMAT_DAY,\
		COMPONNET_FORMAT_WEEK, COMPONNET_FORMAT_HEART, COMPONNET_FORMAT_CALORIES,\
		COMPONNET_FORMAT_SLEEP, COMPONNET_FORMAT_BP, COMPONNET_FORMAT_DISTANCE, COMPONNET_FORMAT_BLE, COMPONNET_FORMAT_BUTTON, COMPONNET_FORMAT_LABEL };
	 int count = component_list.size();
	 for (int i = 0; i < count; i++)
	 {
		 componnet_id_map.insert(component_list.at(i), component_id_list.at(i));
	 }
}

WatchView::~WatchView()
{
}

int WatchView::Height(QString id)
{
	SetCurrentItem(id);
	return current_item.size.height();
}

int WatchView::Width(QString id)
{
	SetCurrentItem(id);
	return  current_item.size.width();
}

int WatchView::FontSize(QString id)
{
	SetCurrentItem(id);
	return current_item.font.param.font_size;
}

int WatchView::Spacing(QString id)
{
	SetCurrentItem(id);
	return current_item.font.param.spacing;
}

int WatchView::LineHeight(QString id)
{
	SetCurrentItem(id);
	return current_item.font.param.lineHeight;
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
	return current_item.point.y();
	
}

QString WatchView::Fomat(QString id)
{
	SetCurrentItem(id);
	return current_item.fomat;
}

QStringList WatchView::GetElementList(QString id)
{
	SetCurrentItem(id);
	return current_item.element_list;
}

void WatchView::SetItem(ComponnetsItem item)
{
	current_item = item;
}

void WatchView::SetCurrentItem(QString id)
{
	if (view_items_map.contains(id))
	{
		current_item = view_items_map.value(id);
	}

}


QPoint WatchView::GetPoint(QString id, Language_e lan)
{
	SetCurrentItem(id);
	QPoint point;
	if (current_item.fomat == "Text")
	{
		if (current_item.text_point.contains(lan))
		{
			//如果当前的语言有对应的坐标
			language_offset	text_point = current_item.text_point.value(lan);
			point.setX(text_point.x);
			point.setY(text_point.y);

			//      qDebug() << "id" << id << "updata" << text_point.x << current_lan;
		}
		else
		{
			
			point = current_item.point;
		}
	}
	else
	{
		point = current_item.point;
	}
	
	return point;
}

QPoint WatchView::GetPoint(QString id)
{
	SetCurrentItem(id);
	QPoint point = current_item.point;
	return point;
}

QString WatchView::GetPriview(QString id)
{
	SetCurrentItem(id);
	return current_item.current_element;
}

QString WatchView::Family(QString id)
{
	SetCurrentItem(id);
	return current_item.font.param.family;
}

void WatchView::AppendItem(QString id, ComponnetsItem item)
{
	view_items_map.insert(id, item);
}

QStringList WatchView::GetViewId()
{
	return view_items_map.keys();
}

bool WatchView::contains(QString id)
{
	return view_items_map.contains(id);
}

ComponnetsItem WatchView::GetCurrentItem(QString id)
{
	return view_items_map.value(id);
}

int WatchView::Count()
{
	return view_items_map.count();
}

QString WatchView::GetComponnetType(QString type)
{
	return componnet_id_map.value(type);
}
