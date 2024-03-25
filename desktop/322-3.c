#include <stdio.h>
#include <stdlib.h>
int num, i;

void guass(float *R1, float *R2)
{
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

int main()
{

    scanf("%d", &num);

    // malloc
    float **T = (float **)malloc(num * sizeof(float *));
    for (int i = 0; i < num; i++)
    {
        T[i] = (float *)malloc(num * sizeof(float));
    }
    float *b = (float *)malloc(num * sizeof(float));

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

    return 0;
}