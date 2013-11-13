/*
 * File:   function.c
 * Author: Zhe Fu
 * Date:   13-11-10
 * 
 * Description: This is the .c file for functions
 * 
 */

#include "stdio.h"
#include "function.h"

// 阶乘
int fac(int n){
 	int res = 1;
 	while(n >= 2){
 		res = res * (n--);
 	}
 	return res;
 }

// 获得int型数的位数
int intlen(int n){
    int i = 1;
    while (1) {
        if (pow(10, i) > n) break;
        else i += 1;
    }
    return i;
}

// 十进制转递增进制中介数
int dec2in(int dec){
    int i = 0, x = 1;
    int temp = 0;
    int res = 0;
    while (1) {
        if (fac(x) > dec) break;
        x += 1;
    }
    while (1) {
        x -= 1;
        if (x == 0) break;
        temp = dec / fac(x);
        dec -= fac(x) * temp;
        res = res * 10 + temp;
        i += 1;
    }
    return res;
}

// 十进制转递减进制中介数
int dec2de(int dec){
    int res = 0;
    int i, temp;
    for (i = origin_len; i > 0; i--) {
        temp = dec % i;
        res += temp * pow(10, origin_len - i);
        dec = (dec - temp) / i;
    }
    return res;
}

// 递增进制中介数转十进制数
int in2dec(int in){
    int i, temp;
    int res = 0;
    for (i = media_len; i > 0; i--) {
        temp = in / pow(10, i - 1);
        res += temp * fac(i);
        in -= temp * pow(10, i - 1);
    }
    return res;
}

// 递减进制中介数转十进制数
int de2dec(int de){
    int res = 0;
    int len = intlen(de);
    int i, temp;
    for (i = 0; i < len; i++) {
        temp = de % 10;
        res += temp * fac(origin_len) / fac(origin_len - i);
        de = de / 10;
    }
    return res;
}

// 排列按字典序法生成中介数
int p2media_dic(int Originnum){
    int media = 0, count = 0;
    int i, j;
    int array[origin_len];
    for (i = 0; i < origin_len; i++) {
        array[i] = Originnum / pow(10, origin_len - i - 1);
        Originnum -= array[i] * pow(10, origin_len - i - 1);
    }
    for (i = 0; i < origin_len; i++) {
        count = 0;
        for (j = i + 1; j < origin_len; j++)
            if (array[i] > array[j]) count += 1;
        media += count * pow(10, origin_len - i - 2);
    }
    return media;
}

// 排列递增进制排列法生成中介数
int p2media_in(int Originnum){
    int media = 0, count = 0;
    int i, j, k;
    int array[origin_len];
    for (i = 0; i < origin_len; i++) {
        array[i] = Originnum / pow(10, origin_len - i - 1);
        Originnum -= array[i] * pow(10, origin_len - i - 1);
    }
    for (i = origin_len; i > 0; i--) {
        for (j = 0; j < origin_len; j++) {
            if (array[j] == i) {
                count = 0;
                for (k = j + 1; k < origin_len; k++) {
                    if (array[k] < i) count += 1;
                }
                break;
            }
        }
        media += count * pow(10, i - 2);
    }
    return media;
}

// 排列按递减进制排列法生成中介数
int p2media_de(int Originnum){
    int media = 0, count = 0;
    int i, j, k;
    int array[origin_len];
    for (i = 0; i < origin_len; i++) {
        array[i] = Originnum / pow(10, origin_len - i - 1);
        Originnum -= array[i] * pow(10, origin_len - i - 1);
    }
    for (i = origin_len; i > 0; i--) {
        for (j = 0; j < origin_len; j++) {
            if (array[j] == i) {
                count = 0;
                for (k = j + 1; k < origin_len; k++) {
                    if (array[k] < i) count += 1;
                }
                break;
            }
        }
        media += count * pow(10, origin_len - i);
    }
    return media;
}

// 排列按邻位对换法生成中介数
int p2media_swap(int Originnum){
    int res = 0;
    int i, j;
    int count = 0;
    int direction_array[media_len];
    int origin_array[origin_len];
    int media_array[media_len];
    for (i = 0; i < origin_len; i++) {
        origin_array[i] = Originnum / pow(10, origin_len - i - 1);
        Originnum -= origin_array[i] * pow(10, origin_len - i - 1);
    }
    for (i = 0; i < origin_len; i++) {
        if (origin_array[i] == 2) break;
    }
    
    direction_array[0] = 0; // 0 for left
    for (i = origin_len - 1; i >= 0; i--) {
        if (origin_array[i] < 2) count += 1;
        else if (origin_array[i] == 2) break;
    }
    media_array[0] = count;
    
    for (i = 1; i < media_len; i++) {
        count = 0;
        if (i % 2 == 1 ) {
            if (media_array[i - 1] % 2 == 1) direction_array[i] = 1;
            else direction_array[i] = 0;
        }
        else {
            if ((media_array[i - 1] + media_array[i - 2]) % 2 == 1) direction_array[i] = 1;
            else direction_array[i] = 0;
        }
        if (direction_array[i] == 0){
            for (j = origin_len - 1; j >= 0; j--) {
                if (origin_array[j] < (i + 2)) count += 1;
                else if (origin_array[j] == (i + 2)) break;
            }
            media_array[i] = count;
        }
        else{
            for (j = 0; j < origin_len; j++) {
                if (origin_array[j] < (i + 2)) count += 1;
                else if (origin_array[j] == (i + 2)) break;
            }
            media_array[i] = count;
        }
    }
    for (i = 0; i < media_len; i++) {
        res += media_array[i] * pow(10, media_len - i - 1);
    }
    return res;
}

// 按字典序法从中介数还原成排列
int media2p_dic(int media){
    int sum = (origin_len) * (1 + origin_len) / 2;
    int res = 0;
    int count, temp, i, j;
    int media_array[media_len];
    int assist_array[origin_len];
    for (i = 0; i < media_len; i++) {
        media_array[i] = media / pow(10, media_len - i - 1);
        media -= media_array[i] * pow(10, media_len - i - 1);
    }
    for (i = 0; i < origin_len; i++) {
        assist_array[i] = i + 1;
    }
    for (i = 0; i < media_len; i++) {
        count = 0;
        for (j = 0; j < origin_len; j++){
            if (assist_array[j] != 0) count += 1;
            if (count == (media_array[i] + 1)) {
                temp = assist_array[j];
                assist_array[j] = 0;
                sum -= temp;
                break;
            }
        }
        res += temp * pow(10, media_len - i);
    }
    res += sum;
    return res;
}

// 按递增进制排列法从中介数还原成排列
int media2p_in(int media){
    int sum = (origin_len) * (1 + origin_len) / 2;
    int res = 0;
    int count = 0;
    int temp = origin_len;
    int i, j;
    int media_array[media_len];
    int assist_array[origin_len];
    for (i = 0; i < media_len; i++) {
        media_array[i] = media / pow(10, media_len - i - 1);
        media -= media_array[i] * pow(10, media_len - i - 1);
    }
    for (i = 0; i < origin_len; i++) {
        assist_array[i] = 0;
    }
    for (i = 0; i < media_len; i++) {
        count = 0;
        for (j = origin_len - 1; j >= 0; j--) {
            if (assist_array[j] == 0) count += 1;
            if (count == (media_array[i] + 1)) {
                assist_array[j] = temp;
                temp -= 1;
                sum -= (j + 1);
                break;
            }
        }
    }
    assist_array[sum - 1] = 1;
    for (i = 0; i < origin_len; i++) {
        res += assist_array[i] * pow(10, origin_len - i - 1);
    }
    return res;
}

// 按递减进制排列法从中介数还原成排列
int media2p_de(int media){
    int sum = (origin_len) * (1 + origin_len) / 2;
    int res = 0;
    int count = 0;
    int temp = origin_len;
    int i, j;
    int media_array[media_len];
    int assist_array[origin_len];
    for (i = 0; i < media_len; i++) {
        media_array[i] = media / pow(10, media_len - i - 1);
        media -= media_array[i] * pow(10, media_len - i - 1);
    }
    for (i = 0; i < origin_len; i++) {
        assist_array[i] = 0;
    }
    for (i = media_len - 1; i >= 0; i--) {
        count = 0;
        for (j = origin_len - 1; j >= 0; j--) {
            if (assist_array[j] == 0) count += 1;
            if (count == (media_array[i] + 1)) {
                assist_array[j] = temp;
                temp -= 1;
                sum -= (j + 1);
                break;
            }
        }
    }
    assist_array[sum - 1] = 1;
    for (i = 0; i < origin_len; i++) {
        res += assist_array[i] * pow(10, origin_len - i - 1);
    }
    return res;
}

// 按邻位对换法从中介数还原成排列
int media2p_swap(int media){
    int res = 0;
    int i, j, count;
    int p_array[origin_len];
    int media_array[media_len];
    for (i = 0; i < media_len; i++) {
        media_array[i] = media / pow(10, media_len - i - 1);
        media -= media_array[i] * pow(10, media_len - i - 1);
    }
    for (i = 0; i < origin_len; i++) {
        p_array[i] = 0;
    }
    
    for (i = origin_len; i > 2; i--) {
        if (i % 2 == 1){
            if (media_array[i - 3] % 2 == 0){
                count = 0;
                for (j = origin_len - 1; j >= 0; j--) {
                    if (p_array[j] == 0) count += 1;
                    if (count == (media_array[i - 2] + 1)) {
                        p_array[j] = i;
                        break;
                    }
                }
            }
            else {
                count = 0;
                for (j = 0; j < origin_len; j++) {
                    if (p_array[j] == 0) count += 1;
                    if (count == (media_array[i - 2] + 1)) {
                        p_array[j] = i;
                        break;
                    }
                }
            }
        }
        else {
            if ((media_array[i - 3] + media_array[i - 4]) % 2 == 0){
                count = 0;
                for (j = origin_len - 1; j >= 0; j--) {
                    if (p_array[j] == 0) count += 1;
                    if (count == (media_array[i - 2] + 1)) {
                        p_array[j] = i;
                        break;
                    }
                }
            }
            else {
                count = 0;
                for (j = 0; j < origin_len; j++) {
                    if (p_array[j] == 0) count += 1;
                    if (count == (media_array[i - 2] + 1)) {
                        p_array[j] = i;
                        break;
                    }
                }
            }
        }
    }
    count = 0;
    for (j = origin_len - 1; j >= 0; j--) {
        if (p_array[j] == 0) count += 1;
        if (count == media_array[0] + 1){
            p_array[j] = 2;
            break;
        }
    }
    for (j = origin_len - 1; j >= 0; j--) {
        if (p_array[j] == 0) {
            p_array[j] = 1;
            break;
        }
    }
    for (j = 0; j < origin_len; j++) {
        res += p_array[j] * pow(10, origin_len - j - 1);
    }
    return res;
}
