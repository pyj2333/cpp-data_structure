#include "Solution.h"
#include "../Stack.h"
#include <iostream>

const char PUSH = '1';
const char POP  = '0';
//存储优先级关系
//第一行表示cur
//第一列表示栈顶元素top_val;
char table[6][6]={
{' ',  '+',   '-',    '*',   '/',   '^'},
{'+',  POP,   POP,   PUSH,   PUSH,  PUSH},
{'-',  POP,   POP,   PUSH,   PUSH,  PUSH},
{'*',  POP,   POP,   POP,    POP,   PUSH},
{'/',  POP,   POP,   POP,    POP,   PUSH},
{'^',  POP,   POP,   POP,    POP,   POP}
};

int find_cur(const char& cur){
    int i = 0;
    for(int i = 0; i < 6; i++){
        if(table[0][i] == cur)
            return i;}
    return -1;
}

int find_top(char& top){
    int i = 0;
    for(int i = 0; i < 6; i++){
        if(table[i][0] == top)
            return i;}
    return -1;
}



bool is_num(char& c){
    return c >= '0' && c <= '9';
}

char compare(char& cur, char& top_val){
    /*
    cur:当前字符
    top_val:栈顶的值
    返回'1':入栈
    返回'0'：出栈 
     */
    int x = find_top(top_val);
    int y = find_cur(cur);
    return table[x][y];
} 

Cal::Cal(){
    str = "";
}

Cal::Cal(const string & m_str){
    str = m_str;   
}

string Cal::transform(){
    std::string result = "";
    Stack<char> stack;
    char val;//用来存储弹出栈顶的值
    char top_val;//用来存储栈顶的值
    for(int i =0; i < str.length(); i++){
         
         //遇到数字
         if(is_num(str[i])){
              result += str[i];
              continue;}

         //栈空或遇到右括号
          if(stack.is_empty() || str[i] == '('){
              stack.push(str[i]);
              continue;}
         
         //遇到左括号
         else if(str[i] == ')'){
             stack.pop(val);
             while(val != '('){
                 result += val;
                 stack.pop(val);}
                 continue;}

         else{
         //遇到运算符
         stack.top_val(top_val);
         while(compare(str[i],top_val) == '0'){
                if(!stack.pop(val))break;
                result += val;
                stack.top_val(top_val);
         }
         stack.push(str[i]);}
}
while (stack.pop(val))
{
    result += val;
}

return result;
}

double get_result(std::string s){
    //s:后缀表达式
    Stack<int> stack;
    int val;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
             stack.push(s[i] - '0');//字符转数字，不能用(int)s[i],这会得出s[i]对应的ascii值
             std::cout<<s[i] - '0'<<"压入栈中\n";}
        else{
            stack.pop(val);
            double right = val;
            if(!stack.pop(val)){
                 val = 0;
            }
            double left = val;
            switch (s[i])
            {
            case '+':
                stack.push ((left + right)); 
                break;
            case '-':
                stack.push (left - right);
                break;
            case '*':
                stack.push (left * right);
                break;
            case '/':
                stack.push (left / right);
                break;
            }
        }
    }
    stack.pop(val);
return double(val);
}