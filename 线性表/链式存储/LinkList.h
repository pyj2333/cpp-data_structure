#include "Node.h"

//定义一个链表类,一个类使用另一个类时,采用的是“组合”或者“友元函数”进行通信
//此处不是使用，而是包含，采取继承或许会更好。

template <class T>
class LinkList: public Node <T>
{
    Node<T>* head;//指向头结点的指针
    LinkList();//生成头结点
    bool get(int i, T& data);//获取第i个节点数据域的值
    bool insert(int i, Node<T>& node);//在第i个位置插入节点
    bool del(int i);//删除第i个节点
    void head_create();//整表创建,头插入
    void tail_creat();//尾插入
    void show();//打印整个链表
    ~LinkList();
};
