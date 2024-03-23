//somefunction.h
#ifndef SOMEFUNCTION_H
#define SOMEFUNCTION_H

// 声明一个函数
float SumFloat(int myVariable,float *myOtherVariable);

// 声明一个全局变量
extern int myVariable;
extern float * myOtherVariable;
extern float myOtherVariable2;

// 声明一个结构体
struct MyStruct {
    int field1;
    double field2;
};

#endif // SOMEFUNCTION_H
