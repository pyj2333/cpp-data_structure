#include "Node.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;

//定义一个链表类LinkList
//规定:第０个节点表示头结点

template <class T>
class LinkList: public Node<T> 
{
private:
    Node<T>* head;//指向头结点的指针
public:
    LinkList();//生成头结点
    bool get(int i, T& data);//获取第i个节点的数据域的值
    bool insert(int i, Node<T>* node);//在第i个位置后面插入节点
    bool del(int i);//删除第i个节点
    void head_create();//整表创建,头插法
    void tail_creat();//尾插法
    void show();//遍历链表，并打印所有元素
    ~LinkList();//释放内存
};

template <class T>
LinkList<T>::LinkList()//生成头结点,此时会调用父类默认构造函数
{
    head = new Node<T>;//head -> next = NULL;head -> data = 0; 
}


template <class T>
void  LinkList<T>::head_create()
{
    //采用“头插法”创建一个链表,数据域中插入n个随机数
    const int n = 100;
    srand(time(0));//随机数的种子
    //问：循环中不断的使用new分配内存,且把new返回的指针赋值给同一个变量,如何销毁
    //答：在析构函数函数中遍历链表,释放内存即可。
    for(int i = 0; i < n; i++)
    {  
    //1.生成节点
    Node<T>* p = new Node<T>;
    //2.插入数据
    p -> data = rand() % 100 + 1;
    //3.把新节点插入到头结点中和下一个节点之间
    //地址从后往前赋值
    p -> next = head -> next;
    head -> next = p;
    //思考：我们在书写循环语句时，不要总是拿新创建的第一个节点去思考怎样操作
    //如果思考如何操作第一个节点，只需要把节点地址赋值给头结点的指针域即可
    //然而这样思考，生成第二个节点怎么办，第三个，第四个呢？
    //你应该想在含有多个节点的链表中在头部插入数据怎么办。
    }
}

template <class T>
void LinkList<T>::show()
{
    //这里演示链表的操作
    int len = 0;
    Node<T>* p = head -> next;//p指向遍历时的当前节点
    while(p != nullptr)
    {
        //打印数据
        cout<<"第"<<++len<<"个节点"<< p -> data<<endl;
        //移动当前节点
        p = p -> next; 
    }
} 

template <class T>
void LinkList<T>::tail_creat()
{
    //现在演示从尾部插入n个数字
    int n = 100;
    //1.构造一个节点表示尾节点
    Node<T>* node = head;//以头结点作为尾节点

    for(int i = 0; i < n; i++)
    {
        //2.构造节点
        Node<T>* p = new Node<T>;
        p -> data = i;
        //3.把此节点插入尾部
        node -> next = p;
        //4.改变尾节点的位置
        node = p;
    }
    node -> next = NULL;  
}

template <class T>
bool LinkList<T>::get(int i, T& data)
{
    //获取链表第i个元素，i = 0表示头结点
    //1.声明一个指针用于遍历
    Node<T>* ran = head;
    int j = 0;
    //遍历链表i次
    //while(ran -> next && j < i)
    //上面语句会出现段错误.我想要ran -> next为false时
    //退出循环,可实际上应该是ran -> next为nullptr的时候
    //退出,尽管nullptr本质上为0,但是应该是程序此时是先去访问
    //这块内存的内容, 而这块内存禁止访问,所以出现段错误.
    //程序判断条件在设计的时候,应该是直接比较,而不是编译器隐士转换
    //后比较。同时,语句要清晰, 不要大多数情况下可以省略的东西.
    //比如说,if(s) 与 if(s != 0)尽管意义一样,但是后者更加清晰明了。
    //写代码不是用来装逼的！！！
    while(ran->next != nullptr && j < i)
    {
        ran = ran -> next;
        j++;
    }
    
    if(i <= 0 || j < i)
        return false;

    data = ran -> data;
    return true;
}

template <class T>
bool LinkList<T>::insert(int i, Node<T>* node)
{
    //在第i个节点后面插入节点
    //1.首先遍历到第i个节点
    int j = 0;
    Node<T> * ran = head;
    while(ran != nullptr && j < i)
    {
        j++;
        ran = ran -> next;
    }
    //2.对于i的检测
    //第i个是尾节点
    if(ran -> next == nullptr)
    {
        ran -> next = node; 
        return true;
    }

    //下标不合法
    if(j < i || i < 0)
    {
        cout<<"下标不合法"<<endl;
        return false;
    }

    //３.插入
    node -> next = ran -> next;
    ran -> next = node;
    return true;
}

template <class T>
bool LinkList<T>::del(int i)
{
    //首先遍历到第i-1个节点
    Node<T>* ran = head;
    int j = 0;
    while(ran -> next != nullptr && j < i-1)
    {
        ran = ran -> next;
        j++;
    }
    //i是否合法的检测
    //尾节点如何删除
    //直接释放内存

    if(j + 1 < i || i  <= 0)
    //j为想要删除的前一个节点,i为用户想要删除的节点,
    //下标不合法时,不是j < i;如果i合法,j仍然小于i
    {
        cout<<"删除失败\n";
        return false;
    }
    
    if(ran -> next -> next == nullptr)
    {
        delete ran->next;
        ran -> next = nullptr;//删除节点后,不会将自动将地址置为NULL;
        return true;
    }

    //第i个节点为中间节点删除
    Node<T>* p = ran -> next;//p为第i个节点的地址
    ran -> next = p -> next;
    delete p;//销毁内存需要放在最后面,因为前一行用到了p;
    return true;
}

template <class T>
LinkList<T>::~LinkList()
{
    //遍历链表,并销毁内存
    Node<T>* ran = head;
    int i = 0;
    Node<T>* p;
    while(ran != nullptr) 
    {
        p = ran;
        ran = ran -> next;
        delete p;
        //采用p来接收当前节点，而不是delete ran;
        if(i==0)
            cout<<"销毁头结点"<<endl;
        else
            cout<<"销毁第"<<i<<"个节点"<<endl;
        i++;
        //此处需要先移动指针，再释放内存
    }
    cout<<"销毁完毕"<<endl;
}

