// Consider telephone book database of N clients. Make use of a hash table implementation
// to quickly look up client‘s telephone number. Make use of two collision handling
// techniques and compare them using number of comparisons required to find a set of
// telephone numbers (Note: Use linear probing with replacement and without
// replacement). Perform following operations
// 1) Insert
// 2) Display
// 3) Search (number of comparisons required to search)
// Use Hash function as H(x) = (3*x + 5)%10

// 1. create + insert                                               done
// 2. display                                                       done
// 3. search + no of comparisions req                               done
// 4. linear probing with and without replacement simultaneously    done 
// 5. delete

#include <iostream>
using namespace std;

class record
{
    int phno;
    public:
    record()
    {
        phno = 0;
    }
    record(int phno)
    {
        this->phno = phno;
    }
    friend class hashtable;
};

class hashtable
{
    record arr[10];
    public:

    void display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << i<<"   "<< arr[i].phno << endl;
        }
        cout << endl;
    }

    int hash_func(int phno)
    {
        long int ind = (3 * phno + 5);   //range 8 bytes long   and   4 bytes int
        int x = ind % 10;
        return x;
    }

    void insert_without_rep(int phno)
    {
        int ind = hash_func(phno);
        if (arr[ind].phno == 0)
        {
            arr[ind].phno = phno;
            // cout<<"Record Inserted"<<endl;
            return;
        }
        else
        {
            if(ind >= 9)
            {
                ind = 0;
            }
            while(arr[ind].phno != 0 && arr[ind].phno != phno)
            {
                
                if(ind >= 9)
                {
                    ind = 0;
                }
                ind ++;
            }
            if(arr[ind].phno == phno)
            {
                cout<<"Record Already Exists"<<endl;
                return;
            }
            arr[ind].phno = phno;
            // cout<<"Record Inserted"<<endl;
        }
    }

    void insert_with_rep(int phno)
    {
        int ind = hash_func(phno);
        if(arr[ind].phno == 0)
        {
            arr[ind].phno = phno;
            // cout<<"Record Inserted"<<endl;
            return;
        }
        int ind2 = hash_func(arr[ind].phno);
        if(ind2 == ind)
        {
            insert_without_rep(phno);
            return;
        }
        int rep = arr[ind].phno;
        arr[ind].phno = phno;
        insert_with_rep(rep);
    }

    void delete_record(int phno)
    {
        cout<<"Deleting record "<<phno<<endl;
        int i = search(phno);
        if (i == -1)
        {
            // cout<<"Element not found."<<endl;
            return;
        }
        arr[i].phno = 0;
    }

    int search(int x)
    {
        int i = hash_func(x);
        int cmp = 1;
        if(arr[i].phno == x)
        {
            cout<<"Element Found at position "<<i<<endl;
            return i;
        }
        else
        {
            while(1)
            {
                i++;
                if(i > 9)
                    i = 0;
                cmp++;
                if(arr[i].phno == x)
                {
                    cout<<"Element Found at position "<<i<<endl;
                    break;
                }
                if (cmp > 10)
                {
                    cout<<"Element not found."<<endl;
                    i = -1;
                    break;
                }
                
            }
        }
        cout<<"Number of Comparisions needed "<<cmp<<endl;
        return i;
        cout<<endl;
    }
};

int main()
{
    hashtable h;
    // h.display();
    // h.insert_without_rep(10);
    // h.insert_without_rep(20);
    // h.insert_without_rep(10);

    h.insert_with_rep(11);
    h.insert_with_rep(21);
    h.insert_with_rep(5);
    h.insert_with_rep(15);
    h.insert_with_rep(41);
    h.display();
    // h.search(20);
    h.delete_record(81);
    h.display();
    return 0;
}