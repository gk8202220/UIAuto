#include "ImageSelectWidget.h"
#include <QDir>
#include <QAbstractItemModel>
#pragma execution_character_set("UTF-8")
void ImageSelectWidget::on_selected_image(const QModelIndex index)
{

	QModelIndexList select_list = ui.LV_Image_Browse->selectionModel()->selectedIndexes();
	int app_row = selected_image_model->rowCount();
	
	for each (QModelIndex index in select_list)
	{
		int row = index.row();
		QModelIndex name_index = ui.LV_Image_Browse->model()->index(row,0);
		QString  name = name_index.data().toString();
		QString image_path = current_path + "/" + name;
		//qDebug() << "on_selected_image" << name << row;
		if (selected_image_list->contains(image_path))
		{
			continue;
		}
		
		QFileInfo file_info(image_path);
		if (file_info.isFile())
		{
			selected_image_list->append(image_path);
			selected_image_model->appendRow(new QStandardItem(QIcon(image_path), name));

		}
		
	}
	ui.LV_Image_selected->setModel(selected_image_model);
}
void ImageSelectWidget::on_pb_confirm()
{
	if (mode == SELECT_MODE_CREAT)
	{
		emit create_image();
	}
	else
	{
		emit updata_image();
	}

	
	this->hide();
}
void ImageSelectWidget::on_item_up()
{
	//将项目下移
	QModelIndex cr_index = ui.LV_Image_selected->currentIndex();
	//selected_image_model.
	 	int currRow = cr_index.row();
	//int currentRow = ui.LV_Image_selected->currentIndex().row();
	QModelIndex sourceParent = ui.LV_Image_selected->model()->index(currRow, 0);
	QModelIndex destinationParent = ui.LV_Image_selected->model()->index(currRow + 1, 0);
	ui.LV_Image_selected->model()->moveRow(sourceParent, currRow, destinationParent, currRow + 1);
	
	//ui.LV_Image_selected->model()->moveRow(cr_index, cr_row, cr_index, cr_row + 1);
	//QAbstractItemModel::beginMoveRows(sourceParent, cr_row, cr_index, )

	//if (cr_index.isValid()) //判断非空，否则点击会出错
	//{
	//	//int currRow = ui->listWidget->currentRow();//获取当前行号
	//	int currRow = cr_index.row();
	//	QVariant selstr = cr_index.data();
	//	if (currRow > 0) //限制（上移至第0行终止）
	//	{
	//		 ui.LV_Image_selected->model()->removeRow(currRow);
	//	    	ui.LV_Image_selected->model()->insertRow(currRow - 1);//在上一行插入新行，内容为之前选中内容
	//	}
	//	//ui.LV_Image_selected->model()->setCurrent(currRow - 1);//将上移后的新行选中，实现连续上移
	//	//ui.LV_Image_selected->setCurrentIndex()
	//}
	
	
	
}
void ImageSelectWidget::on_item_dowm()
{
}
void ImageSelectWidget::on_delete_item(const QModelIndex index)
{
	//双击删除
	selected_image_list->remove(selected_image_list->indexOf(index.data().toString()));
	ui.LV_Image_selected->model()->removeRow(index.row());
}
ImageSelectWidget::ImageSelectWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	image_model = new QStandardItemModel();
	selected_image_model = new QStandardItemModel();
	ui.LV_Image_Browse->setIconSize(QSize(60, 60));
	ui.LV_Image_selected->setIconSize(QSize(60, 60));
}

ImageSelectWidget::~ImageSelectWidget()
{
}

void ImageSelectWidget::OpenPath(QString path)
{
	root_path = path;	
	SelectPath(root_path);
}

void ImageSelectWidget::setSelectedImage(QStringList* image_list)
{

	selected_image_list = image_list;
	selected_image_model->clear();
	if (selected_image_list->isEmpty())
	{
		return;
	}

	for each (QString image_path in *selected_image_list)
	{
		QFileInfo path_info(image_path);
		QString name = path_info.baseName();
		selected_image_model->appendRow(new QStandardItem(QIcon(image_path), name));

	}
	ui.LV_Image_selected->setModel(selected_image_model);
}

void ImageSelectWidget::SetMode(SELECT_MODE_T mode)
{
	this->mode = mode;
	if (mode == SELECT_MODE_CREAT)
	{
		ui.PB_Confirm->setText("创建");
	}
	else
	{
		ui.PB_Confirm->setText("确定");
	}
}

void ImageSelectWidget::SelectPath(QString path)
{
	current_path = path;
	QDir dir(path);
	image_model->clear();
	
	foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Files, QDir::DirsFirst))
	{
		if (fileInfo.isDir())
		{
			//目录遍历
			
			//qDebug() << fileInfo.absolutePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐"
			//qDebug() << fileInfo.filePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
			//qDebug() << fileInfo.fileName(); //"音乐音量"
			//qDebug() << fileInfo.baseName(); //"音乐音量"
			//qDebug() << fileInfo.absoluteFilePath();// "F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
			//qDebug() << fileInfo.path();// "F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐"
			//getBmpPaths(fileInfo.absoluteFilePath());
			//进行界面的显示
			//ui->LV_Image_Browse
			QString item_path = fileInfo.fileName();
			image_model->appendRow(new QStandardItem(item_path));
		}
		else {
			//qDebug() << fileInfo.filePath();
			//QImage image(fileInfo.filePath());
			if (fileInfo.suffix() == "bmp" || fileInfo.suffix() == "png")
			{
				QString icon_src = fileInfo.baseName();// .toUpper();q
				//qDebug() << fileInfo.absolutePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
				//qDebug() << fileInfo.filePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量/musicvu_icon1_mute.bmp"
				//qDebug() << fileInfo.fileName(); //"musicvu_icon1_mute.bmp"
				//qDebug() << fileInfo.baseName(); //"musicvu_icon1_mute"
				//qDebug() << fileInfo.absoluteFilePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量/musicvu_icon1_mute.bmp
			//	qDebug() << fileInfo.filePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
			//	qDebug() << "\n";
				//qDebug() << icon_src;
				//Image_Path_Map.insert(icon_src, fileInfo.filePath());
				QString image_name = fileInfo.fileName();
				QString image_path = fileInfo.absoluteFilePath();

				image_model->appendRow( new QStandardItem( QIcon(image_path), image_name));
				
			}		

		}
	}
	ui.LV_Image_Browse->setModel(image_model);
}

void ImageSelectWidget::on_select_item(const QModelIndex index)
{
	QString item = index.data().toString();
	QString current_select_path;
	if (item == "..")
	{
		//上一级
		QDir dir(current_path);
		if (dir.cdUp())
		{
			current_select_path = dir.absolutePath();
		}
		else
		{
			current_select_path = current_path;
		}
		
	}
	else if (item == ".")
	{
		current_select_path = root_path;
		

	}
	else
	{
		current_select_path = current_path + "/" + item;
		
	}
	QFileInfo file_info(current_select_path);
	if (file_info.isDir())
	{
		SelectPath(current_select_path);
	}
	qDebug() << current_select_path;
	
}