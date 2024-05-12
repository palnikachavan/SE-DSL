// Beginning with an empty binary tree, construct binary tree by inserting the values in the
// order given. After constructing a binary tree perform following operations on it-
// • Perform post order recursive traversal
// • Inorder, Preorder non-recursive traversal
// • Find the height of tree

// 1. insert                                done
// 2. postorder recursive                   done
// 3. inorder and preorder non recursive    done
// 4. height of the tree                    done


#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
    int data;
    node* left;
    node * right;
    public:
    friend class binarytree;
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class binarytree
{
    public:
    node * root;
    binarytree()
    {
        root =NULL;
    }
    void insert(int d)
    {
        node *newnode = new node(d);
        if(root == NULL)
        {
            root = newnode;
            cout<<"Root Added"<<endl;
            return;
        }
        node * temp;
        queue <node *> q;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->left == NULL)
            {
                temp->left = newnode;
                cout<<"Left Added"<<endl;
                return;
            } 
            else if(temp->right == NULL)
            {
                temp->right = newnode;
                cout<<"Right Added"<<endl;
                return;
            }
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }

    void postorder(node* root)
    {
        if(root != NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }

    int height(node * root)
    {
        int count = 1;
        while(root->left != NULL)
        {
            count++;
            root = root->left;
        }
        return count;
    }

    void inorder(node* root) {
        if (root == nullptr) return;
        stack<node*> s;
        node* current = root;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    void preorder(){
        stack <node *> s;
        s.push(this -> root);
        node *current = nullptr;
        while(!s.empty()){
            current = s.top();
            cout<<current -> data<<" ";
            s.pop();

            //now push right child first and then left so that pop time, left comes first 
            if(current -> right != nullptr){
                s.push(current -> right);
            }
            if(current -> left != nullptr){
                s.push(current -> left);
            }
        }
        cout<<endl;
    }

};

int main()
{
    binarytree b;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.insert(5);
    b.insert(6);

    b.preorder();
    cout<<endl;
    cout<<"Height is :"<<b.height(b.root)<<endl;
    return 0;
}