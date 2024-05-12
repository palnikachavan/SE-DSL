// Beginning with an empty binary tree, construct binary tree by inserting the values in the
// order given. After constructing a binary tree perform following operations on it-
// • Perform non-recursive inorder traversal, recursive postorder
// • Level wise printing
// • Display and count leaf nodes
// • Display and count internal nodes

// 1. Create + insert           done
// 2. Postorder recursive       done
// 3. inorder recursive         done
// 4. BFS(queue)                done
// 5. Leaf nodes                done
// 6. Internal nodes            done

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node {
public:
    friend class binarytree;
    int data;
    node* left;
    node* right;
    node() {
        data = 0;
        left = NULL;
        right = NULL;
    }

    node(int d) {
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
        root = NULL;
    }
    void insert(int d)
    {
        node *newnode = new node(d);
        if (root == NULL)
        {
            root = newnode;
            cout<<"Root added"<<endl;
            return;
        }
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if(temp->left == NULL)
            {
                temp->left = newnode;
                cout<<"Left Child Added"<<endl;
                return;
            }
            else if(temp->right == NULL)
            {
                temp->right = newnode;
                cout<<"Right Child Added"<<endl;
                return;
            }
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
    }

    void preorder(node * root)
    {
        if(root != NULL)
        {
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    int leaf_nodes(node* root)
    {
        if(root == NULL)
            return 0;
        else if(root->left == NULL && root->right == NULL)
            return 1;
        else
            leaf_nodes(root->left) + leaf_nodes(root->right);
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

    void BFS()
    {
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            node *temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!= NULL)
                q.push(temp->left);
            if(temp->right!= NULL)
                q.push(temp->right);
        }
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
    b.insert(7);
    b.insert(8);
        


    // b.preorder(b.root);
    b.BFS();
    return 0;
}