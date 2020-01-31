typedef int I;

class Node{
public:
    I val;
    Node* next;
    Node(){
    next = nullptr;}
};

class Stack{
private:
    Node* top;
public:
    Stack();
    bool pop(I&);
    bool push(const I &);
};
