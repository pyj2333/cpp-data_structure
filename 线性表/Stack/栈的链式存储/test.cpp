#include "Stack.h"
#include "iostream"

int main(){
    Stack<int> stack;
    int val;
    for(int i = 0; i < 3; i++){
        if(stack.push(i)){
              std::cout<<i<<"插入成功\n";
        }
    }

    for(int i = 0; i < 3; i++){
        if(stack.pop(val)){
              std::cout<<"val = "<<val<<'\n';
        }
        else
              std::cout<<"出栈失败\n";
        
}
}