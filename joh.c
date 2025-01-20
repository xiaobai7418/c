//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//
 
#include <stdio.h>
#include <stdlib.h>
 
#define N 1000
 
// �������ҵ�һ�����������������������
int findDivisors(int num, int **divisors) {
    int sum = 1; // ��ʼ��������Ϊ1��1����������������
    int count = 1; // ��ʼ����������
    *divisors = (int*)malloc(num * sizeof(int)); // ��̬�����ڴ�洢����
    (*divisors)[0] = 1; // ��һ��������1
 
    // ������2��num/2����������Ѱ������
    for (int j = 2; j <= num / 2; ++j) {
        if (num % j == 0) { // ���j��num������
            sum += j; // �ӵ���������
            (*divisors)[count++] = j; // �洢����
        }
    }
 
    return sum; // ����������
}
 
int main() {
    // ������2��N����������Ѱ��������
    for (int i = 2; i <= N; ++i) {
        int *divisors; // ָ�����ڴ洢��������
        int sum = findDivisors(i, &divisors); // ��ȡ������
 
        // �����ǰ�����������������͵�����������
        if (i == sum) {
            printf("%d = %d", i, divisors[0]);
            for (int n = 1; divisors[n] != 0; ++n) { // �����������
                printf(" + %d", divisors[n]);
            }
            printf("\n");
        }
 
        free(divisors); // �ͷŶ�̬������ڴ�
    }
 
    return 0; // ����0��ʾ����ɹ�����
}
