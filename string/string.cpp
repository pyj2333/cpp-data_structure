/*
author:Fizz;
time: 2020-2-13; 
Please be more patient for coding;
*/
#include <cstring>
#include "string.h"

string::string(){
    //创建一个空字符串
    //不使用new char,是为了便于书写析构函数
    str = new char[1];
    str[0] = '\0';
    length = 0;
}

string::string(const char* temp){
    //分配的空间比字符串长度大一，多余的空间来存储\0
    length = std::strlen(temp);
    str = new char[length+1];
    std::strcpy(str,temp);
}


string::string(const string & st){
    //复制字符串对象st
    length = st.length;
    str = new char[length + 1];
    std::strcpy(str,st.str);
}

string& string:: operator = (string& st){
    //st赋值给当前对象
    //对象赋值给自己
    if(&st == this)return *this;
    //释放当前对象的内存
    delete[] str;
    length = st.length;
    str = new char[length + 1];
    std::strcpy(str,st.str);
    return *this;
}

char& string::operator[](int i){
    return str[i];
}

const char& string::operator[](int i) const{
    return str[i];
}

bool operator<(const string& st1, const string& st2){
    return st1.str < st2.str;
}

bool operator>(const string& st1, const string& st2){
    return st1.str > st2.str;
}

bool operator==(const string& st1, const string& st2){
    return st1.str == st2.str;
}

ostream& operator<<(ostream& os, const string& st){
    os<<st.str;
    return os;
}
string::~string(){
    delete[] str;
}

