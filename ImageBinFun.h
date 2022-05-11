#pragma once
#include <QString.h>
#include <QMap>
#include <QJsonObject>
#include "ImageToBin.h"
#define  H02Q_UI 0  //如果H02Q 需要预留FD000的4K空间和先合成UI再合成字库
typedef enum
{
	IMAGE_FORMAT_DIAL,  //表盘指针
	IMAGE_FORMAT_BMP, //正常bmp图片
	IMAGE_FORMAT_ALPHA, //  只获取alpha值


}IMAGE_FORMAT;
typedef enum
{
	COMPRESS_NULL,  //不压缩压缩
	COMPRESS_MINIZLO,  //minilzo压缩
	COMPRESS_VEEPOO, //维亿魄压缩
	COMPRESS_MINIZLO_BLOCK,  //minilzo压缩

}COMPRESS_FORMAT; //压缩方法
typedef struct
{
	QString ui_bin_path;
	QString ui_head_path;

}ui_path_t;
class ImageBinFun
{
public:
	ImageBinFun();
	void titletobmpbin(QString titile);
	 void saveBmpPaths(QString path); //遍历目录下的切图并保存到QMap
	QStringList titleList;  //同一切图类型的头
	void SetCompress(COMPRESS_FORMAT format); //设置压缩
	void SetColorFormat(COLOR_FORMAT format); //设置4字节倒换
	void GetUiPath(ui_path_t *path);
	QString getImageFormat(QString image_file_name, IMAGE_FORMAT* image_format); //获取图片的类型
	QStringList GetImageTitleList(QStringList Images);
	
private:
	QMap<QString, QString>Image_Path_Map; //图片命名和路径
	
	QByteArray bmpbin; //图片保存成bin
	QJsonObject Title_Image_json;  //保存标题和对应的所有切图
	
	IMAGE_FORMAT image_format;
	int image_addr_count; //记录图片文件的地址
	int test_conut = 0;
	QString gui_flash_addr; //切图地址和大小信息
	QString gui_flash_size_array; //切图地址和大小信息
	QString gui_flash_size_array_head; //切图地址和大小信息
	COMPRESS_FORMAT gui_is_compress;  //是否进行压缩
	void getBmpPaths(QString path);  //遍历目录下的切图

	void jsonfile(QString file);
	image_info_t getImageBinForFormat(IMAGE_FORMAT image_format, QString icon_name); //分类型转为bin
	void SameImageSave(QStringList imageList, QString last_image_title);

	bool minilzo_init(void); 
	QByteArray vp_compress(QByteArray src); //veepoo 压缩算法
	QByteArray vp_decompress(QByteArray dst); //veepoo 压缩算法解压
	QByteArray minilzo_compress(QByteArray src); //minilzo 压缩算法
	void minilzo_compressBlock(QByteArray src, image_info_t* image_info, QByteArray *dst); //minilzo  分块压缩算法
	QByteArray minilzo_decompressBlock(QByteArray src, image_info_t* image_info); //minilzo 分块解缩算法
	QByteArray minilzo_decompress(QByteArray src); // //minilzo 解缩算法
	void PrintDialAddr(QList<image_info_t> image_info_list); //打印指针的地址信息
	void PrintImageAddr(QList<image_info_t> image_info_list); //打印图片的地址信息
	void PrintPngAddr(QList<image_info_t> image_info_list);
	COLOR_FORMAT color_format; //进行4字节倒换
	QByteArray minilzo_GetBolckDate(image_info_t* image_info, int start_y, int date_size, QByteArray dst);
		
	QString gui_addr_bin_path; //切图生成UI的bin文件路径
	QString gui_addr_head_path; //切图生成UI的头文件文件路径



};

