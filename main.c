/*
 * File:   main.c
 * Author: Zhe Fu
 * Date:   13-11-10
 * 
 * Description: This is the main entry file
 * 
 */

#include "stdio.h"
#include "function.h"
#include <sys/time.h>

void p_dic(int print){
	printf("\n字典序法\n");
	int result;
	struct timeval start,end;
	gettimeofday(&start,NULL);
	if (print == 1){
	    for (int i = 0; i< fac(origin_len); i++) {
			printf("%d\n", media2p_dic(dec2in(i)));
	    }
	}
	else{
		for (int i = 0; i< fac(origin_len); i++) {
			media2p_dic(dec2in(i));
	    }		
	}
    gettimeofday(&end,NULL);
    long temp = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000;
	printf("\n所用时间: %ld ms\n\n", temp);
}

void p_in(int print){
	printf("\n递增进制法\n");
	int result;
	struct timeval start,end;
	gettimeofday(&start,NULL);
	if (print == 1){
	    for (int i = 0; i< fac(origin_len); i++) {
			printf("%d\n", media2p_in(dec2in(i)));
	    }
	}
	else{
		for (int i = 0; i< fac(origin_len); i++) {
			media2p_in(dec2in(i));
	    }		
	}
    gettimeofday(&end,NULL);
    long temp = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000;
	printf("\n\n所用时间: %ld ms\n\n", temp);
}

void p_de(int print){
	printf("\n递减进制法\n");
	int result;
	struct timeval start,end;
	gettimeofday(&start,NULL);
	if (print == 1){
	    for (int i = 0; i< fac(origin_len); i++) {
			printf("%d\n", media2p_de(dec2de(i)));
	    }
	}
	else{
		for (int i = 0; i< fac(origin_len); i++) {
			media2p_de(dec2de(i));
	    }		
	}
    gettimeofday(&end,NULL);
    long temp = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000;
	printf("\n\n所用时间: %ld ms\n\n", temp);
}

void p_swap(int print){
	printf("\n邻位对换法\n");
	struct timeval start,end;
	gettimeofday(&start,NULL);
	if (print == 1){
	    for (int i = 0; i< fac(origin_len); i++) {
			printf("%d\n", media2p_swap(dec2de(i)));
	    }
	}
	else{
		for (int i = 0; i< fac(origin_len); i++) {
			media2p_swap(dec2de(i));
	    }		
	}
    gettimeofday(&end,NULL);
    long temp = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000;
	printf("\n\n所用时间: %ld ms\n\n", temp);
}

void p_all(int print){
    printf("字典序法\t递增进制法\t递减进制法\t邻位对换法\n");
	int result;
	struct timeval start,end;
	gettimeofday(&start,NULL);
	if (print == 1){
	    for (int i = 0; i< fac(origin_len); i++) {
			printf("%d\t", media2p_dic(dec2in(i)));
			printf("%d\t", media2p_in(dec2in(i)));
			printf("%d\t", media2p_de(dec2de(i)));
			printf("%d\n", media2p_swap(dec2de(i)));
	    }
	}
	else{
		for (int i = 0; i< fac(origin_len); i++) {
			media2p_dic(dec2in(i));
			media2p_in(dec2in(i));
			media2p_de(dec2de(i));
			media2p_swap(dec2de(i));
	    }		
	}
    gettimeofday(&end,NULL);
    long temp = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000;
	printf("\n\n所用时间: %ld ms\n\n", temp);
}

void full_permutation(){
	char c;
	int print;
	printf("\n");
	printf("输入(2~9)中一个数: ");
	scanf(" %d", &origin_len);
	media_len = origin_len - 1;
	printf("\n");
	printf("进行%d位数的全排列，使用:\n", origin_len);
	printf("[1] 字典序法\n");
	printf("[2] 递增进制法\n");
	printf("[3] 递减进制法\n");
	printf("[4] 邻位对换法\n");
	printf("[0] 以上所有方法\n");
	printf("\n");
	printf("请输入序号: ");
	scanf(" %c", &c);
	printf("\n");
	printf("是否输出所有结果? [1] 输出 [2] 不输出\n");
	printf("\n");
	printf("请输入序号: ");
	scanf(" %d", &print);
	switch(c){
		case '1': p_dic(print); break;
		case '2': p_in(print); break;
		case '3': p_de(print); break;
		case '4': p_swap(print); break;
		default: p_all(print); break;
    }

}

void specified_permutation(){
	char c;
	int num, next, temp;
	printf("\n");
	printf("输入第一个数(2~9位): ");
	scanf(" %d", &num);
	origin_len = intlen(num);
	media_len = origin_len - 1;
	printf("\n");
	printf("输入指定的间隔数: ");
	scanf(" %d", &next);
	printf("\n");
	printf("求%d后的第%d个数，结果是:\n\n", num, next);
    printf("字典序法\t递增进制法\t递减进制法\t邻位对换法\n");
    // 字典序法
	temp = in2dec(p2media_dic(num)) + next;
	if ((temp < 0)||(temp > fac(origin_len))) printf("超出范围\t");
	else {
		printf("%d\t", media2p_dic(dec2in(temp)));
	}
	// 递增进制法
	temp = in2dec(p2media_in(num)) + next;
	if ((temp < 0)||(temp > fac(origin_len))) printf("超出范围\t");
	else {
		printf("%d\t", media2p_in(dec2in(temp)));
	}
	// 递减进制法
	temp = de2dec(p2media_de(num)) + next;
	if ((temp < 0)||(temp > fac(origin_len))) printf("超出范围\t");
	else {
		printf("%d\t", media2p_de(dec2de(temp)));
	}
	// 邻位对换法
	temp = de2dec(p2media_swap(num)) + next;
	if ((temp < 0)||(temp > fac(origin_len))) printf("超出范围\n");
	else {
		printf("%d\n", media2p_swap(dec2de(temp)));
	}
	printf("\n\n");
}

int main(){
	printf("\n");
	printf("[1] 生成指定位数的所有全排列\n");
	printf("[2] 生成某数指定个数后的排列\n");
	printf("[0] 退出\n");
	printf("\n");
	printf("请输入序号: ");
	char c = getchar();
	switch(c){
		case '1': full_permutation(); break;
		case '2': specified_permutation(); break;
		default: return 0;
    }
}