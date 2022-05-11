#pragma once
#include <QString.h>
#include <QMap>
#include <QJsonObject>
#include "ImageToBin.h"
#define  H02Q_UI 0  //���H02Q ��ҪԤ��FD000��4K�ռ���Ⱥϳ�UI�ٺϳ��ֿ�
typedef enum
{
	IMAGE_FORMAT_DIAL,  //����ָ��
	IMAGE_FORMAT_BMP, //����bmpͼƬ
	IMAGE_FORMAT_ALPHA, //  ֻ��ȡalphaֵ


}IMAGE_FORMAT;
typedef enum
{
	COMPRESS_NULL,  //��ѹ��ѹ��
	COMPRESS_MINIZLO,  //minilzoѹ��
	COMPRESS_VEEPOO, //ά����ѹ��
	COMPRESS_MINIZLO_BLOCK,  //minilzoѹ��

}COMPRESS_FORMAT; //ѹ������
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
	 void saveBmpPaths(QString path); //����Ŀ¼�µ���ͼ�����浽QMap
	QStringList titleList;  //ͬһ��ͼ���͵�ͷ
	void SetCompress(COMPRESS_FORMAT format); //����ѹ��
	void SetColorFormat(COLOR_FORMAT format); //����4�ֽڵ���
	void GetUiPath(ui_path_t *path);
	QString getImageFormat(QString image_file_name, IMAGE_FORMAT* image_format); //��ȡͼƬ������
	QStringList GetImageTitleList(QStringList Images);
	
private:
	QMap<QString, QString>Image_Path_Map; //ͼƬ������·��
	
	QByteArray bmpbin; //ͼƬ�����bin
	QJsonObject Title_Image_json;  //�������Ͷ�Ӧ��������ͼ
	
	IMAGE_FORMAT image_format;
	int image_addr_count; //��¼ͼƬ�ļ��ĵ�ַ
	int test_conut = 0;
	QString gui_flash_addr; //��ͼ��ַ�ʹ�С��Ϣ
	QString gui_flash_size_array; //��ͼ��ַ�ʹ�С��Ϣ
	QString gui_flash_size_array_head; //��ͼ��ַ�ʹ�С��Ϣ
	COMPRESS_FORMAT gui_is_compress;  //�Ƿ����ѹ��
	void getBmpPaths(QString path);  //����Ŀ¼�µ���ͼ

	void jsonfile(QString file);
	image_info_t getImageBinForFormat(IMAGE_FORMAT image_format, QString icon_name); //������תΪbin
	void SameImageSave(QStringList imageList, QString last_image_title);

	bool minilzo_init(void); 
	QByteArray vp_compress(QByteArray src); //veepoo ѹ���㷨
	QByteArray vp_decompress(QByteArray dst); //veepoo ѹ���㷨��ѹ
	QByteArray minilzo_compress(QByteArray src); //minilzo ѹ���㷨
	void minilzo_compressBlock(QByteArray src, image_info_t* image_info, QByteArray *dst); //minilzo  �ֿ�ѹ���㷨
	QByteArray minilzo_decompressBlock(QByteArray src, image_info_t* image_info); //minilzo �ֿ�����㷨
	QByteArray minilzo_decompress(QByteArray src); // //minilzo �����㷨
	void PrintDialAddr(QList<image_info_t> image_info_list); //��ӡָ��ĵ�ַ��Ϣ
	void PrintImageAddr(QList<image_info_t> image_info_list); //��ӡͼƬ�ĵ�ַ��Ϣ
	void PrintPngAddr(QList<image_info_t> image_info_list);
	COLOR_FORMAT color_format; //����4�ֽڵ���
	QByteArray minilzo_GetBolckDate(image_info_t* image_info, int start_y, int date_size, QByteArray dst);
		
	QString gui_addr_bin_path; //��ͼ����UI��bin�ļ�·��
	QString gui_addr_head_path; //��ͼ����UI��ͷ�ļ��ļ�·��



};

