#include "Veepoolzo.h"
#include <QBYTEARRAY.H>
//
//  veepoolzo.c
//  testMiniLZO
//
//  Created by zhangchong on 2021/11/15.
//

#include <string.h>
#define match_max 255

int Veepoolzo::veepoo_compress(const unsigned char* src, unsigned long src_len, unsigned char* dst, unsigned long* dst_len) {

    //当前指向压缩的地址
    veepoo_ulong currect_ip = 0;

    //压缩数据要复制的地址
    veepoo_ulong dst_ip = 0;


    //相同数据的个数
    veepoo_ulong match_count = 0;

    //不相同数据匹配的个数
    veepoo_ulong no_match_count = 0;

    //初始化第一个数据
    unsigned char first_number = src[0];
    while (1) {
        for (veepoo_ulong i = 0; ; i++) {
            if (src[currect_ip + i] == first_number) { //与上一个数据相同，匹配数据加1
                match_count++;
            }
            else {//如果和上一个不一致，如果匹配相同的大于3个，结束，如果小于三个继续匹配
                if (match_count < 3) {//小于3个继续往下找3个及3个以上相同的
                    match_count = 1;
                }
                else {//如果匹配到三个及以上，结束
                   //查看不相同数据的个数
                    no_match_count = i - match_count;

                    veepoo_ulong no_match_count_p1 = no_match_count % match_max;
                    veepoo_ulong no_match_count_p = (no_match_count_p1 == 0) ? (no_match_count / match_max) : (no_match_count / match_max + 1);

                    veepoo_ulong match_count_p1 = match_count % match_max;
                    veepoo_ulong match_count_p = (match_count_p1 == 0) ? (match_count / match_max) : (match_count / match_max + 1);


                    //不相同的
                    for (int k = 0; k < no_match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == no_match_count_p - 1) {
                            count = (no_match_count_p1 == 0) ? match_max : no_match_count_p1;
                        }
                        dst[dst_ip] = 0;
                        dst[dst_ip + 1] = count;
                        memcpy(dst + dst_ip + 2, src + currect_ip + k * match_max, count);
                        dst_ip = dst_ip + count + 2;
                    }

                    //相同的
                    for (int k = 0; k < match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == match_count_p - 1) {
                            count = (match_count_p1 == 0) ? match_max : match_count_p1;
                        }
                        dst[dst_ip] = count;
                        dst[dst_ip + 1] = first_number;
                        dst_ip = dst_ip + 2;
                    }


                    //重新初始化
                    match_count = 0;
                    first_number = src[currect_ip + i];

                    //重新定向当前的ip

                    if (currect_ip + i + 1 >= src_len) {//没有数据了

                    }
                    else {
                        currect_ip = currect_ip + i;
                        break;
                    }
                }
            }
            //重新定制一个数据
            first_number = src[currect_ip + i];

            //没有数据的处理
            if (currect_ip + i + 1 >= src_len) {//没有数据了
                if (match_count >= 3) {//如果匹配到三个及以上
                    //拆分255一包
                    //查看不相同数据的个数
                    no_match_count = i - match_count + 1;

                    veepoo_ulong no_match_count_p1 = no_match_count % match_max;
                    veepoo_ulong no_match_count_p = (no_match_count_p1 == 0) ? (no_match_count / match_max) : (no_match_count / match_max + 1);

                    veepoo_ulong match_count_p1 = match_count % match_max;
                    veepoo_ulong match_count_p = (match_count_p1 == 0) ? (match_count / match_max) : (match_count / match_max + 1);

                    //不相同的
                    for (int k = 0; k < no_match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == no_match_count_p - 1) {//最后一包
                            count = (no_match_count_p1 == 0) ? match_max : no_match_count_p1;
                        }
                        dst[dst_ip] = 0;
                        dst[dst_ip + 1] = count;
                        memcpy(dst + dst_ip + 2, src + currect_ip + k * match_max, count);
                        dst_ip = dst_ip + count + 2;
                    }

                    //相同的
                    for (int k = 0; k < match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == match_count_p - 1) {//最后一包
                            count = (match_count_p1 == 0) ? match_max : match_count_p1;
                        }
                        dst[dst_ip] = count;
                        dst[dst_ip + 1] = first_number;
                        dst_ip = dst_ip + 2;
                    }
                }
                else {//全部不相同
                   //全部不相同，完全不匹配的数量就是i+1
                    no_match_count = i + 1;
                    //拆分255一包
                    veepoo_ulong no_match_count_p1 = no_match_count % match_max;
                    veepoo_ulong no_match_count_p = (no_match_count_p1 == 0) ? (no_match_count / match_max) : (no_match_count / match_max + 1);
                    //不相同的
                    for (int k = 0; k < no_match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == no_match_count_p - 1) {//最后一包
                            count = (no_match_count_p1 == 0) ? match_max : no_match_count_p1;
                        }
                        dst[dst_ip] = 0;
                        dst[dst_ip + 1] = count;
                        memcpy(dst + dst_ip + 2, src + currect_ip + k * match_max, count);
                        dst_ip = dst_ip + count + 2;
                    }

                }
                *dst_len = dst_ip;
                return 1;
            }
        }
    }

    return 0;
}


int Veepoolzo::veepoo_decompress(const unsigned char* src, unsigned long src_len, unsigned char* dst, unsigned long* dst_len, unsigned long* current_index) {
    if (src_len < 2) {//长度不符合，最少要2个字节
        return 0;
    }
    //当前指向压缩的地址
    unsigned long currect_ip = 0;
    //下一个指向压缩的地址
    unsigned long next_ip = 0;
    //压缩数据要复制的地址
    unsigned long dst_ip = 0;

    while (1) {
        if (next_ip >= src_len - 1) {//全部解析完成
            //解压后数据的长度
            *dst_len = dst_ip;
            *current_index = next_ip;
            return 1;
        }
        currect_ip = next_ip;
        //开始如何解析
        if (src[currect_ip] == 0) {//开始从不重复开始
            next_ip = next_ip + src[currect_ip + 1] + 2;
            if (next_ip <= src_len) {
                //赋值,这里如何能copy更快速
                memcpy(dst + dst_ip, src + currect_ip + 2, src[currect_ip + 1]);
            }
            else {//剩余数据不够解析
                *current_index = currect_ip;
                *dst_len = dst_ip;
                return 0;
            }
            //下一个数据复制地址
            dst_ip = dst_ip + src[currect_ip + 1];
        }
        else {//开始从重复开始
            next_ip = next_ip + 2;
            //赋值,这里如何能copy更快速
            memset(dst + dst_ip, src[currect_ip + 1], src[currect_ip]);
            //下一个数据复制地址
            dst_ip = dst_ip + src[currect_ip];
        }
    }
    return 0;
}
