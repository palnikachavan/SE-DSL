#include <iostream>
using namespace std;

int main()
{
    int num, denum;
    cout<<"Enter numerator :";
    cin>>num;
    cout<<"Enter denum :";
    cin>>denum;
    float res = 0;
    try
    {
        
        if (denum == 0) 
            throw denum;
        else
            res = num / denum;
    }

    catch(int denum)
    {
        cout<<"Exception : Zero division error."<<endl;
    }
    cout<<"Result is :"<<res<<endl;
    return 1;
}