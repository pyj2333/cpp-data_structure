//定义节点类
template <class T>
class Node
{
protected://public继承后数据成员仍为protected
    T data;//数据域
    Node* next;//指向下一个节点的指针
};


