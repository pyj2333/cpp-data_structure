#include <iostream>
using std::cout;

//declare
template <class T>
class List
{
private:
    int max_size;//从1开始;
    int len; //从1开始;
    T * lis;
public:
    List(int m_Max = 10);
    int get_max(){return max_size;};
    int get_len(){return len;};
    bool append(T m);//依次添加元素;
    int find(T& n);//遍历查找,返回元素n的下标,若不在元素中,则返回-1;
    bool remove(T& n);//删除元素n;
    bool insert(int & i,  T & n);//在i位置插入i;
    void show();
    ~List();
};
//千万注意：
//define
template <class T>
List<T>::List(int m_Max)
{
    max_size = m_Max;
    len = 0;
    lis = new T[max_size];
}

template <class T>
void List<T>::show()
{
    for(int i = 0; i < len; i++)
    cout<<lis[i]<<",";
    cout<<'\n';
}

template <class T>
int List<T>::find(T& n)
{
    for(int i = 0; i < len; i++)
    {
        if(lis[i] == n)
        return i;
    }
    return -1;
}

template <class T>
bool List<T>::append(T n)
{
 if(len == max_size)
    return false;
 lis[len++] = n;
 return true;
}

template <class T>
bool List<T>::remove(T& n)
{
    int index = find(n);
    if(index == -1)//长度为空,n不在线性表中;
        return false;
    
    if(index == len - 1)//当n为最后一个元素
    {
        len--;
        return true;
    }
    for(int j = index; j < len-1; j++){
        lis[j] = lis[j+1];
        }
    len--;
    return true;        
}


template <class T>
List<T>::~List()
{
    delete[] lis;
}


template <class T>
bool List<T>::insert(int & i , T & n)
{
    /*
    i:插入的位置,从１开始;
    n:插入的数;
    */
    if(i < 1 || i > len + 1 || len == max_size)//i不合法或者数组达到最大容量　　　　　　　　
        return false;
    if(i == len + 1){
         lis[i] = n;
         return true;
    }
    //for(int j = i-1;j < len; j++)错误循环,这样只会把第n个数移到末尾
    
    for(int j = len - 1; j > i-2; j--)
       lis[j+1] = lis[j];
    
    lis[i - 1] = n;
    return true;
}

