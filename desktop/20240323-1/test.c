#include <stdio.h>
#include "somefunction.h"
#include "somefunction.c"
#include <stdlib.h>
int main() 
{
    float result ;
    int size = 10;
    scanf("%d", &size);
    
    float* a = (float*)malloc(size * sizeof(float)); // 动态分配一个浮点数数组
    for (int i = 0; i < size; i++) {
        scanf("%f",&a[i]); // 给数组赋值
    }
    result = SumFloat(size, a); // 调用函数
    printf("%.3f\n", result); // 输出结果
    free(a); // 释放动态分配的数组
    return 0;
}