#include "class_retain.h"

Class_Retain::Class_Retain()
{
    this->retainCount = 0;

}

#include <stdio.h>
void Class_Retain::retain(){
    
    retainCount++;
    //printf("retain:retainCount=%d\n",retainCount);
    
}

void Class_Retain::release(){

    retainCount--;
    //printf("release:retainCount=%d\n",retainCount);
   
}

bool Class_Retain::isRetainZero(){
    if(retainCount<=0){
        return true;
    }else{
        return false;
    }
}
