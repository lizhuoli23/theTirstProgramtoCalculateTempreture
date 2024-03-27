#include <stdio.h>
#include <stdlib.h>
int num, i, j, k;

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

int main()
{

    scanf("%d", &num);

    // malloc
    float **E = (float **)malloc(num * sizeof(float *));
    float **I = (float **)malloc(num * sizeof(float *));
    for (i = 0; i < num; i++)
    {
        E[i] = (float *)malloc(num * sizeof(float));
        I[i] = (float *)malloc(num * sizeof(float));
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            if (i == j)

            {
                I[i][j] = 1;
            }
            else
            {
                I[i][j] = 0;
            }
        }
    }

    // input
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            scanf("%f", &E[i][j]);
        }
    }

    // solve

    for (i = 0; i < num; i++)
    {

        if (E[i][i] == 0)
        {
            for (j = i + 1; j < num; j++)
            {

                if (E[j][i] != 0)
                {
                    guass(&E[j][0], &E[i][0]);
                    guass(&I[j][0], &I[i][0]);
                    break;
                }
            }
        }

        float ratio = 1 / E[i][i];
        for (j = i + 1; j < num; j++)
        {

            for (k = 0; k < num; k++)
            {
                I[j][k] -= E[j][i] * ratio * I[i][k];
            }
            for (k = num; k > -1; k--)
            {
                E[j][k] -= E[j][i] * ratio * E[i][k];
            }
        }
    }

    for (i = num - 1; i > 0; i--)
    {
        float ratio1 = 1 / E[i][i];
        // E[i][i] = 1;
        for (int k = 0; k < num; k++)
        {
            I[i][k] *= ratio1;
            E[i][k] *= ratio1;
        }
        for (j = 0; j < i; j++)
        {
            for (int k = 0; k < num; k++)
            {
                I[j][k] -= E[j][i] * I[i][k];
            }
            // for (int k = num; k > i-1; k++)
            // {
            //     E[j][k] -= E[j][i] * E[i][k];
            // }
        }
    }

    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            printf("%7.4f ", I[i][j]);
        }
        printf("\n");
    }
    return 0;
}