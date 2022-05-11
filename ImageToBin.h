#pragma once

#include <QObject>
#include <QMap>
//位图文件头数据
typedef struct _BITMAP_FILE_HEADER {
	uint16_t signature;			//00~01:文件头签名字节,仅检测'BM'序
	uint32_t file_size;			//02~05:整个文件的大小
	uint32_t _reserved1;			//06~09:保留4字节,必须为0
	uint32_t data_offset;			//0A~0D:位图数据距文件开始的偏移
}BITMAP_FILE_HEADER;

//图像信息头数据
typedef struct _BITMAP_INFO_HEADER {
	uint32_t header_size;			//0E~11:位图信息头的长度,根据文件判断
	uint32_t width;				//12~15:位图宽度,像素为单位
	uint32_t height;				//16~19:位图高度,像素为单位
	unsigned short planes;				//1A~1B:位图的面数,该值总是1
	unsigned short bpp;					//1C~1D:位深:1,4,8,16,24,32
	unsigned long compress;				//1E~21:压缩说明
	unsigned long data_size;			//22~25:数据大小
	unsigned long hresolution;			//26~29:水平分辨率
	unsigned long vresolution;			//2A~2D:垂直分辨率
	unsigned long colors;				//2E:31:使用的颜色数
	unsigned long colors_important;		//重要的颜色数
}BITMAP_INFO_HEADER;

//颜色表
typedef struct _RGBQUAD {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
	unsigned char _reserved;
}BITMAP_RGB_QUAD;

//由图像信息头+颜色表组成的图像信息
typedef struct _BITMAP_INFO {
	BITMAP_INFO_HEADER bmih;
	BITMAP_RGB_QUAD bmcolor;
}BITMAP_INFO;

typedef struct
{
	uint16_t r;
	uint16_t g;
	uint16_t b;
	uint16_t a;
}RGBAUnit;
typedef struct
{
	int address;
	uint8_t linePointCount;//这一行颜色点的总数
	uint8_t xCoord;  //起始x的位置

}ZZPictureLine;  //一行的数据
typedef struct
{
	int length;
	uint8_t startLine;  //起始行
	uint8_t totalLinesCount; //总的行数
	QList<ZZPictureLine> lines;
	QByteArray allDatas;

}ZZPicture;

typedef enum
{
	RGBA5658,  //小端字节
	RGBA8888,
	BRGBA5658, // 大端字节 进行4字节转换


}COLOR_FORMAT;
typedef struct
{
	int width;
	int height;
	int size;
	QString name;

}image_info_t;
class BMPtobin : public QObject
{
	Q_OBJECT

public:
	BMPtobin(QObject *parent);
	~BMPtobin();
	static image_info_t OpenBmp(QString fileName, QByteArray* data, COLOR_FORMAT color_format);
	static image_info_t OpenPngToDial(QString fileName, QByteArray* data, COLOR_FORMAT color_format); //png指针转bin
	static QByteArray Convert32to16ZZ(QByteArray sourceBytes, int width, int height, COLOR_FORMAT color_format, bool addAlpha = false);
	static image_info_t OpenAlpha(QString fileName, QByteArray* data, COLOR_FORMAT color_format);
private:
//	QMap<QString, QString>Image_Path_Map; //图片命名和路径


};
