#pragma once

#include <QObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonObject>
#include "ComponnetsItem.h"
#include "VpWatchCode.h"
#include "ImageBinFun.h"
class CodeJson : public QObject
{
	Q_OBJECT

public:
	CodeJson(QObject *parent);
	~CodeJson();
	void FontParamToJson(QMap<QString, ComponnetsItem> *items_map);
	QJsonObject language_root_obj; // ���в�����json�ļ�����
	void JsonToCode(QJsonObject language_root_obj);
	QString GetCode();
	QString GetCodeAddrArry();
private:
	QString GenerateCode(QString type, QStringList element_list);
	
	VpWatchCode* vpWatchCode;
	QString code_string;
	QString code_addr_arry;
	ImageBinFun* imageBinFun;
};
