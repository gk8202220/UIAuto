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
//bmpת565
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
			//ת��565
			unsigned int rgb = rgb24to565(image.pixel(QPoint(x, y)));
			srcdata.append((rgb & 0xFF));  //��λ
			srcdata.append(((rgb >> 8) & 0xFF)); //��λ
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
//png ֻ��ȡalphaֵ
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
			//ת��565
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
	// ԭͼ�Ŀ������ ԭͼ������32λ��
	int sourceStride = width * 4;  //ÿһ����ռ�Ĵ�С
	int saveStride = 0;

	if (sourceBytes.size() % sourceStride != 0)
		qDebug() << "�����ͼƬ�ֽ����鳤�Ȳ��Ƕ�Ӧɨ���ȵ�������";

	ZZPicture zZPicture;// = new ZZPicture();

						
	int startLine = -1;// ��Ч������ʼ��
	
	int effectiveLines = 0;// ��Ч����������
	// ��һ�е����ص����
	int latestLinePoints = 0;
	// ��������
	QByteArray pointsBytes;// = new List<byte>();
	for (int i = 0; i < height; i++) //���ϵ��£�����ͼƬ�Ŀ������
	{
		// ��ǰɨ���ȵ�RGBAֵ����  һ��һ�д���
		QByteArray RGBAListPerLine;// = new byte[sourceStride];
								   //Array.Copy(sourceBytes, i * sourceStride, RGBAListPerLine, 0, sourceStride);
		RGBAListPerLine = sourceBytes.mid(i * sourceStride, sourceStride); //ȡһ�е�ԭʼ����
		// ���е�ǰɨ���ȵ�alphaֵ
		QList<RGBAUnit> rgbBytes;// = new QList<RGBAUnit>(); // ��������һ��ԭʼ RGBA����ɫֵ
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

		// ��ʼ��ַ�ͽ�����ַ  888 =�� 565 ���� ɸѡ��Ч���ص� 
		// ����png alphaͨ��Ϊ0��͸�����ʱ��rgbֵ��Ч������ֻ��ͨ��alphaͨ���ж���Ч����
		int first = -1;
		for (int i = 0; i < rgbBytes.count(); i++)
		{
			if (rgbBytes.at(i).a > 0x03)
			{

				first = i;  //��ȡ����һ�е���ʼ��Ч��ɫֵ��λ��
				break;
			}
		}
		int end = -1;// Array.FindLastIndex(rgbBytes.ToArray(), item = > {
		for (int i = rgbBytes.count() - 1; i >= 0; i--)
		{
			if (rgbBytes.at(i).a > 0x03)
			{
				end = i; //��ȡ����һ�еĽ�����Ч��ɫֵ��λ��
				break;
			}
		}

		// �Ҳ�����ʼ�ͽ�����ַ ������
		if (first == -1 || end == -1)
			continue;

		// ��Ч������ʼ��
		if (startLine == -1)
		{
			startLine = i;  //������ʼ��
		}


		// ��Ч���ݵ�������
		effectiveLines++;

		ZZPictureLine zZPictureLine;// = new ZZPictureLine();
									
		QByteArray lineDataBytes;// = new List<byte>();// ���е�ָ���������� 

								 // ����ʼ��ַ��������ַ����
		for (int y = first; y <= end; y++) {


			quint8 G = RGBAListPerLine[y * 4];
			quint8 B = RGBAListPerLine[y * 4 + 1];
			quint8 R = RGBAListPerLine[y * 4 + 2];
			quint8 A = RGBAListPerLine[y * 4 + 3];

			// RGB =�� { 0, 0, 0 } Ϊ�� 
			// RGB =�� { 255, 255, 255 } Ϊ��
			// A �� 0x00 - 0xff Ϊ 00��ȫ͸�� �� ff��ȫ��͸��(��Ϊ��)

		/*	if (isP) {
		*		//���ݵ���
				lineDataBytes.append((quint8)(((G << 3) & 0xe0) | ((B >> 3) & 0x1f)));
				lineDataBytes.append((quint8)((R & 0xf8) | ((G >> 5) & 7)));
				if (addAlpha)
					lineDataBytes.append((uint8_t)A);
			}
			else {*/
			if (color_format == RGBA5658)
			{
				if (A != 0xff && !addAlpha) // ��͸�� �� A �ı���ת��rgb  0xff�ǲ�͸������ɫ�� 0xff��0x00
				{
					int Bint = (quint32)(B);
					int Gint = (quint32)(G);
					int Rint = (quint32)(R);
					float scale = (quint32)(A) / (float)255; //͸���ȵİٷֱ�
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

		// ��ǰ�е� x ����
		qint8 xCoord = (qint8)first + 1; // ������泬��255�أ��ǲ��ǳ��ˣ�
		zZPictureLine.xCoord = xCoord;

		// ��ǰ�е����ص����
		latestLinePoints = end - first + 1;
		zZPictureLine.linePointCount = latestLinePoints;// Convert.ToByte();

		zZPicture.lines.append(zZPictureLine);  //��һ�е���Ϣ������ܵ�������
		zZPicture.allDatas.append(lineDataBytes);//��һ�е����ݱ�����ܵ�������
	
	}
	
	zZPicture.startLine = (uint8_t)(startLine);// ��ʼ��
	zZPicture.totalLinesCount = (uint8_t)(effectiveLines); //�ܵ�����

	QByteArray targetBytesWitoutLenght;// = new List<byte>();
	// ָ�����ݽṹ = ��Ч���ݵ��ܳ��ȣ�ռ2���ֽڣ�  ��ʼ�У�ռ1���ֽڣ� + �ܵ�������ռ1���ֽڣ� + 
	// �� ��ַƫ��λ�ã�ռ2���ֽڣ� ��һ�е�������ռ1���ֽڣ�  x����ʼλ�ã�ռ1���ֽڣ�*�ܵ�����

	targetBytesWitoutLenght.append((uint8_t)zZPicture.startLine); //��ʼ��ռ1λ
	targetBytesWitoutLenght.append((uint8_t)zZPicture.totalLinesCount); //����ռ1λ

	int latestLineAddr = 0;  //��ǰ�����ƫ�Ƶ�ַ
	// ���� ƫ�Ƶ�ַ
	for (int i = 0; i < effectiveLines; i++) {
		ZZPictureLine currentLine = zZPicture.lines[i];

		currentLine.address = (uint16_t)(4 + 4 * zZPicture.totalLinesCount + latestLineAddr); //��һ��4 ��ʾ ��Ч���ݵ��ܳ��ȣ�ռ2���ֽڣ�  ��ʼ�У�ռ1���ֽڣ� + �ܵ�������ռ1���ֽڣ�
																							//�ڶ���4 ��ʾ �� ��ַƫ��λ�ã�ռ2���ֽڣ� ��һ�е�������ռ1���ֽڣ�  x����ʼλ�ã�ռ1���ֽڣ�
		// �ۼ� ������ʼ��ַ
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
		targetBytesWitoutLenght.append((currentLine.address >> 8) & 0xFF); //��һ����Ч��ƫ�Ƶ�ַռ��λ

		targetBytesWitoutLenght.append(currentLine.linePointCount);
		targetBytesWitoutLenght.append(currentLine.xCoord);

		
	}

	targetBytesWitoutLenght.append(zZPicture.allDatas);
	QByteArray targetBytes;// = new List<byte>();
	int lenght = targetBytesWitoutLenght.count() + 2;

	targetBytes.append(lenght & 0xFF);
	targetBytes.append((lenght >> 8) & 0xFF); //��һ����Ч��ƫ�Ƶ�ַռ��λ

	targetBytes.append(targetBytesWitoutLenght);
	//qDebug() << "lenght & 0xFF" << (lenght & 0xFF) << "  " << ((lenght >> 8) & 0xFF) << targetBytes.size();
	return targetBytes;

}