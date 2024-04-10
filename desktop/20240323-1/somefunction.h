//somefunction.h
#ifndef SOMEFUNCTION_H
#define SOMEFUNCTION_H

// 声明一个全局变量
extern int myVariable;
extern float num;
extern float* b;
extern float** T;
extern float * myOtherVariable;
extern float* R1;
extern float* R2;
extern float** R;

// 声明一个函数
void guass(float *R1, float *R2);
void guass2(float **R, int a);
float SumFloat(int myVariable,float *myOtherVariable);

void EquationsSolver(float num, float **T, float *b);



// // 声明一个结构体
// struct MyStruct {
//     int field1;
//     double field2;
// };

#endif // SOMEFUNCTION_H
