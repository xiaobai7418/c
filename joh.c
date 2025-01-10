//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
//
 
#include <stdio.h>
#include <stdlib.h>
 
#define N 1000
 
// 函数：找到一个数的所有因数并计算其和
int findDivisors(int num, int **divisors) {
    int sum = 1; // 初始化因数和为1（1是所有数的因数）
    int count = 1; // 初始化因数计数
    *divisors = (int*)malloc(num * sizeof(int)); // 动态分配内存存储因数
    (*divisors)[0] = 1; // 第一个因数是1
 
    // 遍历从2到num/2的所有数，寻找因数
    for (int j = 2; j <= num / 2; ++j) {
        if (num % j == 0) { // 如果j是num的因数
            sum += j; // 加到因数和中
            (*divisors)[count++] = j; // 存储因数
        }
    }
 
    return sum; // 返回因数和
}
 
int main() {
    // 遍历从2到N的所有数，寻找完美数
    for (int i = 2; i <= N; ++i) {
        int *divisors; // 指针用于存储因数数组
        int sum = findDivisors(i, &divisors); // 获取因数和
 
        // 如果当前数是完美数（因数和等于数本身）
        if (i == sum) {
            printf("%d = %d", i, divisors[0]);
            for (int n = 1; divisors[n] != 0; ++n) { // 输出所有因数
                printf(" + %d", divisors[n]);
            }
            printf("\n");
        }
 
        free(divisors); // 释放动态分配的内存
    }
 
    return 0; // 返回0表示程序成功结束
}