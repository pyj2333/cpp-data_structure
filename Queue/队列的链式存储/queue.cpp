#include "queue.h"

Queue::Queue(){
    //生成头结点,此时队列为空,front == rear;
    front = rear =new Node(0);
}

bool Queue::is_empty(){
    if(front == rear)return true;
    return false;
}

bool Queue::push(const I& val){
    Node* node = new Node(val);
    if(!node)return false;//堆栈溢出
    rear -> next = node;
    rear = rear -> next;
    return true;
}

bool Queue::pop(I& m_val){
    if(is_empty())return false;
    Node* del = front -> next;
    m_val = del -> val;
    //除头结点外只有一个节点时，出队列后rear指针要前移
    //此时队列为空
    if(front -> next == rear)rear = front;
    else front -> next = del -> next;
    delete del;
    return true;
}