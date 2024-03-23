#include <stdio.h>
#include <stdlib.h>
// int size = 10;
// int chongqingjuntong[3];
// void chuanshangjia(int *a)
// {
//     int i,j,k;
//     //int b=sizeof(a) / sizeof(a[0]);
//     chongqingjuntong[0]=a[0];
//     for (i=1;i<4-1;i++)
//     {
//         if(a[i]>chongqingjuntong[i-1])
//             {
//                 chongqingjuntong[i]=a[i];
//             }
        
//         else if(a[i]<=chongqingjuntong[0])
//             {
//                 for(j=i;j>0;j--)
//                 {
//                     //int f=a[i];
//                     chongqingjuntong[j]=chongqingjuntong[j-1];
                    
//                     //chongqingjuntong[j+1]=f;
//                 }
//                 chongqingjuntong[0]=a[i];
//             }
        
//         else
//         {
//             for(j=0;j<i-1;j++)
//             {           
            
//                 if(a[i]>chongqingjuntong[j]&&a[i]<=chongqingjuntong[j+1])
//                     {
//                         for(k=i;k>j+1;k--)
//                             {
//                                 chongqingjuntong[k]=chongqingjuntong[k-1];
//                             }
//                             chongqingjuntong[j+1]=a[i];
//                     }
//                 else
//                     {}
//             }
//         }
//     }
// }
int main()
{
    int size ;
    scanf("%d",&size);
    int* chongqingjuntong = malloc(size * sizeof(int));
    int a[size];
    for(int k=0;k<size;k++)
        {
            scanf("%d",&a[k]);
        }
    int i,j,k;
    //int b=sizeof(a) / sizeof(a[0]);
    chongqingjuntong[0]=a[0];
    for (i=1;i<size;i++)
    {
        if(a[i]>chongqingjuntong[i-1])
            {
                chongqingjuntong[i]=a[i];
            }
        
        else if(a[i]<=chongqingjuntong[0])
            {
                for(j=i;j>0;j--)
                {
                    //int f=a[i];
                    chongqingjuntong[j]=chongqingjuntong[j-1];
                    
                    //chongqingjuntong[j+1]=f;
                }
                chongqingjuntong[0]=a[i];
            }
        
        else
        {
            for(j=0;j<i-1;j++)
            {           
            
                if(a[i]>chongqingjuntong[j]&&a[i]<=chongqingjuntong[j+1])
                    {
                        for(k=i;k>j+1;k--)
                            {
                                chongqingjuntong[k]=chongqingjuntong[k-1];
                            }
                            chongqingjuntong[j+1]=a[i];
                    }
                else
                    {}
            }
        }
    
}
    // int a[3];
    // for(int k=0;k<3;k++)
    //     {
    //         scanf("%d",&a[k]);
    //     }
    
    // chuanshangjia(a);
    for(int k=0;k<size;k++)
        {
            int m=chongqingjuntong[k];
            printf("%d ",m);
        }
        return 0;
}




