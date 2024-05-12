// A Dictionary stores keywords and its meanings. Provide facility for adding new keywords.
// Provide facility to display whole data sorted in ascending/ Descending order. Also find
// how many maximum comparisons may require for finding any keyword. Use Height
// balanced (AVL) tree.

// 1. create                            done
// 2. insert                            done
// 3. ascending/ descending             done
// 4. max comparisions for search.      done


#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class node
{
    int data;
    int height;
    node * left, *right;

    public:
    node()
    {
        data = 0;
        height = 1;
        left = right = NULL;
    }

    node(int x)
    {
        data = x;
        height = 1;
        left = right = NULL;
    }
    friend class AVL;
};

class AVL
{
    public:
    node * root;
    AVL()
    {
        root = NULL;
    }

    int getHeight(node * root)
    {   
        if(root == NULL)
        {
            return 0;
        }
        return root->height;
    }

    void changeHeight(node * temp)
    {
        temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    }

    int balanceFactor(node * temp)
    {
        if(temp == NULL)
        {
            return 0;
        }
        return getHeight(temp->left) - getHeight(temp->right);
    }

    node * llrotation(node * temp)
    {
        node * newroot = temp->left;
        temp->left = newroot->right;  //right subtree of middle node given to previous root's left
        newroot->right = temp;

        changeHeight(temp);
        changeHeight(newroot);
        return newroot;
    }

    node * rrrotation(node *temp)
    {
        node *newroot = temp->right;
        temp->left = newroot->left;
        newroot->left = temp;

        changeHeight(temp);
        changeHeight(newroot);
        return newroot;
    }

    node * lrrotation(node * temp)
    {
        temp->left = rrrotation(temp->left);
        return llrotation(temp);
    }

    node * rlrotation(node * temp)
    {
        temp->right = llrotation(temp->right);
        return rrrotation(temp);
    }

    node *balance_node(node *x)
    {   
        if(balanceFactor(x) == 2)  //left imbalance
        {
            if(balanceFactor(x->left) < 0)
            {
                x = lrrotation(x);
            }
            else
            {
                x = llrotation(x);
            }
        }
        if(balanceFactor(x) == -2)  //right imbalance
        {
            if(balanceFactor(x->right) > 0)
            {
                x = rlrotation(x);
            }
            else
            {
                x = rrrotation(x);
            }
        }
        changeHeight(x);
        return x;
    }

    node* insert( node * a,int d)
    {   
        // node * newnode = new node(d);
        if(a == NULL)
        {
            a = new node(d);
            return a;
        }
        if(d < a->data)
        {
            a->left = insert(a->left,d);
        }
        else if(d > a->data)
        {
            a->right = insert(a->right,d);
        }
        else
            return a;
        return balance_node(a);
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
    AVL t;
    t.root = t.insert(t.root,30);
    t.root = t.insert(t.root,20);
    t.root = t.insert(t.root,10);
    t.inorder(t.root);
    return 0;
}

