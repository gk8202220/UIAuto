#include "ImageToBin.h"
#include <QDebug>
#include <QImage>
#pragma execution_character_set("UTF-8")
BMPtobin::BMPtobin(QObject* parent)
	: QObject(parent)
{
}

BMPtobin::~BMPtobin()
{
}
unsigned int rgb24to565(unsigned int a)
{
	//	unsigned int t = a;
	//	unsigned int tt = a;

	unsigned short b = (a & 0xff) >> 3;
	unsigned short g = ((a & 0xff00) >> 10);
	unsigned short r = ((a & 0xff0000) >> 19);
	unsigned int rgb = (b | (g << 5) | (r << 11));

	rgb = (rgb >> 8) + ((rgb & 0xFF) << 8);
	return rgb;
}
//bmp转565
image_info_t BMPtobin::OpenBmp(QString fileName, QByteArray* data, COLOR_FORMAT color_format)
{
	image_info_t image_info = {0};
	QImage image(fileName);
	QByteArray srcdata;
	image_info.width = image.width();
	image_info.height = image.height();
	
	for (int y = 0; y < image.height(); y++)
	{
		for (int x = 0; x < image.width(); x++)
		{
			//转成565
			unsigned int rgb = rgb24to565(image.pixel(QPoint(x, y)));
			srcdata.append((rgb & 0xFF));  //低位
			srcdata.append(((rgb >> 8) & 0xFF)); //高位
		}
	}
	if (color_format == RGBA5658)
	{
		for (uint32_t i = 0; i < srcdata.size(); i += 4)
		{
			data->append(srcdata.at(i + 3));
			data->append(srcdata.at(i + 2));
			data->append(srcdata.at(i + 1));
			data->append(srcdata.at(i));

		}
	}
	else
	{
		data->append(srcdata);
	}
	image_info.size = srcdata.size();
	return image_info;

}
//png 只获取alpha值
image_info_t BMPtobin::OpenAlpha(QString fileName, QByteArray* data, COLOR_FORMAT color_format)
{
	image_info_t image_info = { 0 };
	QImage image(fileName);
	QByteArray srcdata;
	image_info.width = image.width();
	image_info.height = image.height();

	for (int y = 0; y < image.height(); y++)
	{
		for (int x = 0; x < image.width(); x++)
		{
			//转成565
			uint8_t alpha =(uint8_t)image.pixelColor(QPoint(x, y)).alpha();
			srcdata.append((alpha & 0xFF)); 
			
		}
	}
	if (color_format == RGBA5658)
	{
		/*if (srcdata.size() % 4 != 0)
		{
			QByteArray data;
			data.append(0xff);
			for (int i = srcdata.size() % 4; i < 4; i++)
			{
				
				srcdata.append(0xff);
			}
		}*/
		data->append(srcdata);
	//	for (uint32_t i = 0; i < srcdata.size(); i += 4)
	//	{
	///*		data->append(srcdata.at(i + 3));
	//		data->append(srcdata.at(i + 2));
	//		data->append(srcdata.at(i + 1));
	//		data->append(srcdata.at(i));*/

	//	}
	}
	else
	{
		data->append(srcdata);
	}
	image_info.size = srcdata.size();
	return image_info;

}

image_info_t BMPtobin::OpenPngToDial(QString fileName, QByteArray* data, COLOR_FORMAT color_format)
{
	int res_size = 0;
	image_info_t image_info = { 0 };
	QImage image(fileName);

	if (image.isNull())
	{
		qDebug() << "OpenPngToDial error!";
		image_info.size = 0;
		return image_info;
	}
	QByteArray color;
	for (int h = 0; h < image.height(); h++)
	{
		for (int w = 0; w < image.width(); w++)
		{
			color.append((uint8_t)image.pixelColor(QPoint(w, h)).green());
			color.append((uint8_t)image.pixelColor(QPoint(w, h)).blue());
			color.append((uint8_t)image.pixelColor(QPoint(w, h)).red());
			color.append((uint8_t)image.pixelColor(QPoint(w, h)).alpha());
		}
	}
	QByteArray colordata = Convert32to16ZZ(color, image.width(), image.height(), color_format, true);
	data->append(colordata);
	image_info.height = image.height();
	image_info.width = image.width();
	
	res_size = colordata.size();
	image_info.size = colordata.size();
	return image_info;
}

QByteArray BMPtobin::Convert32to16ZZ(QByteArray sourceBytes, int width, int height, COLOR_FORMAT color_format, bool addAlpha) {
	// 原图的跨区宽度 原图必须是32位是
	int sourceStride = width * 4;  //每一行所占的大小
	int saveStride = 0;

	if (sourceBytes.size() % sourceStride != 0)
		qDebug() << "传入的图片字节数组长度不是对应扫描宽度的整数倍";

	ZZPicture zZPicture;// = new ZZPicture();

						
	int startLine = -1;// 有效数据起始行
	
	int effectiveLines = 0;// 有效数据总行数
	// 上一行的像素点个数
	int latestLinePoints = 0;
	// 像素数据
	QByteArray pointsBytes;// = new List<byte>();
	for (int i = 0; i < height; i++) //从上到下，遍历图片的跨区宽度
	{
		// 当前扫描宽度的RGBA值数组  一行一行处理
		QByteArray RGBAListPerLine;// = new byte[sourceStride];
								   //Array.Copy(sourceBytes, i * sourceStride, RGBAListPerLine, 0, sourceStride);
		RGBAListPerLine = sourceBytes.mid(i * sourceStride, sourceStride); //取一行的原始数据
		// 所有当前扫描宽度的alpha值
		QList<RGBAUnit> rgbBytes;// = new QList<RGBAUnit>(); // 保存着这一行原始 RGBA的颜色值
		for (int z = 0; z < sourceStride; z += 4) {
			RGBAUnit rgba;// = new RGBAUnit();
			if (z + 3 >= sourceStride)
				break;

			rgba.g = RGBAListPerLine[z];
			rgba.b = RGBAListPerLine[z + 1];
			rgba.r = RGBAListPerLine[z + 2];
			rgba.a = RGBAListPerLine[z + 3];

			rgbBytes.append(rgba);
		}

		// 起始地址和结束地址  888 =》 565 有损 筛选无效像素点 
		// 由于png alpha通道为0即透明情况时，rgb值无效，所以只能通过alpha通道判断有效区域
		int first = -1;
		for (int i = 0; i < rgbBytes.count(); i++)
		{
			if (rgbBytes.at(i).a > 0x03)
			{

				first = i;  //获取到这一行的起始有效颜色值的位置
				break;
			}
		}
		int end = -1;// Array.FindLastIndex(rgbBytes.ToArray(), item = > {
		for (int i = rgbBytes.count() - 1; i >= 0; i--)
		{
			if (rgbBytes.at(i).a > 0x03)
			{
				end = i; //获取到这一行的结束有效颜色值的位置
				break;
			}
		}

		// 找不到起始和结束地址 不处理
		if (first == -1 || end == -1)
			continue;

		// 有效数据起始行
		if (startLine == -1)
		{
			startLine = i;  //保存起始行
		}


		// 有效数据的总行数
		effectiveLines++;

		ZZPictureLine zZPictureLine;// = new ZZPictureLine();
									
		QByteArray lineDataBytes;// = new List<byte>();// 该行的指针区域数据 

								 // 从起始地址到结束地址遍历
		for (int y = first; y <= end; y++) {


			quint8 G = RGBAListPerLine[y * 4];
			quint8 B = RGBAListPerLine[y * 4 + 1];
			quint8 R = RGBAListPerLine[y * 4 + 2];
			quint8 A = RGBAListPerLine[y * 4 + 3];

			// RGB =》 { 0, 0, 0 } 为黑 
			// RGB =》 { 255, 255, 255 } 为白
			// A 从 0x00 - 0xff 为 00完全透明 到 ff完全不透明(即为黑)

		/*	if (isP) {
		*		//数据倒换
				lineDataBytes.append((quint8)(((G << 3) & 0xe0) | ((B >> 3) & 0x1f)));
				lineDataBytes.append((quint8)((R & 0xf8) | ((G >> 5) & 7)));
				if (addAlpha)
					lineDataBytes.append((uint8_t)A);
			}
			else {*/
			if (color_format == RGBA5658)
			{
				if (A != 0xff && !addAlpha) // 半透明 按 A 的比例转化rgb  0xff是不透明（黑色） 0xff且0x00
				{
					int Bint = (quint32)(B);
					int Gint = (quint32)(G);
					int Rint = (quint32)(R);
					float scale = (quint32)(A) / (float)255; //透明度的百分比
					B = (Bint * scale);
					G = (Gint * scale);
					R = (Rint * scale);
				}
				uint8_t c_h = ((R & 0xf8) | ((G >> 5) & 7));
				uint8_t c_l = (((G << 3) & 0xe0) | ((B >> 3) & 0x1f));
				lineDataBytes.append(c_h);
				lineDataBytes.append(c_l);
			
				if (addAlpha)
					lineDataBytes.append((uint8_t)A);
			}
			else if (color_format == RGBA8888)
			{
				lineDataBytes.append((uint8_t)R);
				lineDataBytes.append((uint8_t)G);
				lineDataBytes.append((uint8_t)B);
				if (addAlpha)
					lineDataBytes.append((uint8_t)A);
			}


		}

		// 当前行的 x 坐标
		qint8 xCoord = (qint8)first + 1; // 如果界面超过255呢？那不是超了？
		zZPictureLine.xCoord = xCoord;

		// 当前行的像素点个数
		latestLinePoints = end - first + 1;
		zZPictureLine.linePointCount = latestLinePoints;// Convert.ToByte();

		zZPicture.lines.append(zZPictureLine);  //将一行的信息保存的总的数据上
		zZPicture.allDatas.append(lineDataBytes);//将一行的数据保存的总的数据上
	
	}
	
	zZPicture.startLine = (uint8_t)(startLine);// 起始行
	zZPicture.totalLinesCount = (uint8_t)(effectiveLines); //总的行数

	QByteArray targetBytesWitoutLenght;// = new List<byte>();
	// 指针数据结构 = 有效数据的总长度（占2个字节）  起始行（占1个字节） + 总的行数（占1个字节） + 
	// （ 地址偏移位置（占2个字节） 这一行的总数（占1个字节）  x的起始位置（占1个字节）*总的行数

	targetBytesWitoutLenght.append((uint8_t)zZPicture.startLine); //起始行占1位
	targetBytesWitoutLenght.append((uint8_t)zZPicture.totalLinesCount); //总行占1位

	int latestLineAddr = 0;  //当前保存的偏移地址
	// 处理 偏移地址
	for (int i = 0; i < effectiveLines; i++) {
		ZZPictureLine currentLine = zZPicture.lines[i];

		currentLine.address = (uint16_t)(4 + 4 * zZPicture.totalLinesCount + latestLineAddr); //第一个4 表示 有效数据的总长度（占2个字节）  起始行（占1个字节） + 总的行数（占1个字节）
																							//第二个4 表示 （ 地址偏移位置（占2个字节） 这一行的总数（占1个字节）  x的起始位置（占1个字节）
		// 累加 各行起始地址
		if (color_format == RGBA8888)
		{
			saveStride = 4;
		}
		else if (color_format == RGBA5658)
		{
			saveStride = 3;
		}
		latestLineAddr += zZPicture.lines[i].linePointCount * saveStride;

		targetBytesWitoutLenght.append(currentLine.address & 0xFF);
		targetBytesWitoutLenght.append((currentLine.address >> 8) & 0xFF); //第一个有效行偏移地址占两位

		targetBytesWitoutLenght.append(currentLine.linePointCount);
		targetBytesWitoutLenght.append(currentLine.xCoord);

		
	}

	targetBytesWitoutLenght.append(zZPicture.allDatas);
	QByteArray targetBytes;// = new List<byte>();
	int lenght = targetBytesWitoutLenght.count() + 2;

	targetBytes.append(lenght & 0xFF);
	targetBytes.append((lenght >> 8) & 0xFF); //第一个有效行偏移地址占两位

	targetBytes.append(targetBytesWitoutLenght);
	//qDebug() << "lenght & 0xFF" << (lenght & 0xFF) << "  " << ((lenght >> 8) & 0xFF) << targetBytes.size();
	return targetBytes;

}