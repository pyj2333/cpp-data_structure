#include "Queue.h"

Queue::Queue(){
    front = rear = 0; 
}

bool Queue::is_empty(){
    return front == rear;
}

bool Queue::is_full(){
    return (rear + 1) % MAXSIZE == front;
}

bool Queue::push(const I& val){
    if(is_full())
         return false;
    queue[rear] = val;
    rear = (rear + 1) % MAXSIZE;
}

bool Queue::pop(I& val){ 
    if(is_empty())
         return false;
    val = queue[front];
    front = (front + 1) % MAXSIZE;
}