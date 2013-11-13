/*
 * File:   function.h
 * Author: Zhe Fu
 * Date:   13-11-10
 * 
 * Description: This is the .h file for functions
 * 
 */

#include "stdio.h"
#include "math.h"

int media_len;
int origin_len;

// 阶乘
int fac(int n);

// 获得int型数的位数
int intlen(int n);

// 十进制转递增进制中介数
int dec2in(int dec);

// 十进制转递减进制中介数
int dec2de(int dec);

// 递增进制中介数转十进制数
int in2dec(int in);

// 递减进制中介数转十进制数
int de2dec(int de);

// 排列按字典序法生成中介数
int p2media_dic(int Originnum);

// 排列递增进制排列法生成中介数
int p2media_in(int Originnum);

// 排列按递减进制排列法生成中介数
int p2media_de(int Originnum);

// 排列按邻位对换法生成中介数
int p2media_swap(int Originnum);

// 按字典序法从中介数还原成排列
int media2p_dic(int media);

// 按递增进制排列法从中介数还原成排列
int media2p_in(int media);

// 按递减进制排列法从中介数还原成排列
int media2p_de(int media);

// 按邻位对换法从中介数还原成排列
int media2p_swap(int media);
