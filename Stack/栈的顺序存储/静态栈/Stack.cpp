#include "Stack.h"


Stack::Stack()
{
top = -1;
Max = 10;
stack = new I[Max];
}

Stack::Stack(const int m_Max)
{
top = -1;
Max = m_Max;
stack = new I[Max];
}

bool Stack::is_empty()
{
return top == -1;
}

bool Stack::is_full()
{
return top == Max-1;
}

bool Stack::pop(I& st)
{
//pop函数中参数st的作用：
//我想得到出栈的元素的值，但是一个函数只能有一个返回值
//我在main()函数中定义一个指针,直接传入函数,修改这块内存的值即可。
//出栈
if (top > -1)
{
    st = stack[top--];
    return true;//返回栈顶指针 
}
return false;
}

bool Stack::push(const I& st)
{
//入栈
if(top < Max-1)
{
    stack[++top] = st;
    return true;
}
return false;
}

bool Stack::get_top(I& top_value)
{
    if(top > -1)
    {
        top_value = stack[top];
        return true;
    }; 
return false;
    
}
Stack::~Stack()
{
    delete[] stack;
}