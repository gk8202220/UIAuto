//
//  veepoolzo.h
//  testMiniLZO
//
//  Created by zhangchong on 2021/11/15.
//

#ifndef veepoolzo_h
#define veepoolzo_h

#include <stdio.h>

typedef unsigned long      veepoo_ulong;

class Veepoolzo
{
public:
	/// 压缩接口
	/// @param src 压缩数据源
	/// @param src_len 压缩数据源 数据长度
	/// @param dst 压缩后的数据
	/// @param dst_len 压缩后数据的长度
	static int veepoo_compress(const unsigned char* src, unsigned long src_len,  unsigned char* dst, unsigned long* dst_len);


	/// 解压接口
	/// @param src 解压前的数据源
	/// @param src_len 解压前的数据源 数据长度
	/// @param dst 解压后的数据
	/// @param dst_len 解压后数据的长度
	/// @param current_index 解压后指向解压数据最后的位置
	static int veepoo_decompress(const unsigned char* src, unsigned long src_len, unsigned char* dst, unsigned long* dst_len, unsigned long* current_index);


};

#endif /* veepoolzo_h */

