#ifndef CUSTOM_STACK_H
#define CUSTOM_STACK_H

#include <vector>

class CustomStack{
    private:
        std::vector<int> elstack;
    public:
        CustomStack();
        ~CustomStack();
        void push(int cosito);
        void pop();
        int size();
        bool empty();
        int top();
};

#endif