#include <iostream>
#include <string.h>
#define Max 30
using namespace std;

class exp;

class Stack
{
    int top;
    friend class exp;
    char stack[50];
    public:
    Stack()
    {
        top = -1;
    }

    void push(char d)
    {
        if(top == 49)
        {
            cout<<"Stack Overflow. "<<endl;
        }
        else 
        {
            top++;
            stack[top] =  d;
            //cout<<"Element Pushed Successfully\n";
        }
    }

    void display()
    {
        char temp = top;
        while(temp != -1)
        {
            cout<<stack[temp]<<endl;
            temp--;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        return 1;
        else
        return 0;
    }

    bool isFull()
    {
        if(top == 49)
        return 1;
        else
        return 0;
    }

    char top_ele()
    {
        return stack[top];
    }

    char pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow. "<<endl;
        }
        else
        {
            char out;
            out = stack[top];
            top--;
            //cout<<"Popped Element :"<<out<<endl;
            return out;
        }
    }
};
class exp
{
    string expres;
    friend class Stack;
    public:
    Stack s1;
    Stack s;
    exp()
    {
        cout<<"Enter Infix Expression :";
        cin>>expres;
        
    }

    void display()
    {
        cout<<"Expression is :"<< expres<<endl;
    }

    void change()
    {
        cout<<"Enter New Expression :";
        cin>>expres;
        cout<<"Expression Changed. "<<endl;

    }

    int prio(char a)
    {
        if(a == '+' || a == '-')
            return 1;
        else if(a == '*' || a == '/')
            return 2;
    }




    void inf_post()
    {
        char a, last;
        char postfix[Max];
        int t = 0, x = 0;
        string out;
        a = expres[t];
        while(a != '\0')
        {
            if(a == '[' || a == '(' || a == '{')
            {
                s.push(a);
            }
            else if((a >= 97 && a <= 122) || (a >= 65 && a <= 90))
            {
                postfix[x] = a;
                x++;
            }
            else if(a == '+' || a == '-' || a == '*' || a == '/')
            {
                int pri;
                pri = prio(a);
                if (s.isEmpty() || s.top_ele() == '(' || s.top_ele() == '{' || s.top_ele() == '[' )
                    s.push(a);
                else
                {
                    while (prio(s.top_ele()) >= prio(a) && !s.isEmpty())
                    {
                        postfix[x] = s.pop();
                        x++;
                    }
                    s.push(a);
                }
            }
            else
            {
                if(a == ')')
                {
                    while (s.top_ele() != '(' && !s.isEmpty())
                    {
                        char xa;
                        xa = s.pop();
                        postfix[x] = xa;
                        x++;
                    }
                }
            }

            t++;
            a = expres[t];
        }
        s.display();
        last = s.pop();

        postfix[x] = last;
        x++;
        cout<<"result :"<<postfix<<endl;
    }
    
    void evaluate(string postf)
    {
        
        char a;
        int t = 0;
        a = postf[t];
        while (a != '\0')
        {
            
            if((a>= 97 && a <=122) || (a >= 65 && a<= 90))
            {
                int val = 0;
                cout<<"Enter value for "<<a<<" :";
                cin>>val;
                s1.push(val);
            }
            if(a == 43 || a == 45 || a == 42 || a == 47)
            {
                int temp1, temp2, res;
                temp2 = s1.pop();
                temp1 = s1.pop();
                if(a == '+')
                {
                    res = temp1 + temp2;
                }
                else if(a == '-')
                {
                    res = temp1 - temp2;
                }
                else if(a == '*')
                {
                    res = temp1 * temp2;
                }
                else if(a == '/')
                {
                    res = temp1 / temp2;
                }
                s1.push(res);
            }
            t++;
            a = postf[t];
        }
        cout<<"Result is :"<<s1.pop();
        s1.display();
    }
};

int main()
{
    exp e1;
    e1.inf_post();
}

// int main()
// {
//     exp e1;
//     char ch = 'y';
//     while(ch == 'y')
//     {
//         int o;
//         cout<<"\t\t\tMENU"<<endl;
//         cout<<"1. Input Values and Evaluate Expression "<<endl;
//         cout<<"2. Display Expression "<<endl;
//         cout<<"3. Change Expression "<<endl;
//         cout<<"Enter Option :";
//         cin>>o;
//         switch (o)
//         {
//         case 1:
//             {
//                 e1.evaluate();
//                 break;
//             }
//         case 2:
//             {
//                 e1.display();
//                 break;
//             }
//         case 3:
//             {
//                 e1.change();
//             }
//         default:
//             break;
//         }
//     cout<<"\nDo you want to continue? (y/n)";
//     cin>>ch;
//     }
//     return 1;
// }