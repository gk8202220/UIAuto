#pragma once

#ifndef MINITEST_H
#define MINITEST_H

#include <stdio.h>
#include <stdlib.h>
#include "minilzo.h"

#define IN_LEN      3547352 //整块解压时为原始文件大小 ， 分块解压时为块大小
#define OUT_LEN     (IN_LEN + IN_LEN / 16 + 64 + 3)

#define HEAP_ALLOC(var,size) \
    lzo_align_t __LZO_MMODEL var [ ((size) + (sizeof(lzo_align_t) - 1)) / sizeof(lzo_align_t) ]

#define IN_SRC_FILE_PATH                "Air_H_02Q_6245_UI_V1.1_CRC_8B06_20211105.bin"
#define ZIP_FILE_PATH                   "H_02Q_6245_UI_V1.0_zip_CRC_BC0D_20211125.bin"
#define UPZIP_FILE_PATH                 "zzzz_upzip.bin"
#define SIZE_FILE_PATH                  "zzzz.txt"

static HEAP_ALLOC(wrkmem, LZO1X_1_MEM_COMPRESS);

unsigned long TestMiniLZO(unsigned long _Len, unsigned char* src_data, unsigned char* dst_data);
unsigned long minilzo_compression(unsigned long uzip_len, unsigned char* src_data, unsigned char* dst_data);
unsigned long minilzo_decompression(unsigned long zip_len, unsigned long uzip_len, unsigned char* src_data, unsigned char* dst_data);

#endif

