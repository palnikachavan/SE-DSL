#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class info
{
public:
    string name;
    int roll,date,month,year;
    void inp()
    {
        cout<<"enter name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"enter roll number: ";
        cin>>roll;
        cout<<"Enter DOB [dd/mm/yyyy]"<<endl;
        cout<<"Date: ";
        cin>>date;
        cout<<"Month: ";
        cin>>month;
        cout<<"Year: ";
        cin>>year;
    }

    void op()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Roll number: "<<roll<<endl;
        cout<<"DOB: "<<date<<"/"<<month<<"/"<<year<<endl;
        cout<<"------------------"<<endl;
    }
};

int search_name(vector<info> &i,string x)
{
    vector<info>::iterator it;
    int d=0;
    for ( it = i.begin(); it!=i.end() ; it++)
    {
        if (it->name==x){
            return d+1;
        }
        d++;
    }
}

int search_roll(vector<info> &i,int x)
{
    vector<info>::iterator it;
    int d=0;
    for ( it = i.begin(); it!=i.end() ; it++)
    {
        if (it->roll==x)
        {
            return d+1;
        }
        d++;
    }
}

bool sort_name(info i1,info i2)
{
    return(i1.name<i2.name);

}

bool sort_roll(info i1,info i2)
{
    return(i1.roll<i2.roll);

}

int main()
{
    vector<info> v;
    vector<info>::iterator it;
    info i;
    int n,sroll;
    string sname;
    cout<<"Total inp data: ";
    cin>>n;
    for (int j = 0; j < n; j++)
    {
        i.inp();
        v.push_back(i);
    }
    cout<<"DISPLAY: "<<endl;
    for ( it = v.begin(); it!=v.end() ; it++)
    {
        it->op();
    }
    cout<<"Search "<<endl;
    cout<<"using name enter name: ";
    cin>>sname;
    cout<<search_name(v,sname);
    cout<<endl;
    cout<<"using roll number enter roll: ";
    cin>>sroll;
    cout<<search_roll(v,sroll);
    cout<<endl;
    cout<<"Sorting by name: ";
    sort(v.begin(),v.end(),sort_name);
    for ( it = v.begin(); it!=v.end() ; it++)
    {
       cout<<it->name<<endl;
    }
    cout<<endl;
    cout<<"Sorting by roll: ";
    sort(v.begin(),v.end(),sort_roll);
    for ( it = v.begin(); it!=v.end() ; it++)
    {
       cout<<it->roll<<endl;
    }
    

    return 0;
    
}