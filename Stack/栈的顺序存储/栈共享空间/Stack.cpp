#include "Stack.h"

Stack::Stack(){
    top_1 = -1;
    top_2 = max;
}

bool  Stack::pop(I& val, int top_num){
    if(top_num == 1){
       if(top_1 == -1)
          return false;
        val = arr[top_1--];
        return true;}
    if(top_num == 2){
        if(top_2 == max)
            return false;
        val = arr[top_2++];
        return true;}
}

bool Stack::push(const I& val, int top_num){
    if (top_1 + 1 == top_2)
        return false;
    if(top_num == 1){
        arr[++top_1] = val;
        return true;
    }
    if(top_num == 2){
        arr[--top_2] = val;
        return true;
    }
}