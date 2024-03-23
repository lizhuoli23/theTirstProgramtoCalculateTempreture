#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define Nx 1000 // 200
#define Ny 100  // 20
#define Nz 50  // 10

float caixukun(float chang, float tiao)
{
    if (chang >= tiao)
    {
        return chang;
    }
    else
    {
        return tiao;
    }
}

int main()
{
    float ***T = (float ***)malloc(Nx * sizeof(float **));
    float ***T_new = (float ***)malloc(Nx * sizeof(float **));
    for (int i = 0; i < Nx; i++)
    {
        T[i] = (float **)malloc(Ny * sizeof(float *));
        T_new[i] = (float **)malloc(Ny * sizeof(float *));
        for (int j = 0; j < Ny; j++)
        {
            T[i][j] = (float *)malloc(Nz * sizeof(float));
            T_new[i][j] = (float *)malloc(Nz * sizeof(float));
        }
    }
    int max_Iterative_Times = 5000; // 最大迭代次数
    float Convergence = 1;        // 收敛条件
    int i, j, k, iterative;

    // 定义边界条件          //<别人的,留纪念>(此处从0开始和从1开始存疑)
    for (i = 1; i < Nx; i++)
    {
        for (j = 0; j < Ny; j++)
        {
            for (k = 0; k < Nz; k++)
            {
                T[i][j][Nz - 1] = 40; // AEFD面(顶面）温度为40
                T[i][j][0] = (1-j/Ny*0.8)*(100-75*i/Nx); // 底面温度
                
                T[i][0][k] = 100-75*i/Nx;      // 初始条件
                T[i][Ny - 1][k] = 100-75*i/Nx;   
                
                T[0][j][k] = 100;     // ABEG面（左侧面）温度为100                
                T[Nx - 1][j][k] = 20; // DCHF面（右侧面）温度为20
                       
            }
        }
    }

    for (i = 1; i < Nx - 1; i++)
    {
        for (j = 1; j < Ny - 1; j++)
        {
            for (k = 1; k < Nz - 1; k++)
            {
                T[i][j][k] = 60; // 初始条件：温度60
            }
        }
    }

    for (i = 0; i < Nx; i++)
    {
        for (j = 0; j < Ny; j++)
        {
            for (k = 0; k < Nz; k++)
            {
                T_new[i][j][k] = T[i][j][k];
            }
        }
    }

    // 迭代计算
    for (iterative = 0; iterative < max_Iterative_Times; iterative++)
    {

        // 计算内部节点的温度值
        for (i = 1; i < Nx - 1; i++)
        {
            for (j = 1; j < Ny - 1; j++)
            {
                for (k = 1; k < Nz - 1; k++)
                {
                    T_new[i][j][k] = (T[i + 1][j][k] + T[i - 1][j][k] + T[i][j + 1][k] + T[i][j - 1][k] + T[i][j][k + 1] + T[i][j][k - 1]) / 6;
                    //if(iterative>2)
                    //printf(" %.2f\n", T[i][j][k]);
                }
            }
        }
        //float rap[Ny - 2], lanqiu[Nz - 2];
        //float music;
        //// 检查收敛条件
        // double max_difference = 0;//初始化差值
        // for (i = 1; i < Nx - 1; i++)
        // {
        //     for (j = 1; j < Ny - 1; j++)
        //     {
        //         for (k = 1; k < Nz - 1; k++)
        //         {
        //             float asdfghjkl0 = fabs(T_new[i][j][k] - T[i][j][k]); //< Convergence
        //             float asdfghjkl1 = fabs(T_new[i][j][k - 1] - T[i][j][k - 1]);
        //             rap[j - 1] = caixukun(asdfghjkl0, asdfghjkl1);
        //             //{
        //             // max_difference = fabs(T_new[i][j][k] - T[i][j][k]);
        //             //}
        //         }
        //         lanqiu[i - 1] = caixukun(rap[j], rap[j - 1]);
        //     }
        //     music = caixukun(lanqiu[i], lanqiu[i - 1]);
        // }
        // if (music < Convergence)
        // {
        //     break;
        // }

        // // if (max_difference < Convergence)
        // // {
        // //     break;
        // // }
        // // //更新计算后的温度值
        // else
        // {
        for (i = 1; i < Nx - 1; i++)
        {
            for (j = 1; j < Ny - 1; j++)
            {
                for (k = 1; k < Nz - 1; k++)
                {
                    T[i][j][k] = T_new[i][j][k];
                }
            }
        }
    }
    //}

    // 输出最终的温度场分布
    //}
    // for (i = 0; i < Nx; i++)
    // {
    //     for (j = 0; j < Ny; j++)
    //     {
    //         for (k = 0; k < Nz; k++)
    //         {
    //             printf("%.2f ", T[i][j][k]);
    //         }
    //         printf("\n");
    //     }
    //     printf("\n");
    // }
    FILE *file = fopen("data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    for (i = 1; i < Nx-1; i++)
    {
        for (j = 1; j < Ny-1; j++)
        {
            for (k = 1; k < Nz-1; k++)
            {
                fprintf(file, "%d %d %d %.2f\n", i, j, k, T[i][j][k]);
            }
        }
    }

    fclose(file);
    for (int i = 0; i < Nx; i++)
    {
        for (int j = 0; j < Ny; j++)
        {
            free(T[i][j]);
            free(T_new[i][j]);
        }
        free(T[i]);
        free(T_new[i]);
    }

    free(T);
    free(T_new);
    //printf("Hello, World!\n");
    return 0;
}
