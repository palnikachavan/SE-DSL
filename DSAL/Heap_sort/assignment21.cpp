// Implement the Heap sort algorithm for demonstrating heap data structure with modularity
// of programming language (consider integer data)

#include <iostream>
#include <queue>
using namespace std;

class node
{
    int data;
    node *left, *right;
    public:
    node()
    {
        data = 0;
        left = right = NULL;
    }
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
    friend class BT;
};

class BT
{
    public:
    node * root;
    int cnt;

    BT()
    {
        root = NULL;
        cnt = 0;
    }

    void insert(int x)
    {
        node * newnode = new node(x);
        if(root == NULL)
        {
            root = newnode;
            cnt = 1;
            return;
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node * curr = q.front();
            q.pop();
            if(curr->left != NULL && curr->right != NULL)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
            else if(curr->left == NULL)
            {
                curr->left = newnode;
                cnt++;
                return;
            }
            else if(curr->right == NULL)
            {
                curr->right = newnode;  
                cnt++;
                return;
            }
        }
    }

    void BFS()
    {
        if(root == NULL)
        {
            return;
        }
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node * curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }
            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }

    node * lastnode(node * root)
    {
        if (root == NULL)
        {
            return nullptr;
        }
        queue<node *> q;
        node * current = root;
        q.push(root);
        while(!q.empty())
        {
            current = q.front();
            q.pop();
            if(current->left != NULL)
            {
                q.push(current->left);
            }
            if(current->right != NULL)
            {
                q.push(current->right);
            }
        }
        return current;
    }

    node * max_heap_tree(node * root)
    {
        if (root == NULL)
        {
            return nullptr;
        }
        root->left = max_heap_tree(root->left);
        root->right = max_heap_tree(root->right);

        if(root->left != NULL && root->left->data > root->data)
        {
            int temp = root->data;
            root->data = root->left->data;
            root->left->data = temp;
        }
        if(root->right != NULL && root->right->data > root->data)
        {
            int temp = root->data;
            root->data = root->right->data;
            root->right->data = temp;
        }
        return root;
    }

    node* deletenode(node * root, int key)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root->data == key)
        {
            delete root;
            return nullptr;
        }
        root -> left = deletenode(root -> left,key);
        root -> right = deletenode(root -> right,key);
        return root;
    }

    void heap_sort()
    {
        for(int i = 0; i < cnt; i++)
        {
            max_heap_tree(root);
            node *last = lastnode(root);
            int tem = last->data;
            last->data = root->data;
            root->data = tem;

            cout<<last->data<<" ";
            deletenode(this->root, last->data);
        }
    }

};

int main()
{
    BT b;
    b.insert(87);
    b.insert(12);
    b.insert(75);
    b.insert(91);
    b.insert(44);
    b.insert(57);
    b.insert(68);
    b.BFS();
    cout<<endl;
    b.heap_sort();
    return 0;
}