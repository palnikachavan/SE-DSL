#include <iostream>
#include <string.h>
using namespace std;

class Student;

class personal  // personal
{
    string driving_no;
    public:
    void input()
    {
        cout<<"Enter Driving License :";
        cin>>driving_no;
    }
    friend class Student;
};

class Student  // generic
{
    string name ,clas, dob, blood_grp, add;
    int rollno, div, phno;
    personal p;
    public:
    static int cnt;
    Student()
    {
        // default constructor
        cout<<"default constructor ."<<endl;
        cnt++;

    }

    Student(string namee, string clasS, int Div, int Rollno, int Phno, string dOb, string blood, string aDd)
    {
        cout<<"Parameterized Constructor"<<endl;
        name = namee;
        clas = clasS;
        div = Div;
        rollno = Rollno;
        phno = Phno;
        dob = dOb;
        blood_grp = blood;
        add = aDd;
        p.input();
        cnt++;
    }

    Student (Student &s)
    {
        cout<<"Copy Constructor"<<endl;
        this->name = s.name;
        this->clas = s.clas;
        this->div = s.div;
        this->rollno = s.rollno;
        this->phno = s.phno;
        this->dob = s.dob;
        this->blood_grp = s.blood_grp;
        this->add = s.add;
        this->p.driving_no = s.p.driving_no;
        cnt++;
    }

    ~Student()
    {
        cout<<"Student Class Destructor."<<endl;
        cnt--;
        inc_count();
    }

    void input()
    {
        cout<<"Enter Name :";
        cin>>name;
        cout<<"Enter Class :";
        cin>>clas;
        cout<<"Enter Rollno";
        cin>>rollno;
        cout<<"Enter Division :";
        cin>>div;
        cout<<"Enter Phone Number :";
        cin>>phno;
        cout<<"Enter Date of Birth :";
        cin>>dob;
        cout<<"Enter Address :";
        cin>>add;
    }

    void display()
    {
        cout<<"Name :"<<name<<endl;
        cout<<"Class :"<<clas<<endl;
        cout<<"Division :"<<div<<endl;
        cout<<"Roll Number :"<<rollno<<endl;
        cout<<"Phone Number :"<<phno<<endl;
        cout<<"Address :"<<add<<endl;
        cout<<"Date of Birth :"<<dob<<endl;
    }



    void static inline inc_count(){cout<<"Count is :"<<cnt<<endl;}

};
int main()
{
    Student s1;
    s1.display();
    s1.input();
    s1.display();
    cout<<"-------------"<<endl;
    //string namee, string clasS, int Div, int Rollno, int Phno, string dOb, string blood, string aDd)
    Student s2("palnika", "TE", 10, 53, 9284, "8974", "B+ve", "87fyuchgd");
    s2.display();
    cout<<"******************"<<endl;
    Student s3 = s2;
    s3.display();
    cout<<"================================"<<endl;

    return 1;
}

//  dynamic memory alloc using new and delete and exception handling