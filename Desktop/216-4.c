#include <stdio.h>
#include <stdlib.h>
int num, i, j;

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
    float **E = (float **)malloc(num * sizeof(float *));
    float **I = (float **)malloc(num * sizeof(float *));
    for (int i = 0; i < num; i++)
    {
        E[i] = (float *)malloc(num * sizeof(float));
        I[i] = (float *)malloc(num * sizeof(float));
        T[i] = (float *)malloc(num * sizeof(float));
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (i == j)

            {
                E[i][j] = 1;
                I[i][j] = 1;
            }
            else
            {
                E[i][j] = 0;
                I[i][j] = 0;
            }
        }
    }

    // input
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%f", &T[i][j]);
        }
    }

    // solve
    for (i = 0; i < num; i++)
    {

        if (T[i][i] == 0)
        {
            for (j = i + 1; j < num; j++)
            {

                if (T[j][j] != 0)
                {
                    guass(&T[j][0], &T[i][0]);
                    guass(&E[j][0], &E[i][0]);
                    break;
                }
            }
        }

        float ratio = 1 / T[i][i];
        for (int j = i + 1; j < num; j++)
        {

            for (int k = num; k > i - 1; k--)
            {
                E[j][k] -= T[j][i] * ratio * E[i][k];
                T[j][k] -= T[j][i] * ratio * T[i][k];
            }
        }
    }

    for (i = 0; i < num; i++)
    {

        if (E[i][i] == 0)
        {
            for (j = i + 1; j < num; j++)
            {

                if (E[j][j] != 0)
                {
                    guass(&E[j][0], &E[i][0]);
                    guass(&I[j][0], &I[i][0]);
                    break;
                }
            }
        }

        float ratio = 1 / E[i][i];
        for (int j = i + 1; j < num; j++)
        {

            for (int k = num; k > i - 1; k--)
            {
                I[j][k] -= E[j][i] * ratio * I[i][k];
                E[j][k] -= E[j][i] * ratio * E[i][k];
            }
        }
    }

    for (i = num - 1; i > 0; i--)
    {
        float ratio1 = 1 / E[i][i];
        E[i][i] = 1;
        for (int k = 0; k < num; k++)
        {
            I[i][k] *= ratio1;
        }
        for (j = i - 1; j > 0; j--)
        {
            for (int k = 0; k < num; k++)
            {

                I[j][k] -= E[j][i] * I[i][k];
            }
        }
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%f ", T[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%f ", I[i][j]);
        }
        printf("\n");
    }
    return 0;
}