// Construct binary search tree. Provide facility for adding new entries, deleting any
// element. Provide facility to display whole data sorted in ascending order using non-
// recursive traversal. Search an element present in a tree and display number of
// comparisons required to search.

// 1. create + insert                                               done
// 2. deleting entries                                              done
// 3. non recursive inorder traversal                               done
// 4. search element and display number of searches required        done

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

    void insert(int x)
    {
        node * newnode = new node(x);
        if(root == NULL)
        {
            root = newnode;
            cout<<"Root Added"<<endl;
            return;
        }
        node * current = root;
        while(1)
        {
            if(current->data == x )
            {
                cout<<"Repeating Value"<<endl;
                break;
            }
            else if(current->data > x && current->left != NULL)
            {
                current = current->left;
            }
            else if(current->data < x && current->right != NULL)
            {
                current = current->right;
            }
            else if(current->data > x && current->left == NULL)
            {
                current->left = newnode;
                cout<<"Left Child Added"<<endl;
                break;
            }
            else if(current->data < x && current->right == NULL)
            {
                current->right = newnode;
                cout<<"Right Child Added"<<endl;
                break;
            }

        }
    }

    void displayInorder(){
        stack <node *> s;
        node *current = this -> root;

        while(!s.empty() || current!=nullptr){
            //Reach the left most node of the current node
            //Push each left node into the stack
            while(current!=nullptr){
                s.push(current);
                current = current -> left;
            }

            //current is null so pop the stack and print the data
            current = s.top();
            s.pop();

            cout<<current -> data<<" ";

            //now check the right part
            current = current -> right;
        }
        cout<<endl;
    }

    int search(int x)
    {
        int count = 0;
        node * current = root;
        while(1)
        {
            if(current == NULL)
            {
                cout<<"Element not found"<<endl;
                break;
            }
            else if(current->data == x)
            {
                cout<<"Element Found"<<endl;
                break;
            }
            else if(current->data > x)
            {
                current = current->left;
            }
            else if(current->data < x)
            {
                current = current->right;
            }
            
            count++;
        }
        return count ;
        
    
    }


    node *minValueNode(node *Node)
    {
        node *current = Node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    node *deleteNode(node *root, int keyw)
    {
        if (root == NULL)
            return root;

        if (keyw < root->data)
            root->left = deleteNode(root->left, keyw);
        else if (keyw > root->data)
            root->right = deleteNode(root->right, keyw);
        else
        {
            if (root->left == NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }
            node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
};

int main()
{
    BST b;
    b.insert(15);
    b.insert(20);
    b.insert(10);
    b.insert(9);
    b.insert(7);
    b.insert(2);

    b.displayInorder();

    int x = b.search(9);  //successful search
    cout<<"Number of comparisions "<<x<<endl;
    x = b.search(1);      //unsuccessful search
    cout<<"Number of comparisions "<<x<<endl;

    b.deleteNode(b.root, 15);
    b.displayInorder();



    return 0;
}