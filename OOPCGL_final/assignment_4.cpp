#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Person
{
    string name;
    int age, phno;
    string gender;

    public:
    void getData()
    {
        cout<<"Enter Name :";
        cin>>name;
        cout<<"Enter Age :";
        cin>>age;
        cout<<"Enter Phone number :";
        cin>>phno;
        cout<<"Enter Gender :";
        cin>>gender;
    }

    void display()
    {
        cout<<"name :"<<name<<endl;
        cout<<"age :"<<age<<endl;
        cout<<"PHNO :"<<phno<<endl;
        cout<<"gender :"<<gender<<endl;
    }

};
int main()
{
    Person p;
    ofstream f;
    int n;
    f.open("new.txt", ios::out);
    cout<<"Number of objects :";
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        p.getData();
        f.write(reinterpret_cast <char*>(&p), sizeof(p));
    }
    f.close();

    ifstream fi;
    fi.open("new.txt"s, ios::in);
    for (int j  =0 ; j < n; j++)
    {
    fi.read(reinterpret_cast <char*>(&p), sizeof(p));
    p.display();

    }


    return 1;
}