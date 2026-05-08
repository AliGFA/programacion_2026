#include <iostream>
#include "Custom_stack.h"


int main(){
    CustomStack MiPila;

    MiPila.push(1);
    MiPila.push(2);
    MiPila.push(3);
    MiPila.pop();
    std::cout << MiPila.top() << std::endl;
    std::cout << MiPila.size();
    


return 0;
}