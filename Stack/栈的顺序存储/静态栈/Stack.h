//栈的顺序存储和线性表的顺序存储很类似,
//都需要一个指向数组的指针，数组的最大容量，表示栈顶的标记。
//栈只允许在头部进行插入和删除操作。

typedef int I;

class Stack
{
private:
    int Max;
    I* stack;
    int top;
    //enum {Max = 10}; //Max只是一个标志,当未分配内存,当遇到Max时,自动替换为10
    //I stack[Max];   //因为数组在声明时，必须要求Max不能为变量,
    //如果我要实现一个被类共享的数组,而且要求在初始化时指定数组大小。
    //如果直接在析构函数中声明数组的话，那就不能在整个类中全局共享了。
    //此处我采用指针的方式。
public:
    Stack();
    Stack(const int m_Max);
    bool is_empty();
    bool is_full();
    bool push(const I& st);
    bool pop(I& st);
    bool get_top(I& top_value);
   ~Stack();
};
