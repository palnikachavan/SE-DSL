// A dictionary stores keywords and its meanings. Provide facility for adding new
// keywords, updating values of any entry, delete any entry. Provide facility to display
// whole data sorted in ascending/ Descending order. Also find how many maximum
// comparisons may require for finding any keyword. Use Binary Search Tree for
// implementation.

// 1. create + insert                                                               done            
// 2. update                                                                        done
// 3. delete                                                                        done
// 4. ascending and descending order (not specified recursive and non recursive)    done
// 5. max comparisions on search                                                    done

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class node
{
    string key, value ;
    node * left, *right;
    public:
    friend class BST;
    node()
    {
        key = "";
        value = "";
        left = right = NULL;
    }
    node (string key, string value)
    {
        this->key = key;
        this->value = value;
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
    void insert(string k, string v)
    {
        node * newnode = new node(k,v);
        if(root == NULL)
        {   
            root = newnode;
            cout<<"Root Added"<<endl;
            return;
        }
        node * temp = root;
        while(temp != NULL)
        {
            if(temp->key == k)
            {
                cout<<"Repeating Value"<<endl;
                break;
            }
            else if(temp->key < k && temp->right != NULL)
            {
                temp = temp->right;
            }
            else if(temp->key > k && temp->left != NULL)
            {
                temp = temp->left;
            }
            else if(temp->key < k && temp->right == NULL)
            {
                temp->right = newnode;
                cout<<"Right Child Added"<<endl;
                break;
            }
            else if(temp->key > k && temp->left == NULL)
            {
                temp->left = newnode;
                cout<<"Left Child Added"<<endl;
                break;
            }
        }

    }

    void update(string k, string v)
    {
        node *found = search(k);
        if(found == NULL)
        {
            return;
        }
        found->value = v;
        cout<<"Value Updated"<<endl;
        cout<<found->key<<" : "<<found->value<<endl;
    }

    node* search(string k)
    {
        node * temp = root;
        int count = 0;
        while(temp != NULL)
        {
            if(temp->key == k)
            {
                cout<<"Data Found"<<endl;
                cout<<temp->key<<" : "<<temp->value<<endl;
                return temp;
            }
            else if(temp->key < k && temp->right != NULL)
            {
                temp = temp->right;
                count++;
            }
            else if(temp->key > k && temp->left != NULL)
            {
                temp = temp->left;
                count++;
            }
            else if(temp->key < k && temp->right == NULL)
            {
                cout<<"Not Found"<<endl;
                count++;
                return nullptr;
                
            }
            else if(temp->key > k && temp->left == NULL)
            {
                cout<<"Not Found"<<endl;
                count++;
                return nullptr;
                
            }
        }
    }

    void ascending(node *temp) // recursive
    {
        if(temp != NULL)
        {
            ascending(temp->left);
            cout<<temp->key<<" : "<<temp->value<<endl;
            ascending(temp->right);
        }
    }

    void descending(node *temp)  // rescursive
    {
        if(temp != NULL)
        {
            descending(temp->right);
            cout<<temp->key<<" : "<<temp->value<<endl;
            descending(temp->left);
        }
    }

    void descending_rec()  //non recursive
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

            cout<<current -> key<<" : "<<current -> value<<endl;

            //now check the left part
            current = current -> left;
        }
        cout<<endl;
    }

    void ascending_rec()  //non recursive
    {
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

            cout<<current -> key<<" : "<<current -> value<<endl;

            //now check the right part
            current = current -> right;
        }
        cout<<endl;
    }

    node *minValueNode(node *Node)
    {
        node *current = Node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    node *deleteNode(node *root, string keyw)
    {
        if (root == NULL)
            return root;

        if (keyw < root->key)
            root->left = deleteNode(root->left, keyw);
        else if (keyw > root->key)
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
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
        return root;
    }
};

int main()
{
    BST b;
    b.insert("ghi", "mno");
    b.insert("abc", "pqr");
    b.insert("def", "xyz");
    b.insert("jkl", "stu");
    b.insert("hefi","efgu");
    b.insert("pnq","pune");
    cout<<endl;
    // b.search("pnq");    
    // cout<<endl;
    // b.search("ppi");
    // cout<<endl;
    // cout<<endl;
    // b.ascending(b.root);
    // cout<<endl;
    // b.descending(b.root);
    // cout<<endl;

    b.update("hefi","heavy");
    cout<<endl;
    b.update("euifoi","etriek");
    return 0;
}