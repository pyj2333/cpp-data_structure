#include "List.h"
#include <iostream>
using std::cout;

int main()
{
    List<int> lis;
    //调用List()函数,此时会调用List()函数,
    //实际上是调用List(int  max = 10),因为默认参数
    //在调用时不用给出;
    //此种方法可以大大减少代码量;
    List<int> c_lis(15);
    
    for(int i = 0; i < 10; i++)
        c_lis.append(i);

    c_lis.show();

    int i = 4;
    int j = 9;
    int k = 10;
    cout<<c_lis.find(i)<<'\n';
    
    if(c_lis.remove(i))
        c_lis.show();
    else
        cout<<"failed\n";
    
    if(c_lis.remove(j))
         c_lis.show();
    else  
         cout<<"failed\n";
    
    if(c_lis.remove(k))
         c_lis.show();
    else
         cout<<"failed\n";
    
    
    

}