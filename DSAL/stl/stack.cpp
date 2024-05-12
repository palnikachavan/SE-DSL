#include <iostream>
using namespace std;

template<typename T>
class Stack
{
    int top;
    T stack[50];

    public:
    Stack()
    {
        top = -1;
    }

    void push(T data)
    {
        if(top == 49)
            return;
        top++;
        stack[top] = data;
    }

    void pop()
    {
        if(top == -1)
            return;
        top--;
    }

    bool empty()
    {
        if(top == -1)
        {
            return 1;
        }
        else
            return 0;
    }

    T front()
    {
        if(top != -1)
            return stack[top];
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(20);
    int res = s.front();
    cout<<res;
    s.pop();
    res = s.front();
    cout<<res;
    return 1;
}