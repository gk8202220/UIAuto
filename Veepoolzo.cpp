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

    //��ǰָ��ѹ���ĵ�ַ
    veepoo_ulong currect_ip = 0;

    //ѹ������Ҫ���Ƶĵ�ַ
    veepoo_ulong dst_ip = 0;


    //��ͬ���ݵĸ���
    veepoo_ulong match_count = 0;

    //����ͬ����ƥ��ĸ���
    veepoo_ulong no_match_count = 0;

    //��ʼ����һ������
    unsigned char first_number = src[0];
    while (1) {
        for (veepoo_ulong i = 0; ; i++) {
            if (src[currect_ip + i] == first_number) { //����һ��������ͬ��ƥ�����ݼ�1
                match_count++;
            }
            else {//�������һ����һ�£����ƥ����ͬ�Ĵ���3�������������С����������ƥ��
                if (match_count < 3) {//С��3������������3����3��������ͬ��
                    match_count = 1;
                }
                else {//���ƥ�䵽���������ϣ�����
                   //�鿴����ͬ���ݵĸ���
                    no_match_count = i - match_count;

                    veepoo_ulong no_match_count_p1 = no_match_count % match_max;
                    veepoo_ulong no_match_count_p = (no_match_count_p1 == 0) ? (no_match_count / match_max) : (no_match_count / match_max + 1);

                    veepoo_ulong match_count_p1 = match_count % match_max;
                    veepoo_ulong match_count_p = (match_count_p1 == 0) ? (match_count / match_max) : (match_count / match_max + 1);


                    //����ͬ��
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

                    //��ͬ��
                    for (int k = 0; k < match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == match_count_p - 1) {
                            count = (match_count_p1 == 0) ? match_max : match_count_p1;
                        }
                        dst[dst_ip] = count;
                        dst[dst_ip + 1] = first_number;
                        dst_ip = dst_ip + 2;
                    }


                    //���³�ʼ��
                    match_count = 0;
                    first_number = src[currect_ip + i];

                    //���¶���ǰ��ip

                    if (currect_ip + i + 1 >= src_len) {//û��������

                    }
                    else {
                        currect_ip = currect_ip + i;
                        break;
                    }
                }
            }
            //���¶���һ������
            first_number = src[currect_ip + i];

            //û�����ݵĴ���
            if (currect_ip + i + 1 >= src_len) {//û��������
                if (match_count >= 3) {//���ƥ�䵽����������
                    //���255һ��
                    //�鿴����ͬ���ݵĸ���
                    no_match_count = i - match_count + 1;

                    veepoo_ulong no_match_count_p1 = no_match_count % match_max;
                    veepoo_ulong no_match_count_p = (no_match_count_p1 == 0) ? (no_match_count / match_max) : (no_match_count / match_max + 1);

                    veepoo_ulong match_count_p1 = match_count % match_max;
                    veepoo_ulong match_count_p = (match_count_p1 == 0) ? (match_count / match_max) : (match_count / match_max + 1);

                    //����ͬ��
                    for (int k = 0; k < no_match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == no_match_count_p - 1) {//���һ��
                            count = (no_match_count_p1 == 0) ? match_max : no_match_count_p1;
                        }
                        dst[dst_ip] = 0;
                        dst[dst_ip + 1] = count;
                        memcpy(dst + dst_ip + 2, src + currect_ip + k * match_max, count);
                        dst_ip = dst_ip + count + 2;
                    }

                    //��ͬ��
                    for (int k = 0; k < match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == match_count_p - 1) {//���һ��
                            count = (match_count_p1 == 0) ? match_max : match_count_p1;
                        }
                        dst[dst_ip] = count;
                        dst[dst_ip + 1] = first_number;
                        dst_ip = dst_ip + 2;
                    }
                }
                else {//ȫ������ͬ
                   //ȫ������ͬ����ȫ��ƥ�����������i+1
                    no_match_count = i + 1;
                    //���255һ��
                    veepoo_ulong no_match_count_p1 = no_match_count % match_max;
                    veepoo_ulong no_match_count_p = (no_match_count_p1 == 0) ? (no_match_count / match_max) : (no_match_count / match_max + 1);
                    //����ͬ��
                    for (int k = 0; k < no_match_count_p; k++) {
                        veepoo_ulong count = match_max;
                        if (k == no_match_count_p - 1) {//���һ��
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
    if (src_len < 2) {//���Ȳ����ϣ�����Ҫ2���ֽ�
        return 0;
    }
    //��ǰָ��ѹ���ĵ�ַ
    unsigned long currect_ip = 0;
    //��һ��ָ��ѹ���ĵ�ַ
    unsigned long next_ip = 0;
    //ѹ������Ҫ���Ƶĵ�ַ
    unsigned long dst_ip = 0;

    while (1) {
        if (next_ip >= src_len - 1) {//ȫ���������
            //��ѹ�����ݵĳ���
            *dst_len = dst_ip;
            *current_index = next_ip;
            return 1;
        }
        currect_ip = next_ip;
        //��ʼ��ν���
        if (src[currect_ip] == 0) {//��ʼ�Ӳ��ظ���ʼ
            next_ip = next_ip + src[currect_ip + 1] + 2;
            if (next_ip <= src_len) {
                //��ֵ,���������copy������
                memcpy(dst + dst_ip, src + currect_ip + 2, src[currect_ip + 1]);
            }
            else {//ʣ�����ݲ�������
                *current_index = currect_ip;
                *dst_len = dst_ip;
                return 0;
            }
            //��һ�����ݸ��Ƶ�ַ
            dst_ip = dst_ip + src[currect_ip + 1];
        }
        else {//��ʼ���ظ���ʼ
            next_ip = next_ip + 2;
            //��ֵ,���������copy������
            memset(dst + dst_ip, src[currect_ip + 1], src[currect_ip]);
            //��һ�����ݸ��Ƶ�ַ
            dst_ip = dst_ip + src[currect_ip];
        }
    }
    return 0;
}
