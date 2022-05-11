#pragma once

#include <QObject>
#include <QMap>
//λͼ�ļ�ͷ����
typedef struct _BITMAP_FILE_HEADER {
	uint16_t signature;			//00~01:�ļ�ͷǩ���ֽ�,�����'BM'��
	uint32_t file_size;			//02~05:�����ļ��Ĵ�С
	uint32_t _reserved1;			//06~09:����4�ֽ�,����Ϊ0
	uint32_t data_offset;			//0A~0D:λͼ���ݾ��ļ���ʼ��ƫ��
}BITMAP_FILE_HEADER;

//ͼ����Ϣͷ����
typedef struct _BITMAP_INFO_HEADER {
	uint32_t header_size;			//0E~11:λͼ��Ϣͷ�ĳ���,�����ļ��ж�
	uint32_t width;				//12~15:λͼ���,����Ϊ��λ
	uint32_t height;				//16~19:λͼ�߶�,����Ϊ��λ
	unsigned short planes;				//1A~1B:λͼ������,��ֵ����1
	unsigned short bpp;					//1C~1D:λ��:1,4,8,16,24,32
	unsigned long compress;				//1E~21:ѹ��˵��
	unsigned long data_size;			//22~25:���ݴ�С
	unsigned long hresolution;			//26~29:ˮƽ�ֱ���
	unsigned long vresolution;			//2A~2D:��ֱ�ֱ���
	unsigned long colors;				//2E:31:ʹ�õ���ɫ��
	unsigned long colors_important;		//��Ҫ����ɫ��
}BITMAP_INFO_HEADER;

//��ɫ��
typedef struct _RGBQUAD {
	unsigned char blue;
	unsigned char green;
	unsigned char red;
	unsigned char _reserved;
}BITMAP_RGB_QUAD;

//��ͼ����Ϣͷ+��ɫ����ɵ�ͼ����Ϣ
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
	uint8_t linePointCount;//��һ����ɫ�������
	uint8_t xCoord;  //��ʼx��λ��

}ZZPictureLine;  //һ�е�����
typedef struct
{
	int length;
	uint8_t startLine;  //��ʼ��
	uint8_t totalLinesCount; //�ܵ�����
	QList<ZZPictureLine> lines;
	QByteArray allDatas;

}ZZPicture;

typedef enum
{
	RGBA5658,  //С���ֽ�
	RGBA8888,
	BRGBA5658, // ����ֽ� ����4�ֽ�ת��


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
	static image_info_t OpenPngToDial(QString fileName, QByteArray* data, COLOR_FORMAT color_format); //pngָ��תbin
	static QByteArray Convert32to16ZZ(QByteArray sourceBytes, int width, int height, COLOR_FORMAT color_format, bool addAlpha = false);
	static image_info_t OpenAlpha(QString fileName, QByteArray* data, COLOR_FORMAT color_format);
private:
//	QMap<QString, QString>Image_Path_Map; //ͼƬ������·��


};
