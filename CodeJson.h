#pragma once

#include <QObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonObject>
#include "ComponnetsItem.h"
#include "VpWatchCode.h"
class CodeJson : public QObject
{
	Q_OBJECT

public:
	CodeJson(QObject *parent);
	~CodeJson();
	void FontParamToJson(QMap<QString, ComponnetsItem> *items_map);
	QJsonObject language_root_obj; // 所有参数的json文件对象
	void JsonToCode(QJsonObject language_root_obj);
	QString GetCode();
private:
	QString GenerateCode(QString type, QStringList element_list);
	
	VpWatchCode* vpWatchCode;
	QString code_string;
};
