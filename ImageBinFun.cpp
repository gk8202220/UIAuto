#include "ImageBinFun.h"
#include <QJsonArray>
#include <QDir>
#include <QImage>
#include <QJsonDocument>
#include <QStandardItemModel>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include "veepoolzo.h"
#include "MinilzoTest.h"
#include "crcunit.h"
#pragma execution_character_set("UTF-8")
void ImageBinFun::titletobmpbin(QString titile)
{
	//对应的图片保存成bin
	QByteArray bmpbin;
	QJsonArray imageArray = Title_Image_json.value(titile).toArray();
	foreach(QJsonValue value, imageArray)
	{
		QString image_file_path = Image_Path_Map.value(value.toString());

		//if (ui.checkBox_Litter->isChecked())
		{
			BMPtobin::OpenBmp(image_file_path, &bmpbin, BRGBA5658);
		}
		//else
		{
		//	BMPtobin::OpenBmp(image_file_path, &bmpbin, RGBA5658);
		}

	}
}
void ImageBinFun::jsonfile(QString josnfile)
{
	//QFileInfo info(josnfile);
	//QString iconFilePath = info.path();  //该目录为一级路径
	//									 //读取原始的json文件文件数据
	//QFile file(josnfile);
	//if (!file.open(QIODevice::ReadOnly))
	//{
	//	qDebug() << "open file error!" << josnfile;
	//	return;
	//}
	//QByteArray fileData = file.readAll();
	//file.close();
	//QJsonParseError  json_error;
	////json读取格式
	//QJsonDocument json(QJsonDocument::fromJson(fileData, &json_error));
	//if (json_error.error != QJsonParseError::NoError)
	//{
	//	qDebug() << "json error!" << json_error.error;
	//	return;
	//}
	//rootObj = json.object();
}
#define  UNZIP_MAX_LEN  (8 * 1024); //每块最大压缩8K
ImageBinFun::ImageBinFun()
{
	gui_is_compress = COMPRESS_NULL;
	test_conut = 0;
}

void ImageBinFun::SetCompress(COMPRESS_FORMAT format)
{
	gui_is_compress = format;
}
void ImageBinFun::SetColorFormat(COLOR_FORMAT format)
{
	color_format = format;
}

QString ImageBinFun::getImageFormat(QString image_file_name, IMAGE_FORMAT *image_format)
{
	QStringList imageNameList = image_file_name.split("_");  //切分图片命名
	QString image_title;
	if (imageNameList.at(0).contains("zz"))
	{
		//指针图片
		image_title = imageNameList.at(1) + "_" + imageNameList.at(2); //去掉zz字母
		*image_format = IMAGE_FORMAT_DIAL;
	}
	else if (imageNameList.at(0).contains("aaa"))
	{
		//alpha图片
		image_title = imageNameList.at(1) + "_" + imageNameList.at(2); //去掉zz字母
		*image_format = IMAGE_FORMAT_ALPHA;

	}
	else
	{
		//正常图片
		image_title = imageNameList.at(0) + "_" + imageNameList.at(1);
		*image_format = IMAGE_FORMAT_BMP;
	}
	return image_title;
}

bool ImageBinFun::minilzo_init(void)
{

	if (lzo_init() != LZO_E_OK)
	{
		return false;
	}
	return true;
}


QByteArray ImageBinFun::minilzo_compress(QByteArray src)
{

	unsigned char ret;
	
	unsigned long zip_len = 0;
	
	unsigned char* src_data = (unsigned char*)src.data();
	unsigned long uzip_len = src.size();
	
    unsigned char dst_data[260 * 1024 ] = { 0 };
	//if (uzip_len > IN_LEN && uzip_len <= 0)
	//{
	//	return 0;
	//}

	ret = lzo1x_1_compress(src_data, uzip_len, dst_data, (lzo_uintp)&zip_len, wrkmem);
	QByteArray dst;
	if (ret != LZO_E_OK)
	{
		qDebug() << "lzo1x_1_compress error!";
		return dst;
	}
	else
	{
		for (int i = 0; i < zip_len; i++)
		{
			dst.append(dst_data[i]);
			//dst.append(0xff);
		}
	}
	return dst;
}
QByteArray zip_data;
void ImageBinFun::minilzo_compressBlock(QByteArray src, image_info_t* image_info, QByteArray* dst)
{

	unsigned char ret;

	uint16_t zip_len = 0;

	unsigned char* src_data = (unsigned char*)src.data();
	//unsigned long uzip_len = src.size();
	uint32_t src_size = src.size(); //文件的大小
	uint32_t DEF_ULZIP_MAX_LEN = UNZIP_MAX_LEN;// 8 * 1024; //每块最大压缩8K
	unsigned char dst_data[8 * 1024] = { 0 };
	int image_width_size = image_info->width * 2; //宽度的大小
	int max_heigt = DEF_ULZIP_MAX_LEN / image_width_size;
	int ULZIP_MAX_LEN = max_heigt * image_width_size;
	zip_data.clear();
	//if (uzip_len > IN_LEN && uzip_len <= 0)
	//{
	//	return 0;
	//}
	//计算需要分多少次压缩
	/*int block_count = src_size / ULZIP_MAX_LEN;
	if (src_size % ulzip_len != 0)
	{
		block_count++;
	}*/
	int block_index = 0;
	QList<uint32_t> zip_len_list;
	

	//qDebug() << "需要压缩的高度和大小" << max_heigt << ULZIP_MAX_LEN;
	int has_read_size = 0;
	uint32_t readly_size = src_size;
	QByteArray len_arry;
	while (readly_size > 0)
	{
		memset(dst_data, 0, sizeof(dst_data));
		int ulzip_len = readly_size > ULZIP_MAX_LEN ? ULZIP_MAX_LEN : readly_size;// (block_index * ulzip_len);
		
		ret = lzo1x_1_compress(src_data + (has_read_size), ulzip_len, dst_data, (lzo_uintp)&zip_len, wrkmem);
		block_index++;
	//	block_count--;
		has_read_size += ulzip_len;
		readly_size -= ulzip_len;
		if (ret != LZO_E_OK)
		{
			//qDebug() << "lzo1x_1_compress error!";
			return ;
		}
		else
		{
//			qDebug()<< "压缩前大小" << ulzip_len << "压缩后的大小" << zip_len;
			zip_len_list.append(zip_len);
			len_arry.append((uint8_t)((zip_len >> 8) & 0xff));
			len_arry.append((uint8_t)((zip_len) & 0xff));
		//	qDebug() << "压缩前大小"<< ulzip_len << "压缩后大小" << zip_len;
			for (int i = 0; i < zip_len; i++)
			{
				zip_data.append(dst_data[i]);
				//dst.append(0xff);
			}
		}
	
	}
	//qDebug() << "压缩前总大小" << src_size << "压缩后的总大小" << zip_data.size();
	//qDebug() <<"压缩后索引表"<<  len_arry.size();
	dst->append(len_arry); //添加索引表
	dst->append(zip_data);// 添加数据
	

}
// 在分块压缩中从指定的位置读取大小
QByteArray ImageBinFun::minilzo_GetBolckDate(image_info_t* image_info, int start_y, int end_y, QByteArray dst)
{
	// 计算是在从第几块到最后一块里读取
	int block_start_index = 0; //起始块
	int block_end_index = 0; //结束块
	int block_start_y = 0; //块起始y
	int block_end_y = 0; //块结束y
	
	uint32_t DEF_ULZIP_MAX_LEN = UNZIP_MAX_LEN;// 8 * 1024; //每块最大压缩8K
	int image_width_size = image_info->width * 2; //宽度的大小
	int max_heigt = DEF_ULZIP_MAX_LEN / image_width_size; //最大的高度
	int ULZIP_MAX_LEN = max_heigt * image_width_size;//压缩最大的数据
    int block_count = image_info->size / ULZIP_MAX_LEN; //分的总块
	uint32_t src_size = image_info->size;
	
	int image_read_size = (end_y - start_y  ) * image_width_size; //最终要解压后的总大小
	//qDebug() << end_y << " " << start_y << " " << image_width_size << image_read_size;
	uint32_t out_data_length = 0; //解压后的数据大小
	QByteArray out_data_array; // 解压后的数据

	if (src_size % ULZIP_MAX_LEN != 0)
	{
		block_count++;
	}
    int data_start_addr = block_count * 2; //数据的起始位置
	//qDebug() << "索引表" << block_count;
	////生成索引表
	QByteArray zip_len_list_array = dst.mid(0, block_count * 2);
	QList<uint32_t> zip_len_list; // 每块的大小
	QList<uint32_t> zip_offset_list; //块的偏移位置
	int count_len = 0;
	int icon_current_addr = 0; //当前的数据总大小
	for (uint8_t i = 0; i < block_count * 2; i += 2)
	{
		uint8_t h = (uint8_t)(zip_len_list_array.at(i));
		uint8_t l = (uint8_t)(zip_len_list_array.at(i + 1));
		uint16_t len = (h << 8)| (l);	
	
		zip_len_list.append(len);
		zip_offset_list.append(count_len);
		count_len += len;
		
	}
	
	block_start_index = start_y / max_heigt;
	block_end_index = end_y / max_heigt;
	if (end_y % max_heigt != 0)
	{
		block_end_index++;
	}
	//qDebug() << "总长度 " << count_len << block_start_index << block_end_index;
	for (int i = block_start_index; i < block_end_index; i++)
	{
		int read_start_y = 0;
		int read_end_y = max_heigt;
		if (i == block_start_index)
		{
			read_start_y = start_y % max_heigt;
		}
		if (i == (block_end_index -1))
		{
			read_end_y = end_y % max_heigt ;
			read_end_y = read_end_y == 0 ? max_heigt : read_end_y;
		}
		if (read_end_y == 0)
		{
			break;
		}
		//qDebug() << "读取的起始y " << read_start_y << "读取结束y" << read_end_y;
	
		crcUnit crcunit;
		uint16_t decom_length = zip_len_list.at(i); //此块解压的长度
		int decom_all_length = zip_offset_list.at(i);
		unsigned char out_data[8 * 1024] = { 0 };
		int zip_size_offset = data_start_addr + decom_all_length;
		QByteArray src_data_array = dst.mid(zip_size_offset, decom_length); //获取到解压的数据
		unsigned char* src_data = (unsigned char*)src_data_array.data();
	
		int ret =  lzo1x_decompress((uint8_t*)(src_data), decom_length, (uint8_t*)out_data, (lzo_uintp)&out_data_length, wrkmem);
		//add_size[add_index] = decom_length;
		
		//add_crc[add_index] = crcunit.crc16WithData((const char*)out_data, out_data_length);
		
		if (ret != LZO_E_OK)
		{
			
			qDebug() << "解压失败" << ret;

		}
		else
		{
			//qDebug() << "解压前的大小" << decom_length << "解压后的大小" << out_data_length;
			int add_src_offset = read_start_y * image_width_size; //要添加数据的偏移
			int add_src_len = (read_end_y - read_start_y ) * image_width_size;//要添加数据的大小
			
			icon_current_addr += add_src_len;
			//qDebug() << "当前的总大小" << icon_current_addr << "add_src_offset" << add_src_offset << "add_src_len" << add_src_len << "解压的长度" << out_data_length;
		
		
			for (int i = 0; i < add_src_len; i++)
			{
				out_data_array.append(out_data[i + add_src_offset]);
				//dst.append(0xff);
			}

		}
	}
	if (out_data_array.size() == image_read_size)
	{
		//qDebug() << "解压缩成功";
	}
	else
	{
		//qDebug() << "解压失败的总大小" << out_data_array.size() << "原总大小" << image_read_size;
	}
	
	//qDebug()<<"高度"<< max_heigt << "起始行" << start_y << "结束行" << end_y << "起始块" << block_start_index << "结束块" << block_end_index;
	return out_data_array;

}

QByteArray ImageBinFun::minilzo_decompressBlock(QByteArray src, image_info_t* image_info)
{
	//解压
	uint32_t src_size = src.size(); //文件的大小
	uint32_t decom_all_length = 0; //压缩的大小
	uint32_t out_data_length = 0; //解压后的数据大小
	QByteArray out_data_array; // 解压后的数据
	
	//根据宽度计算出索引表
	uint32_t DEF_ULZIP_MAX_LEN = UNZIP_MAX_LEN;// 8 * 1024; //每块最大压缩8K
	int image_width_size = image_info->width * 2; //宽度的大小
	int max_heigt = DEF_ULZIP_MAX_LEN / image_width_size; 
	int ULZIP_MAX_LEN = max_heigt * image_width_size;
	int block_count = image_info->size / ULZIP_MAX_LEN;
	if (src_size % ULZIP_MAX_LEN != 0)
	{
		block_count++;
	}
	qDebug() << "索引表" << block_count;
	//需要解压的次数
	/*if (src_size % ULZIP_MAX_LEN != 0)
	{
		block_count++;
	}*/
	//生成索引表
	QByteArray zip_len_list_array = src.mid(0, block_count * 2);
	QList<uint32_t> zip_len_list;
	for (uint8_t i = 0; i < block_count * 2; i += 2)
	{
		uint8_t h = (uint8_t)(zip_len_list_array.at(i));
		uint8_t l = (uint8_t)(zip_len_list_array.at(i + 1));
		uint16_t len = (h << 8)| (l);
	
		zip_len_list.append(len);
	}

	int data_start_addr = block_count * 2; //数据的起始位置
	for (uint8_t index = 0; index < block_count; index++)
	{
		
		uint16_t decom_length = zip_len_list.at(index);
		unsigned char out_data[32 * 1024] = { 0 };
		int zip_size_offset = data_start_addr + decom_all_length;
		QByteArray src_data_array = src.mid(zip_size_offset, decom_length);
		
		unsigned char *src_data = (unsigned char*)src_data_array.data();
		qDebug() << src_data_array.size();
		//unsigned char src_data[32 * 1024];
		//memcpy(src_data, (unsigned char*)src_data_array.data(), decom_length);
		qDebug() << src_data[0] << "  date1 = " << src_data[1]<< (decom_all_length + (block_count * 2));
		//unsigned char* src_data = (unsigned char*)src_data_array.data();
		 int ret = lzo1x_decompress((uint8_t*)(src_data ), decom_length, (uint8_t*)out_data, (lzo_uintp)&out_data_length, wrkmem);
		if (ret != LZO_E_OK)
		{
			qDebug() << "解压失败" << ret;
		
		}
		else
		{
			//qDebug() << "解压前的大小" << decom_length << "解压后的大小" << out_data_length;
			for (int i = 0; i < out_data_length; i++)
			{
				out_data_array.append(out_data[i]);
				//dst.append(0xff);
			}

		}
		//qDebug() << "解压前的大小" << decom_length << "解压后的大小" << out_data_length;
		//block_index--;
		//block_count++;
		decom_all_length += decom_length;
	}
	if (out_data_array.size() == image_info->size)
	{
		qDebug() << "解压缩成功";
	}
	else
	{
		qDebug() << "解压失败的总大小" << out_data_array.size() << "原解压失败的总大小" << src.size();
	}
	return out_data_array;

}
QByteArray ImageBinFun::minilzo_decompress(QByteArray src)
{
	uint32_t current_index = 0;
	uint32_t decom_index = 0;

	uint32_t out_data_length = 0;
	uint32_t decom_all_length = 0;

	uint32_t remain_count = 0;
	uint32_t image_size = src.size(); //压缩的大小
	uint32_t read_max_size = 512; //每次解压的数据
	unsigned char dst_data[260 * 1024] = { 0 };
	
	qDebug() << LZO1X_1_MEM_COMPRESS;
	unsigned char* src_data = (unsigned char*)src.data();
	while (1)
	{
		remain_count = image_size - current_index;
		if (remain_count == 0)
		{
			break;
		}
		
		uint32_t decom_length = remain_count >= read_max_size ? read_max_size : remain_count;
		
		lzo1x_decompress( (uint8_t*)src_data + decom_all_length, decom_length,  (uint8_t*)dst_data + current_index, (lzo_uintp)&out_data_length, wrkmem);
		decom_index = upzip_block_size;
		qDebug() << "解压大小" << out_data_length;
		current_index += decom_index;
		decom_all_length += out_data_length;

		if ((decom_index == 0 && out_data_length == 0) || current_index > image_size)
		{
			break;
		}

		//index_len --;
	}
	QByteArray dst;
	for (int i = 0; i < decom_all_length; i++)
	{
		dst.append(dst_data[i]);
	}
	return dst;
}

QByteArray ImageBinFun::vp_decompress(QByteArray src)
{
	unsigned char dst_data[260 * 1024] = { 0 };
	unsigned long dstlen = 0;
	QByteArray dst;
	unsigned long current_index = 0;
	int ret = Veepoolzo::veepoo_decompress((const unsigned char*)src.data(), src.size(), dst_data, &dstlen, &current_index);
	if (ret)
	{
		for (int i = 0; i < dstlen; i++)
		{
			dst.append(dst_data[i]);
		}
	}

	return dst;
}


QByteArray ImageBinFun::vp_compress(QByteArray src )
{
		unsigned char dst_data[260 * 1024 ] = { 0 };
		unsigned long dstlen = 0;
		QByteArray dst;
		bool ret = Veepoolzo::veepoo_compress((const unsigned char*)src.data(), src.size(), dst_data, &dstlen);
		if (ret)
		{
			for (int i = 0; i < dstlen; i++)
			{
				dst.append(dst_data[i]);
			}
		}
	
	return dst;
}

void ImageBinFun::PrintPngAddr(QList<image_info_t> image_info_list)
{
	
	int index = 0;
	for each (image_info_t image_info in image_info_list)
	{

		if (index == 0)
		{
			if (image_info.size != 0)
			{
				QString image_title = getImageFormat(image_info.name, &image_format); //获取图片类型和标题	
				gui_flash_addr.append("\n");
				gui_flash_addr.append("#define ICON_AAA_" + image_title.toUpper() + "_SIZE  " + QString::number(image_info.size));
				gui_flash_addr.append("\n");
				gui_flash_addr.append("#define ICON_AAA_" + image_title.toUpper() + "_WIDE  " + QString::number(image_info.width));
				gui_flash_addr.append("\n");
				gui_flash_addr.append("#define ICON_AAA_" + image_title.toUpper() + "_HIGH  " + QString::number(image_info.height));
				gui_flash_addr.append("\n");
				gui_flash_addr.append("\n");
				/*	qDebug() << "";
					qDebug() << "ICON_" + image_title.toUpper() + "_SIZE  " + QString::number(image_info.size);
					qDebug() << "ICON_" + image_title.toUpper() + "_WIDE  " + QString::number(image_info.width);
					qDebug() << "ICON_" + image_title.toUpper() + "_HIGH  " + QString::number(image_info.height);

					qDebug() << "";*/
			}

		}
		index++;
#if	H02Q_UI
		int ui_start_addr = 0x8E000; //UI起始空间起始地址
		int offset_addr = 0xFD000 - ui_start_addr;
		int addr_count = 0x3000;  //0xFD000 ~ 0x10000  预留的空间
		int boot_end_addr = 0x100000; //预留空间结束地址


		int max_size_offset = image_addr_count + image_info.size;
		if ((max_size_offset > offset_addr) && (image_addr_count < offset_addr))
		{
			image_addr_count = boot_end_addr - ui_start_addr;  // FD000 - 93000
		}
#endif
		//qDebug() << "ICON_" + image_info.name.toUpper() + "_ADDR  " + QString::number(image_addr_count);
		gui_flash_addr.append("#define ICON_" + image_info.name.toUpper() + "_ADDR  " + QString::number(image_addr_count));
		gui_flash_addr.append("\n");
		//qDebug() << "image_addr_count" << image_addr_count;


		image_addr_count += image_info.size;
		//qDebug() << image_addr_count << " image_info.size" << image_info.size;
	}
}


void ImageBinFun::PrintImageAddr(QList<image_info_t> image_info_list)
{
	int index = 0;
	QStringList addr_list;
	for each (image_info_t image_info in image_info_list)
	{

		if (index == 0)
		{
			if (image_info.size != 0)
			{
				QString image_title = getImageFormat(image_info.name, &image_format); //获取图片类型和标题	
				gui_flash_addr.append("\n");
				gui_flash_addr.append("#define ICON_" + image_title.toUpper() + "_SIZE  " + QString::number(image_info.size));
				gui_flash_addr.append("\n");
				gui_flash_addr.append("#define ICON_" + image_title.toUpper() + "_WIDE  " + QString::number(image_info.width));
				gui_flash_addr.append("\n");
				gui_flash_addr.append("#define ICON_" + image_title.toUpper() + "_HIGH  " + QString::number(image_info.height));
				gui_flash_addr.append("\n");
				gui_flash_addr.append("\n");
			/*	qDebug() << "";
				qDebug() << "ICON_" + image_title.toUpper() + "_SIZE  " + QString::number(image_info.size);
				qDebug() << "ICON_" + image_title.toUpper() + "_WIDE  " + QString::number(image_info.width);
				qDebug() << "ICON_" + image_title.toUpper() + "_HIGH  " + QString::number(image_info.height);

				qDebug() << "";*/
			}

		}
		index++;
#if	H02Q_UI
		int ui_start_addr = 0x8E000; //UI起始空间起始地址
		int offset_addr = 0xFD000 - ui_start_addr;
		int addr_count = 0x3000;  //0xFD000 ~ 0x10000  预留的空间
		int boot_end_addr = 0x100000; //预留空间结束地址
		

		int max_size_offset = image_addr_count + image_info.size;
		if ((max_size_offset > offset_addr) && (image_addr_count < offset_addr))
		{
			image_addr_count = boot_end_addr - ui_start_addr;  // FD000 - 93000
		}
#endif
		//qDebug() << "ICON_" + image_info.name.toUpper() + "_ADDR  " + QString::number(image_addr_count);
		gui_flash_addr.append("#define ICON_" + image_info.name.toUpper() + "_ADDR  " + QString::number(image_addr_count));
		gui_flash_addr.append("\n");
		//qDebug() << "image_addr_count" << image_addr_count;
		QString image_title = getImageFormat(image_info.name, &image_format); //获取图片类型和标题	
		addr_list.append("ICON_" + image_title.toUpper() + "_SIZE  ");
		
		image_addr_count += image_info.size;
		//qDebug() << image_addr_count << " image_info.size" << image_info.size;
	}

	QString image_title_first = getImageFormat(image_info_list.at(0).name, &image_format); //获取图片类型和标题

	gui_flash_size_array.append("const  uint32_t icon_" + image_title_first + "_size[" + QString::number(addr_list.count()) + "] = {\n");
	gui_flash_size_array_head.append("extern const  uint32_t icon_" + image_title_first + "_size[" + QString::number(addr_list.count()) + "];\n");
	for each (QString addr in addr_list)
	{

		gui_flash_size_array.append("\t" + addr + "," + "\n");
	}
	gui_flash_size_array.append("};\n\n");
}
void ImageBinFun::GetUiPath(ui_path_t *path)
{
	qDebug()<<"头文件路径" << gui_addr_head_path;
	path->ui_bin_path.append(gui_addr_bin_path);
	path->ui_head_path.append(gui_addr_head_path);
	

	
}

void ImageBinFun::PrintDialAddr(QList<image_info_t> image_info_list)
{
	int index = 0;
	
	QStringList addr_list;
	for each (image_info_t image_info in image_info_list)
	{
		if (index == 0)
		{
			QString image_title = getImageFormat(image_info.name, &image_format); //获取图片类型和标题	
			gui_flash_addr.append("\n");
			gui_flash_addr.append("#define ICON_" + image_title.toUpper() + "_WIDE  " + QString::number(image_info.width));
			gui_flash_addr.append("\n");
			gui_flash_addr.append("#define ICON_" + image_title.toUpper() + "_HIGH  " + QString::number(image_info.height));
			gui_flash_addr.append("\n");
			gui_flash_addr.append("\n");
		}
		index++;
		if (image_format == IMAGE_FORMAT_DIAL)
		{
			if (image_info.size > 8 * 1024)
			{
				gui_flash_addr.append("\r\n#error " + image_info.name.toUpper() + " out of rang 8*1024\r\n");
			}
		}
		gui_flash_addr.append("#define ICON_" + image_info.name.toUpper() + "_SIZE  " + QString::number(image_info.size));
		gui_flash_addr.append("\n");
		addr_list.append( "ICON_" +image_info.name.toUpper() + "_SIZE  ");
	
	}

	QString image_title_first = getImageFormat(image_info_list.at(0).name, &image_format); //获取图片类型和标题

		gui_flash_size_array.append("const  uint32_t icon_" + image_title_first + "_size[" + QString::number(addr_list.count()) + "] = {\n");
		gui_flash_size_array_head.append("extern const  uint32_t icon_" + image_title_first + "_size[" + QString::number(addr_list.count()) + "];\n");
		for each (QString addr in addr_list)
		{
			
			gui_flash_size_array.append("\t" + addr + "," + "\n");
		}
		gui_flash_size_array.append("};\n\n");
	
	

	gui_flash_addr.append("\n");
	for each (image_info_t image_info in image_info_list)
	{
		
		//qDebug() << "ICON_" + image_info.name.toUpper() + "_ADDR  " + QString::number(image_addr_count);
		gui_flash_addr.append("#define ICON_" + image_info.name.toUpper() + "_ADDR  " + QString::number(image_addr_count));
		gui_flash_addr.append("\n");
		//qDebug() << ">>>>>>>" << image_addr_count;
		image_addr_count += image_info.size;
	}
}

void ImageBinFun::SameImageSave(QStringList imageList, QString last_image_title)
{
	
	QJsonArray iconArray;
	QList<image_info_t> image_info_list;
	
	foreach(QString name, imageList)
	{
		iconArray.append(QJsonValue(name));
		image_info_t image_info = {0};	
		QString image_title = getImageFormat(name, &image_format); //获取图片类型和标题	
		image_info = getImageBinForFormat(image_format, name);//根据图片的类型转为bin
		image_info.name = name;
		image_info_list.append(image_info);	 //添加图片的信息

	}
	if (gui_is_compress != COMPRESS_NULL) //压缩
	{
		//
		 if (image_format == IMAGE_FORMAT_ALPHA)
		{
			PrintPngAddr(image_info_list);//打印地址信息
		}
		else
		{
			 PrintDialAddr(image_info_list); //打印地址信息
			
			
		}
	}
	else
	{
		//不压缩
		if (image_format == IMAGE_FORMAT_DIAL)
		{
			PrintDialAddr(image_info_list); //打印地址信息
		}
		else if (image_format == IMAGE_FORMAT_ALPHA)
		{
			PrintPngAddr(image_info_list);//打印地址信息
		}
		else
		{
			PrintImageAddr(image_info_list);//打印地址信息
		}
	}

	titleList.append(last_image_title);
	Title_Image_json.insert(last_image_title, iconArray); //保存title 对应所有image 的json
	
	
}

//获取图片全部路径
void ImageBinFun::getBmpPaths(QString path)
{
	QDir dir(path);

	foreach(QFileInfo fileInfo, dir.entryInfoList(QDir::Dirs | QDir::Files, QDir::DirsFirst))
	{
		if (fileInfo.isDir())
		{
			//目录遍历
			if (fileInfo.fileName() == "." || fileInfo.fileName() == "..")continue;
			//qDebug() << fileInfo.absolutePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐"
			//qDebug() << fileInfo.filePath(); //"F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
			//qDebug() << fileInfo.fileName(); //"音乐音量"
			//qDebug() << fileInfo.baseName(); //"音乐音量"
			//qDebug() << fileInfo.absoluteFilePath();// "F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐/音乐音量"
			//qDebug() << fileInfo.path();// "F:/Work/汇顶/h18T_f/设备UI文件/H18T_UI_1.2.6/切图/音乐"
			getBmpPaths(fileInfo.absoluteFilePath());


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
				Image_Path_Map.insert(icon_src, fileInfo.filePath());
			}
			else if (fileInfo.suffix() == "json")
			{
				//jsonfile(fileInfo.filePath());//获取坐标信息
			}

		}
	}
}

image_info_t ImageBinFun::getImageBinForFormat(IMAGE_FORMAT image_format , QString icon_name)
{
	//第一张获取图片信息
	image_info_t image_info = {0};
	QByteArray c_bmpbin;
	//QByteArray dstbin;
	switch (image_format)
	{
		case IMAGE_FORMAT_DIAL:
		
			image_info = BMPtobin::OpenPngToDial(Image_Path_Map.value(icon_name), &c_bmpbin, RGBA5658);
			break;
		case IMAGE_FORMAT_ALPHA:
			image_info = BMPtobin::OpenAlpha(Image_Path_Map.value(icon_name), &c_bmpbin, color_format);
			break;
		default:
			QByteArray srcbin;
			QByteArray dstbin;
			unsigned long dstlen = 0;
			image_info = BMPtobin::OpenBmp(Image_Path_Map.value(icon_name),&srcbin, color_format);
			if (gui_is_compress != COMPRESS_NULL)
			{
				//进行压缩
				if (gui_is_compress == COMPRESS_VEEPOO)
				{
					dstbin = vp_compress(srcbin);
#if 0 //是否开启压缩校验
					QByteArray  check_src = vp_decompress(dstbin);
					//qDebug() << "ICON_" + icon_name.toUpper() + "_ADDR  " + QString::number(test_conut);
					test_conut += dstbin.size();
					if (check_src != srcbin)
					{
						qDebug() << "vp压缩图片失败." << icon_name;
					}
#endif				
				}
				else if (gui_is_compress == COMPRESS_MINIZLO)
				{
					//minilzo 全部压缩
			        dstbin = minilzo_compress(srcbin);
#if 0 //是否开启压缩校验
			        QByteArray  check_src = minilzo_decompress(dstbin);
#endif
				}
				else 
				{
				  //分块压缩
					 minilzo_compressBlock(srcbin, &image_info, &dstbin);
#if 0 //是否开启压缩校验
					 int inntel = 20;
					 QByteArray  check_src;								
					 int image_height = image_info.height;
					 int i = 0;
				
					 while(image_height != 0)
					 {
						 int read_len = image_height > inntel ? inntel : image_height;
						 QByteArray  src = minilzo_GetBolckDate(&image_info, i, i + read_len, dstbin);
						
						 check_src.append(src);
						 image_height -= read_len;
						 i += read_len;
					 }
#endif				
			
			
				}
				if (!dstbin.isEmpty())
				{
					if (dstbin.size() > 0 && dstbin.size() < srcbin.size())
					{
						c_bmpbin.append(dstbin);
						image_info.size = dstbin.size();
					}
					else
					{
						//压缩失败
						c_bmpbin.append(srcbin);
						image_info.size = srcbin.size();
					}
				
				}
				else
				{
					//压缩失败
					c_bmpbin.append(srcbin); 
					image_info.size = srcbin.size();
				}
			}
			else
			{
				c_bmpbin.append(srcbin);
				image_info.size = srcbin.size();
			}		
			break;
	}
#if H02Q_UI
	//0xFD000 - 0x8E000
	int ui_start_addr = 0x8E000;  //UI起始地址
	int boot_start_addr = 0xFD000; //boot起始地址
	int boot_end_addr = 0x100000;//结束起始地址
	int offset_addr = boot_start_addr - ui_start_addr; //前面可以合成ui的空间，超过这个就跳过至
	int addr_count = boot_end_addr - boot_start_addr;  //0xFD000 ~ 0x10000  预留的空间
	int max_size_offset = bmpbin.size() + c_bmpbin.size();
	if ((max_size_offset  > offset_addr) && (bmpbin.size()  < offset_addr))
	{
		int offset = (offset_addr - bmpbin.size()) + addr_count;  // 一张图片无法放下剩下的需补充，并补充预留空间 0xff
		for (int i = 0; i < offset ; i++)
		{
			QByteArray da;
			da.append(0xff);
			bmpbin.append(da);
		}
	}
#endif
	bmpbin.append(c_bmpbin);
	return image_info;


	
}
void ImageBinFun::saveBmpPaths(QString path)
{
	gui_addr_head_path.clear();
	gui_addr_bin_path.clear();
	Image_Path_Map.clear();
	titleList.clear();
	bmpbin.clear();
	gui_flash_addr.clear();
	getBmpPaths(path);  //从目录遍历获取到切图文件
	if (minilzo_init() == false) //初始化minilzo
	{
		qDebug() << " minilzo_init error!";
	}

	if (Image_Path_Map.isEmpty())
	{
		qDebug() << "get image error !";
	}
	else
	{
		QString last_image_title; //相同大小类型的切图以前下划线的前两个作为区分
		QStringList imageList;
		image_addr_count = 0;  //切图起始地址 
		foreach(QString key, Image_Path_Map.keys())
		{		
			QString image_title;
			image_title = getImageFormat(key,&image_format); //获取图片类型和标题
			if (last_image_title != image_title)
			{
				if (!last_image_title.isEmpty() && !imageList.isEmpty())
				{

					//保存前两位的标题（035main_data4）和对应的所有切图（s035main_data4_mlg_00","s035main_data4_mlg_01","s035main_data4_mlg_02","s035main_data4_mlg_03","s035main_data4_mlg_04"）				
					SameImageSave(imageList, last_image_title);
					imageList.clear();
				}
				last_image_title = image_title;
			}
			imageList.append(key);
			//qDebug() << Image_Path_Map.value(key);
		}
		//最后一次也要添加
		if (!last_image_title.isEmpty() && !imageList.isEmpty())
		{

			//保存前两位的标题（035main_data4）和对应的所有切图（s035main_data4_mlg_00","s035main_data4_mlg_01","s035main_data4_mlg_02","s035main_data4_mlg_03","s035main_data4_mlg_04"）
			SameImageSave(imageList, last_image_title);
			imageList.clear();

		}
		//将bin保存为文件
		if (!bmpbin.isEmpty())
		{
			qDebug() << "生成的UI bin 大小." << bmpbin.size();
			QFileInfo fileInfo(path);
			QString abs_path = fileInfo.absolutePath();
			QDateTime date_time = QDateTime::currentDateTime();
			QString date = date_time.toString("yyyyMMddmmsszzz"); //时间
			gui_addr_bin_path = abs_path + "/gui_falsh_data_" + date + ".bin"; //bin文件路径
			QFile savebinfile(gui_addr_bin_path);
			if (savebinfile.open(QIODevice::WriteOnly))
			{
				savebinfile.write(bmpbin);
			}
			savebinfile.close();
		}
		//保存地址信息文件
		if (!gui_flash_addr.isEmpty())
		{
			//qDebug() << "gui_flash_addr" << gui_flash_addr.size(); 
			gui_flash_addr.append("\n");
			gui_flash_addr.append("\n");
			gui_flash_addr.append("#define ALL_DATA_SIZE  "  + QString::number(bmpbin.size())); //保存总的文件大小
			gui_flash_addr.append("\n");
			//gui_flash_addr.append("#define DATA_CRC_BUF  0x22" );
			gui_flash_addr.append("\n");
			QFileInfo fileInfo(path);
			QString abs_path = fileInfo.absolutePath();
			QDateTime date_time = QDateTime::currentDateTime();
			QString date = date_time.toString("yyyyMMddmmsszzz"); //时间
			gui_addr_head_path = abs_path + "/gui_falsh_addr_" + date + ".h";
			QFile savebinfile(gui_addr_head_path);
			if (savebinfile.open(QIODevice::WriteOnly))
			{
				savebinfile.write(gui_flash_addr.toLocal8Bit());
			}
			savebinfile.close();

		}
		if (gui_is_compress != COMPRESS_NULL)
		{
			//生成size 数组
			if (!gui_flash_size_array.isEmpty())
			{
				QFileInfo fileInfo(path);
				QString abs_path = fileInfo.absolutePath();
				QDateTime date_time = QDateTime::currentDateTime();
				QString date = date_time.toString("yyyyMMddmmsszzz"); //时间
				QFile savebinfile(abs_path + "/gui_falsh_size_array_" + date + ".c");
				if (savebinfile.open(QIODevice::WriteOnly))
				{
					savebinfile.write(gui_flash_size_array.toLocal8Bit());
				}
				savebinfile.close();
			

			}
			//生成size 数组头文件
			if (!gui_flash_size_array_head.isEmpty())
			{
				QFileInfo fileInfo(path);
				QString abs_path = fileInfo.absolutePath();
				QDateTime date_time = QDateTime::currentDateTime();
				QString date = date_time.toString("yyyyMMddmmsszzz"); //时间
				QFile savebinfile(abs_path + "/gui_falsh_size_array_" + date + ".h");
				if (savebinfile.open(QIODevice::WriteOnly))
				{
					savebinfile.write(gui_flash_size_array_head.toLocal8Bit());
				}
				savebinfile.close();

			}

		}

		
	}
}