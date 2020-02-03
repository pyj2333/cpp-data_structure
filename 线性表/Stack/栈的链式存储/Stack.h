template <class T>
class Node{
public:
    T val;
    Node* next;
    Node(){
    next = nullptr;
}
};

template <class T>
class Stack{
private:
    Node<T>* top;
public:
    Stack();
    bool is_empty(){return top == nullptr;}
    bool pop(T&);
    bool push(const T &);
    bool top_val(T&);
    ~Stack();
};

template <class T>
Stack<T>::~Stack(){
     Node<T>* del;
     while(top != nullptr){
          del = top;
          top = top -> next;
          delete del;
     }
}

template <class T>
Stack<T>::Stack(){
    top = nullptr;//生成一个空栈
}

template <class T>
bool Stack<T>::push(const T & m_val){
        Node<T>* node = new Node<T>;
        node -> val = m_val;
        node -> next = top;
        top = node;
        return true;
}

template <class T>
bool Stack<T>::pop(T & m_val){
    if(top == nullptr)
         return false;
     m_val = top -> val;
     Node<T>* del = top;
     top = top -> next;
     delete del;
     return true;
}

template <class T>
bool Stack<T>::top_val(T & m_val){
    if(top == nullptr)
        return false;
    m_val = top -> val;
    return true;
}