#include "WatchView.h"

WatchView::WatchView(QObject *parent)
	: QObject(parent)
{
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

QStringList WatchView::GetTextList(QString id)
{
	SetCurrentItem(id);
	return current_item.texts;
}

void WatchView::SetItem(ComponnetsItem item)
{
	current_item = item;
}

void WatchView::SetCurrentItem(QString id)
{
	if (view_items_map->contains(id))
	{
		current_item = view_items_map->value(id);
	}

}

void WatchView::SetView(QMap<QString, ComponnetsItem> *items_map)
{
	view_items_map = items_map;
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

QString WatchView::GetPriviewText(QString id)
{
	SetCurrentItem(id);
	return current_item.text;
}

QString WatchView::Family(QString id)
{
	SetCurrentItem(id);
	return current_item.font.param.family;
}
