#include <stdio.h>
#include "somefunction.h"
#include "somefunction.c"
#include <stdlib.h>
int main() 
{
    float num1;
    scanf("%f", &num1);
    float* b1;
    float** T1;
    EquationsSolver( num1, T1,b1);
    return 0;
}