/*
两个栈是同类型的栈，他们共享同一块空间;
栈1为空：top_1 == -1;
栈2为空：top_2 == max;
栈满：top_1 + 1 == top_2，这个可以自己推一下，当
栈满时，必有top_1 + 1 + max - top_2 == max;
 */

typedef int I;

class Stack{
private:
    enum{max = 2};
    I arr[max];
    int top_1, top_2;
public:
    Stack();
    bool pop(I& val, int top_num);
    bool push(const I& val, int top_num);
    //采用const可以把字面值常量赋值给val,即可以直接调用push(100);
};