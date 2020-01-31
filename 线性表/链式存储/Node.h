//定义节点类
template <class T>
class Node
{
public:
    T data;//数据域
    Node<T>* next;//指向下一个节点的指针


//此处即使不初始化,next = NULL;NULL即是0,不可访问的内存
public:
    Node()
    {
        next = nullptr;
        //next = NULL;
        //NULL的使用需要头文件NULL
        //尽量使用nullptr而非NULL;
    }
};


