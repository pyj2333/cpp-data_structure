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
    bool insert(int & i,  int & n);//在i位置插入i;
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
    if(

    )
}




template <class T>
List<T>::~List()
{
    delete[] lis;
}

