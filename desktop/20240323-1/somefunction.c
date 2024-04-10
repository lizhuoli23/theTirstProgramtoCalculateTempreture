// somefunction.c
#include <stdio.h>
#include <stdlib.h>


// 定义全局变量
// int myVariable;
// float num;
// float *b;
// float **T;
// float *myOtherVariable;


float SumFloat(int myVariable, float *myOtherVariable)
{
    float myOtherVariable2;
    for (int i = 0; i < myVariable; i++)
    {
        myOtherVariable2 += myOtherVariable[i];
    }
    return myOtherVariable2;
}

void guass(float *R1, float *R2)
{
    float num;
    float *exchange = (float *)malloc(num * sizeof(float));
    for (int i = 0; i < num; i++)
    {
        exchange[i] = R1[i];
        R1[i] = R2[i];
        R2[i] = exchange[i];
    }
}
void guass2(float **R, int a)
{
    int i;
    if (R[a][a] == 0)
    {
        for (i = a - 1; i >= 0; i--)
        {

            if (R[i][i] != 0)
            {
                guass(&R[a][0], &R[i][0]);
                break;
            }
        }
    }
}

void EquationsSolver(float num, float **T, float *b)
{
    int i;

    // malloc
    T = (float **)malloc(num * sizeof(float *));
    for (int i = 0; i < num; i++)
    {
        T[i] = (float *)malloc(num * sizeof(float));
    }
    b = (float *)malloc(num * sizeof(float));

    // input
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%f", &T[i][j]);
        }
    }
    for (int i = 0; i < num; i++)
    {
        scanf("%f", &b[i]);
    }

    // solve
    for (i = num - 1; i >= 0; i--)
    {
        guass2(T, i);
        float ratio = 1 / T[i][i];
        for (int j = 0; j < i; j++)
        {
            b[j] -= ratio * b[i] * T[j][i];
            for (int k = 0; k < i + 1; k++)
            {
                T[j][k] -= T[j][i] * ratio * T[i][k];
            }
        }
    }

    for (i = 0; i < num - 1; i++)
    {
        float ratio = 1 / T[i][i];
        for (int j = i + 1; j < num; j++)
        {
            b[j] -= ratio * b[i] * T[j][i];
        }
    }

    for (i = 0; i < num; i++)
    {
        float ratio = 1 / T[i][i];
        b[i] = ratio * b[i];
    }

    for (int i = 0; i < num; i++)
    {
        printf("%.3f ", b[i]);
    }
    return;
}
