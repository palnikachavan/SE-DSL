// Direct access file
// Implementation of a direct access file -Insertion and deletion of a record from a direct
// access file.

// 1. create + insert + display    done
// 2. delete 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee
{
    int empid, experience, salary;
    string name;
    public:
    Employee(int empid, int experience, string name, int sal)
    {
        this->empid = empid;
        this->experience = experience;
        this->name = name;
        this->salary = sal;
    }
    Employee()
    {
        empid = 0;
        experience = 0;
        name = "";
        salary = 0;
    }
    string toString()
    {
        string output ;
        return output + to_string( empid ) + "-" + name + "-" + to_string( experience ) + "-" + to_string( salary );
	}
    friend class File;
};

class File
{
    int *table;
    string filename;

    public:
    File(string filename)
    {
        this->filename = filename; 
    }

    void write (Employee * employee, int m)
    {
        ofstream output;
        output.open(filename, ios::out);
        for(int i = 0; i < m; i++)
        {
            output << employee[i].toString() << endl;
            
        }
        output.close();
    }

    void print()
    {
        ifstream input; 
        input.open(filename, ios::in);
        string line;
        while(getline(input, line))
        {
            cout << line << endl;
        }
        input.close();
    }
};

int main()
{
    File f("employees.txt");
    Employee emp[3] = {
        Employee(101, 2, "Palnika", 1000),
        Employee(101, 2, "Helo", 150),
        Employee(101, 2, "world", 200)
    };
    f.write(emp, 3);
    f.print();
    return 0;
}