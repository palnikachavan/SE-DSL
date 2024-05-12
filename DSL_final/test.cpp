#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string a            ;
    int i = 0;
    while (i < 4)
    {
        i = (char)i;
        i++;
    }
    cout<<"string is"<<a<<endl;
    return 1;
}