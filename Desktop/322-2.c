//random4()generates uniformly distributed random points within [1,5] x [1,5] x [0,4] x [1,5]
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float X[100],Y[100],Z[100],R[100];
void random4()
{
	int i;

	double x, y, z, r;
	
	
 
	srand(time(NULL));
 
	// 均匀撒点
	for (i=1; i < 100; i++)
	{
		// 【0，1】区域撒点
		x = (double) rand() / RAND_MAX;
		y = (double) rand() / RAND_MAX;
		z = (double) rand() / RAND_MAX;
		r = (double) rand() / RAND_MAX;

		X[i] = x;
		Y[i] = y;
		Z[i] = z;
		R[i] = r;
		}
}
 
 
 
int main()
{
	random4();
	for(int i=0;i<100;i++)
	{
		printf("%.2f %.2f %.2f %.2f\n",1+4*X[i],1+4*Y[i],4*Z[i],1+4*R[i]);
	}
	return 0;
}