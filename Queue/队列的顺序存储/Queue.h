typedef int I;

class Queue{
private:
    int front;
    int rear;
    enum {MAXSIZE = 3};
    I queue[MAXSIZE];
public:
     Queue();
     bool is_empty();
     bool is_full();
     bool push(const I& val);//入队列
     bool pop(I& val);//出队列
};
//notes:
//队列：一端插入一端删除的数据结构
//下面介绍循环队列
/*
1.
如果把数组看做一个队列，每一次进队列就是给数组依次赋值。
第一次进队列：
[0]
第二次进队列：
[0,1]
第三次进队列：
[0,1,2]
第一次出队列：
[1,2]
第二次出队列：
[2]
出队列时数组的元素要整体移动，时间复杂度O(n)，明显效率较低
2.为了解决这种问题，我们采用指针来解决这个问题。
用front来标示队头，rear来标示队尾。
队列初始化时，rear = front = 0;
每一次出对列，front就后移一下。
由此我们可以看出，所谓的删除队列元素并不是真正的删除.
每有一个元素入队列,rear就后移一下。
即：rear为新入队元素的下一个下标。
那么如果当入队以后，如果达到数组最大容量了,rear继续后移.
但是，此时front前位置还可以用啊，因此我们把rear指向0;

3.当队列满时，rear == front;
这就存在了一个问题，队列空的条件是:rear == front
那么如何区分呢，其中一种编程思想是采用另一个变量来区分。
伟大的科学家们用了这个方法：当插入元素后，他们不让rear与front相等，
即(rear + 1) % max == front即为满
综上：
队列为空:front == rear;
队列满时:(rear + 1) % max == front
元素个数：(rear - front + max) % max; 
 */