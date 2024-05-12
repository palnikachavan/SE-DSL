#include <iostream>
#include <map>
#include <string.h>
#define max 30
using namespace std;

int main()
{
    string stat[max];
    int n, i = 0;
    int popu[max];
    map <string, int> states;
    cout<<"Enter Number of States :";
    cin>>n;
    while(i<n)
    {
        cout << "Enter State name :";
        cin >> stat[i];
        cout << "Enter population :";
        cin >> popu[i];
        states[stat[i]] = popu[i];
        cout << endl;   
        i++;
    }

    cout<<"Displaying.. "<<endl;
    map <string, int> ::iterator itr;
    itr = states.begin();
    while (itr != states.end())
    {
        cout<<(*itr).first<<" : "<<(*itr).second<<endl;
        itr ++ ;
    }
    
    string x;
    cout<<"Enter State to find :";
    cin>>x;
    if(states.find(x) != states.end())
    {
        int pop = states[x];
        cout<<"Population is :"<<pop<<endl;
    }
    else
    {
        cout<<"State not found."<<endl;
    }

    return 1;
}