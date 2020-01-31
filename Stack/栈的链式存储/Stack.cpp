#include "Stack.h"

Stack::Stack(){
    top = nullptr;//生成一个空栈
}

bool Stack::push(const I & m_val){
        Node* node = new Node;
        node -> val = m_val;
        node -> next = top;
        top = node;
        return true;
}

bool Stack::pop(I & m_val){
    if(top == nullptr)
         return false;
     m_val = top -> val;
     Node* del = top;
     top = top -> next;
     delete del;
     return true;
}