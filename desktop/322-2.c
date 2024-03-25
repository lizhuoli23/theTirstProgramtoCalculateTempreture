//random4()generates uniformly distributed random points within [1,5] x [1,5] x [0,4] x [1,5]
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
float X[N],Y[N],Z[N],R[N];
void random4()
{
	int i;

	double x, y, z, r;
	
	
 
	srand(time(NULL));
 
	// 均匀撒点
	for (i=0; i < N; i++)
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
	FILE *w=fopen("forcetext.txt","w");
	random4();
	for(int i=0;i<N;i++)
	{
		fprintf(w,"%.2f %.2f %.2f %.2f\n",1+4*X[i],1+4*Y[i],4*Z[i],1+4*R[i]);
	}
	fclose(w);
	return 0;
}