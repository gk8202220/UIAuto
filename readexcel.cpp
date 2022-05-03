#include "readexcel.h"
#include <QDebug>
readexcel::readexcel(QObject *parent)
	: QObject(parent)
{
}

readexcel::~readexcel()
{
}

void readexcel::read(QString file, QList<QList<QVariant> >& res)
{
	QAxObject* excel = NULL;
	QAxObject* workbooks = NULL;
	QAxObject* workbook = NULL;
	excel = new QAxObject(this);
	excel->setControl("Excel.Application");
	if (!excel) {
		//QMessageBox::critical(NULL, "错误信息", "EXCEL对象丢失");
		qDebug("EXCEL对象丢失");
		return;
	}

	excel->dynamicCall("SetVisible(bool)", false);
	workbooks = excel->querySubObject("WorkBooks");
	workbook = workbooks->querySubObject("Open(const QString&)", file);
	QAxObject* worksheet = workbook->querySubObject("WorkSheets(int)", 2); // 获取第一个工作sheet  

	//QAxObject* usedrange1 = worksheet->querySubObject("UsedRange");//获取该sheet的使用范围对象  
	//QAxObject* usedrange = usedrange1->querySubObject("Range(const QString&)", "CF18");
	//QAxObject* rows = usedrange->querySubObject("Rows");
	//QAxObject* columns = usedrange->querySubObject("Columns");
	///*获取行数和列数*/
	//int intCols = columns->property("Count").toInt();
	//int intRows = rows->property("Count").toInt();
	//int intRowStart = usedrange->property("Row").toInt();
	//int intColStart = usedrange->property("Column").toInt();
	//QVariant xls_data = usedrange->dynamicCall("Value");

	QVariant var;
	if (worksheet != NULL && !worksheet->isNull())
	{
		QAxObject* usedRange = worksheet->querySubObject("UsedRange");
		if (NULL == usedRange || usedRange->isNull())
		{
			qDebug() << "null worksheet!";
		}
		var = usedRange->dynamicCall("Value");
		delete usedRange;
	}
	//QList<QList<QVariant> > res;
	castVariant2ListListVariant(var, res);
	
	// 关闭文件
	workbook->dynamicCall("Close()");
	// 关闭excel
	excel->dynamicCall("Quit()");
	delete excel;
	excel = nullptr;

	/////*获取excel内容*/
	//for (int i = intRowStart; i < intRowStart + intRows; i++)  //行
	//{
	//	for (int j = intColStart; j < intColStart + intCols; j++)
	//	{
	//		QAxObject* cell = worksheet->querySubObject("Cells(int,int)", i, j);
	//		QString value = cell->dynamicCall("Value2()").toString();
	//		qDebug() << value;
	//		//setItemValue(i - 1, j - 1, value);
	//		delete cell;
	//	}
	//}
}
void readexcel::castVariant2ListListVariant(const QVariant& var, QList<QList<QVariant> >& res)
{
	QVariantList varRows = var.toList();
	if (varRows.isEmpty())
	{
		return;
	}
	const int rowCount = varRows.size();
	QVariantList rowData;
	for (int i = 0; i < rowCount; ++i)
	{
		rowData = varRows[i].toList();
		//qDebug() << rowData;
		res.push_back(rowData);
	}
}
