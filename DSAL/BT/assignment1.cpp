// Beginning with an empty binary tree, construct binary tree by inserting the values in the
// order given. After constructing a binary tree perform following operations on it-
// • Perform preorder recursive traversal
// • Postorder, Inorder non-recursive traversal
// • Count number of leaves, number of internal nodes.



// insert                                   done
// preorder recursive                       done
// postorder and inorder non recursive      done
// no of leaf and internal nodes            done

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class node
{
    int data;
    node * left;
    node * right;

    public:
    friend class binarytree;
    node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    node (int d)
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
        root = NULL;
    }

    void insert(int d)
    {
        node* newnode = new node(d);
        if(root == NULL)
        {
            root = newnode; 
            cout<<"Node Inserted as Root"<<endl;
            
        }
        else
        {
            queue<node*> q;
            q.push(root);

            while(!q.empty())
            {
                node* current = q.front();
                q.pop();

                if(current->left == NULL)
                {
                    current->left = newnode;
                    cout<<"Node Inserted as Left child"<<endl;
                    break;
                }
                else if(current->right == NULL)
                {
                    current->right = newnode;
                    cout<<"Node Inserted as Right child"<<endl;
                    break;
                }
                else
                {
                    q.push(current->left);
                    q.push(current->right);
                }
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

    int leaf_nodes(node * root)
    {
        if(root == NULL)
            return 0;
        else if(root->left == NULL && root->right == NULL)
            return 1;
        else
            return leaf_nodes(root->left) + leaf_nodes(root->right);
    }

    int internal_nodes(node * root)
    {
        if(root == NULL)
            return 0;
        else if(root->left == NULL && root->right == NULL)
            return 0;
        else
            return internal_nodes(root->left) + internal_nodes(root->right) + 1;
    }

    void postorder(node* root) {
        if (root == nullptr) return;

        stack<node*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            node* current = s1.top();
            s1.pop();
            s2.push(current);

            if (current->left != nullptr)
                s1.push(current->left);
            if (current->right != nullptr)
                s1.push(current->right);
        }

        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
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


};

int main()
{
    binarytree b;
    int x;
    b.insert(1);
    b.insert(5);
    b.insert(6);
    b.insert(7);
    b.insert(8);

    b.postorder(b.root);
    cout<<endl;
    cout<< "Leaf nodes are "<<b.leaf_nodes(b.root);
    cout<<endl;
    cout<< "internal nodes are "<<b.internal_nodes(b.root);
    return 0;
}