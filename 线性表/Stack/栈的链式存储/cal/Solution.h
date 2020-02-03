#include <string>
using std::string;

class Cal{
private:
    string str;//需要被运算的表达式
public:
    Cal();
    Cal(const string & m_str);
    string transform();
    //friend double get_result(std::string);
};

double get_result(std::string);