/*
author:Fizz;
time: 2020-2-13; 
Please be more patient for coding;
*/

#include <iostream>
using std::ostream;

class string{
    char* str;
    int length;
public:
    string();
    string(const char*);
    string(const string&);
    ~string();
    int len() const{return length;};
    string& operator =(string&);
    char& operator[](int i);
    const char& operator [](int i) const;
    friend bool operator<(const string&, const string&);
    friend bool operator>(const string&, const string&);
    friend bool operator==(const string&, const string&);
    friend ostream& operator<<(ostream&, const string&);
};