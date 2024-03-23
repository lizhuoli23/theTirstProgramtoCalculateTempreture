// somefunction.cpp

#include "somefunction.h"
float myOtherVariable2 = 0;
float SumFloat(int myVariable,float *myOtherVariable) {
    for(int i = 0; i < myVariable; i++) 
    {
        myOtherVariable2+=myOtherVariable[i];
    }
    return myOtherVariable2;
    
}