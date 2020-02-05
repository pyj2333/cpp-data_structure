//notes
/*
与单链表相似，只不过多了一个rear指针一直指向尾节点。
入队时从尾节点插入，出队时删除头结点的下一个节点。
*/



typedef int I;

class Node{
public:
    Node* next;
    I val;
public:
    Node(I m_val = 0){
        val = m_val;
        next = nullptr;
    }
};

class Queue{
private:
     Node* front;
     Node* rear;
public:
     Queue();
     bool is_empty();
     bool push(const I&);
     bool pop(I&);
};






