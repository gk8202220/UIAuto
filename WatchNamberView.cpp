#include "WatchNamberView.h"

WatchNamberView::WatchNamberView(QObject *parent)
	: QObject(parent)
{
}

WatchNamberView::~WatchNamberView()
{
}

int WatchNamberView::Height(QString id)
{
	SetCurrentItem(id);
	return current_item.size.height();
}

int WatchNamberView::Width(QString id)
{
	SetCurrentItem(id);
	return  current_item.size.width();
}



int WatchNamberView::X(QString id)
{
	//SetCurrentItem(id);
	QPoint point = GetPoint(id);
	return point.x();
}

int WatchNamberView::Y(QString id)
{
	SetCurrentItem(id);
	//return current_item.point.y();
	return 0;

}

QString WatchNamberView::Fomat(QString id)
{
	SetCurrentItem(id);
	return current_item.fomat;
}

QStringList WatchNamberView::GetElementList(QString id)
{
	SetCurrentItem(id);
	//return current_item.element_list;
	return QStringList();
}

void WatchNamberView::SetItem(NumberComponnetsItem item)
{
	//current_item = item;
}

void WatchNamberView::SetCurrentItem(QString id)
{
	if (view_number_items_map.contains(id))
	{
		current_item = view_number_items_map.value(id);
	}
	else if (view_number_items_map.contains(id))
	{

	}

}


QPoint WatchNamberView::GetPoint(QString id, Language_e lan)
{
	SetCurrentItem(id);
	QPoint point;

	return point;
}

QPoint WatchNamberView::GetPoint(QString id)
{
	SetCurrentItem(id);
	QPoint point;// = current_item.point;
	return point;
}

QString WatchNamberView::GetPriview(QString id)
{
	SetCurrentItem(id);
	//return current_item.current_element;
	return QString();
}



void WatchNamberView::AppendItem(QString id, NumberComponnetsItem item)
{
	view_number_items_map.insert(id, item);
}



QStringList WatchNamberView::GetViewId()
{
	return view_number_items_map.keys();
}

bool WatchNamberView::contains(QString id)
{
	return view_number_items_map.contains(id);
}

NumberComponnetsItem WatchNamberView::GetCurrentItem(QString id)
{
	return view_number_items_map.value(id);
}

int WatchNamberView::Count()
{
	return view_number_items_map.count();
}

QString WatchNamberView::GetComponnetType(QString type)
{
	//return componnet_id_map.value(type);
	return QString();
}
