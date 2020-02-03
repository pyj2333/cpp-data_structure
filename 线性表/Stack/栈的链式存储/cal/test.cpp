#include "Solution.h"
#include <iostream>
#include <string>


int main(){
    //Cal cal("9+(3-1)*3+10/2");
    Cal cal("-1-2-3");
    std::string str = cal.transform();
    std::cout<<str<<'\n';
    double re =  get_result(str);
    std::cout<<re<<'\n';
}
