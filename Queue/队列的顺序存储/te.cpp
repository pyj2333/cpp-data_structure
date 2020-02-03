#include "Queue.h"
#include <iostream>

int main(){
    Queue q;
    int pop_val;
    if(q.is_empty())
        std::cout<<"空\n";
    if(q.push(1)) std::cout<<"success\n";
    if(q.is_full())
        std::cout<<"满\n";
    for(int i= 0; i < 2; i++){
    q.pop(pop_val);
    std::cout<<pop_val<<'\n';
    if(q.is_empty())
        std::cout<<"空\n";
    else
        std::cout<<"非空\n";
    }
   
}