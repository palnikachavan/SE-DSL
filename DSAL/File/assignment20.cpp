// Department maintains a student information. The file contains roll number, name, division
// and address. Allow user to add, delete information of student. Display information of
// particular employee. If record of student does not exist an appropriate message is
// displayed. If it is, then the system displays the student details. Use sequential file to
// maintain the data.


// 1. create a File         done
// 2. Display records       done
// 3. insert records        done
// 4. delete records
// 5. search and display    done


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
    int rollno, division;
    string name, address;

    public:
    friend class File;
    Student()
    {
        rollno = 0;
        division = 0;
        name = "";
        address = "";
    }

    Student(string name, string address, int rollno, int division)
    {
        this->rollno = rollno;
        this->division = division;
        this->name = name;
        this->address = address;
    }

};

class File{
    string fileName;
    fstream input;
    fstream output;

public:
    File(string title){
        this -> fileName = title;
    }

    void write(Student *r,int num){
        output.open(fileName , ios::out);
        for(int i=0;i<num;i++){
            output<<r[i].rollno<<","<<r[i].name<<",SE-"<<r[i].division<<","<<r[i].address<<endl;
        }
        output.close();
    }

    void print_all(){
        input.open(fileName , ios::in);
        while(!input.eof()){
            string record;
            input>>record;
            cout<<record<<endl;
        }
        input.close();
    }

    void search(string a)
    {
        input.open(fileName , ios::in);
        bool isFound = false;
        while(!input.eof()){
            string record;
            getline(input, record);
            string rol = record.substr(0,2);
            if(rol == a){
                isFound = true;
                cout<<"Record found...."<<endl;
                cout<<record<<endl;
                break;
            }
        }
        input.close();
        if(!isFound){
            cout<<"Record not found...."<<endl;
        }
    }

    void delete_record(string r, const char a[])
    {
        input.open(fileName, ios::in);
        // char x[] = fileName;
        output.open("replace.txt", ios::out);
        while(!input.eof())
        {
            string record;
            getline(input, record);
            string rol = record.substr(0,2);
            if(rol == r){
                continue;
            }
            output<<record<<endl;
        }
        if(rename("replace.txt",a) != 0)
        {
            cout<<"Deleted Successfully!"<<endl;
        }
    }
};

int main()
{
    Student s[3] = {
        Student("Palnika", "Pune", 53,3),
        Student("Aakanksha", "Dhairi", 52,3),
        Student("Yashraj", "Pune", 54,3)     
    };

    File f("student.txt");
    const char a[] = "student.txt";
    f.write(s,3);
    f.print_all();
    int x;
    cout<<"Enter roll no to search ";
    cin>>x;
    string rol = to_string(x);
    f.search(rol);

    // f.delete_record(rol, a);
    return 0;
}
