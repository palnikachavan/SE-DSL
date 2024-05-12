// Construct binary search tree. Provide facility for adding new entries. Provide facility to
// display whole data sorted in descending order using non-recursive traversal.
// Find Minimum and maximum data value in tree. Also find how many maximum
// comparisons may require for finding any keyword.

// 1. create + insert                                   done
// 2. display descending order using non recursive      done
// 3. min and max data value                            done
// 4. search and no of comparisions                     done

#include <iostream>
#include <stack>
using namespace std;

class node
{
    int data;
    node* left, *right;
public:
    friend class BST;
    node()
    {
        data = 0;
        left = right = NULL;
    }
    node(int d)
    {
        data = d;
        left = right = NULL;
    }

};

class BST
{
    public:
    node * root;
    BST()
    {
        root = NULL;
    }
    void insert(int d)
    {
        node * newnode = new node(d);
        if(root == NULL)
        {
            root = newnode;
            cout<<"Root added"<<endl;
            return;
        }
        node * temp = root;
        while(1)
        {
            if(temp->data == d)
            {
                cout<<"Repeating Value"<<endl;
                break;
            }
            else if(temp->data > d && temp->left != NULL)
            {
                temp = temp->left;
            }
            else if (temp->data < d && temp->right != NULL)
            {
                temp = temp->right;
            }
            else if(temp->data > d && temp->left == NULL)
            {
                temp->left = newnode;
                cout<<"Left Child Added"<<endl;
                break;
            }
            else if (temp->data < d && temp->right == NULL)
            {
                temp->right = newnode;
                cout<<"Right Child Added"<<endl;
                break;
            }

        }

    }

    void search(int d)
    {
        int count = 0;
        node *temp = root;
        while(temp != NULL)
        {
            if(temp->data == d)
            {
                cout<<"Found"<<endl;
                break;
            }
            else if(temp->data > d && temp->left != NULL)
            {
                temp = temp->left;
                count++;
            }
            else if(temp->data < d && temp->right != NULL)
            {
                temp = temp->right;
                count++;
            }
            else if(temp->data > d && temp->left == NULL)
            {
                cout<<"Not Found"<<endl;
                count++;
                break;
            }
            else if(temp->data < d && temp->right == NULL)
            {
                cout<<"Not Found"<<endl;
                count++;
                break;
            }
            
        }
        cout<<"No of Comparisons : "<<count<<endl;
    }

    int maxValue()
    {
        node * temp = root;
        while(temp->right!= NULL)
        {
            temp = temp->right;
        }
        return temp->data;
    }

    int minValue()
    {
        node * temp = root;
        while(temp->left!= NULL)
        {
            temp = temp->left;
        }
        return temp->data;
    }

    void descending()
    {
        
        stack <node *> s;
        node *current = this -> root;

        while(!s.empty() || current!=nullptr){
            //Reach the right most node of the current node
            //Push each right node into the stack
            while(current!=nullptr){
                s.push(current);
                current = current -> right;
            }

            //current is null so pop the stack and print the data
            current = s.top();
            s.pop();

            cout<<current -> data<<" ";

            //now check the left part
            current = current -> left;
        }
        cout<<endl;
    }
    
};

int main()
{
    BST b;
    b.insert(25);
    b.insert(20);
    b.insert(30);
    b.insert(15);
    b.insert(18);
    b.insert(35);
    // b.insert();

    // b.search(20);
    // b.search(50);

    // cout<<"Max Value is :"<<b.maxValue();

    b.descending();

    return 0;
}