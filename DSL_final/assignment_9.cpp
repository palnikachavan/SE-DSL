#include <iostream>
#include <string.h>
using namespace std;
#define max 20
class expression;
class Stack
{
    friend class expression;
    int top;
    char S[max];
    public:
    Stack()
    {
        top = -1;
    }

    bool isFull()
    {
        if(top == max - 1)
            return 1;
        else
            return 0;
    }

    bool isEmpty()
    {
        if (top == -1)
            return 1;
        else    
            return 0;
    }

    void push(char d)
    {
        if(isFull())
        {
            cout<<"Stack Overflow."<<endl;
        }
        else
        {
            top ++;
            S[top] = d;
        }
    }

    void display()
    {
        char i = 0;
        while(i <= top)
        {
            cout<<S[i]<<endl;
            i++;
        }
    }

    char pop()
    {
        char out;
        if(isEmpty())
            cout<<"Stack Underflow."<<endl;
        else
        {
            out = S[top];
            top --;

        }
        return out;
    }
};

class expression
{
    string exp;
    Stack s1;
    public:
    expression()
    {
        string s;
        cout<<"Enter Infix Expression :";
        cin>>s;
        exp = s;
    }

    void check()
    {
        int i;
        char a;
        a = exp[0];
        bool flag = 0;
        char out = '\0';
        while (a != '\0')
        {
            if(a == '(' || a == '[' || a == '{')
            {
                s1.push(a);
            }
            else if(a == ')')
            {       
                
                while(s1.top >= -2)
                {
                    if(out != '(')
                        {
                            out = s1.pop();
                        }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
            }

            else if(a == ']')         
            {
                while(s1.top >= -2)
                {
                    if(out != '[')
                        {
                            out = s1.pop();
                        }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
            }

            else if(a == '}')        
            {
                while(s1.top >= -2)
                {
                    if(out != '{')
                        {
                            out = s1.pop();
                        }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            cout<<"here :"<<out<<" "<<flag<<endl;
            i++;
            a = exp[i];  
        }

        if(flag == 1)
            cout<<"Valid Parenthesis."<<endl;
        else
            cout<<"Invalid Parenthesis"<<endl;
    }

    
};

int main()
{
    expression e1;
    e1.check();
    // bool x;
    // Stack s1;
    // s1.push('a');
    // x = s1.isFull();
    // cout<<"bool"<<x<<endl;
    return 1;
}