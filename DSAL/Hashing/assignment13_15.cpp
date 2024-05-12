// Implement all the functions of a dictionary (ADT) using open hashing technique: separate
// chaining using linked list Data: Set of (key, value) pairs, Keys are mapped to values, Keys
// must be comparable, and Keys must be unique. Standard Operations: Insert (key, value),
// Find(key), Delete(key). Use hash function as H(x) = (3x+5) %10

// separate chaining
// 1. insert        done
// 2. find          done
// 3. delete        done
// 4. display       done

// hash func = (3x + 5 ) % 10

#include <iostream>
#include <string>
using namespace std;

class record
{
    string key, value;
    record * next;
    public:
    friend class hashtable;
    record()
    {
        key = "";
        value = "";
        next = NULL;
    }
    record(string k, string v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class hashtable
{
    record *arr[10];
    public:
    hashtable()
    {
        for(int i = 0; i < 10; i++)
        {
            arr[i] = NULL;
        }
    }

    int hash_func(string k)
    {
        int sum = 0;
        for (int i = 0; i < k.length(); i++)
        {
            sum += k[i];
        }
        return (3 * sum + 5) % 10;
    }

    void insert(string k, string v)
    {
        int ind = hash_func(k);
        record *temp = new record(k,v);
        if(arr[ind] == NULL)
        {
            arr[ind] = temp;
            cout<<"Node Inserted"<<endl;
            return;
        }
        record * curr = arr[ind];
        while(curr->next != NULL && curr->key != k)
        {
            curr = curr->next;
        }
        if(curr->key == k)
        {
            cout<<"Key already exists"<<endl;
            return;
        }
        curr->next = temp;
        cout<<"Node Inserted ~"<<endl;
    }

    void display()
    {
        for(int i = 0; i < 10; i++)
        {
            record * curr = arr[i];
            cout<<i<<"   ";
            while(curr!= NULL)
            {
                cout<<curr->key<<" : "<<curr->value<<"-->";
                curr = curr->next;
            }
            cout<<endl;
        }
    }


    void search(string k)
    {
        int ind = hash_func(k);
        if(arr[ind]->key == k)
        {
            cout<<"Data Found"<<endl;
            cout<<arr[ind]->key<<" : "<<arr[ind]->value<<endl;
            return;
        }
        record * curr = arr[ind];
        while(curr != NULL)
        {
            if(curr->key == k)
            {
                cout<<"Data Found"<<endl;
                cout<<curr->key<<" : "<<curr->value<<endl;
                return;
            }
            curr = curr->next;
        }
        if(curr == NULL)
        {
            cout<<"Data Not Found"<<endl;
            return;
        }
    }

    void delete_record(string k)
    {
        int ind = hash_func(k);
        if(arr[ind]->key == k)
        {
            arr[ind] = arr[ind]->next;
            return;
        }
        record * curr = arr[ind];
        while(curr->next!= NULL)
        {
            if(curr->next->key == k)
            {
                curr->next = curr->next->next;
                return;
            }
            curr = curr->next;
        }
        if(curr->next == NULL)
        {
            cout<<"Data Not Found"<<endl;
            return;
        }
    }
};

int main()
{
    hashtable h;
    h.insert("abc", "hello");
    h.insert("def", "world");
    h.insert("abc", "hel");
    h.display();

    // h.search("abc");
    // h.search("xyz");

    h.delete_record("abc");
    h.delete_record("xyz");
    h.display();
    return 0;
}