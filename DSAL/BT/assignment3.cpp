// Beginning with an empty binary tree, construct binary tree by inserting the values in the
// order given. After constructing a binary tree perform following operations on it-
// • Perform inorder, recursive traversal
// • Preorder, post-order non-recursive traversal
// • Find mirror image of a tree


// 1. insert                                    done
// 2. inorder recursive                         done
// 3. preorder and post-order non-recursive     done
// 4. mirror image of tree                      done

#include <iostream>
#include <queue>
#include <stack>


using namespace std;

class node
{
    int data;
    node * left;
    node* right;
    public:
    friend class binarytree;
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
        node * newnode = new node(d);
        if(root == NULL)
        {
            root = newnode;
            cout<<"Root Added"<<endl;
            return;
        }
        node * temp;
        queue <node*> q;
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

    void inorder(node* root)
    {
        if(root!= NULL)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }

    void insert_rev(int x)
    {
        node * newnode = new node(x);
        if(root == NULL)
        {
            root = newnode;
            cout<<"Root Added"<<endl;
            return;
        }
        node * temp;
        queue <node*> q;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->right == NULL)
            {
                temp->right = newnode;
                cout<<"Right Added"<<endl;
                return;
            }
            else if(temp->left == NULL)
            {
                temp->left = newnode;
                cout<<"Left Added"<<endl;
                return;
            }
            else
            {
                q.push(temp->right);
                q.push(temp->left);
            }
        }
    }

    void displayPreorder(){
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

    void displayPostorder(){
        stack <node *> s1,s2;
        s1.push(this -> root);
        node *current = nullptr;

        while(!s1.empty()){
            //pop the top element of first stack and push it into the second stack
            current = s1.top();
            s2.push(current);
            s1.pop();

            //now push left child first into s1 and then right so while pop it will go in postorder
            if(current -> left != nullptr){
                s1.push(current -> left);
            }
            if(current -> right != nullptr){
                s1.push(current -> right);
            }
        }

        //now all the nodes of the tree are traversed
        //now the stack s2 is in postorder reversed
        //so pop and display each element
        
        while(!s2.empty()){
            current = s2.top();
            cout<<current -> data<<" ";
            s2.pop();
        }
        cout<<endl;
    }


    binarytree mirror_img(node * root)
    {
        binarytree b;
        if (root == NULL)
            return b;

        b.root = root;
        node * temp = b.root;
        if(temp->left != NULL && temp->right != NULL)// || (temp->left != NULL && temp->right != NULL))
        {
            node *swap = temp->left;
            temp->left = temp->right;
            temp->right = swap;
        }
        else
        {
            return b;
        }
        mirror_img(temp->left);
        mirror_img(temp->right);

        return b;
    }
};

int main()
{
    binarytree b, b1;
    b.insert(1);
    b.insert(2);
    b.insert(3);
    b.insert(4);
    b.insert(5);
    b.insert(6);
    b.insert(7);

    b.inorder(b.root);
    cout<<endl;
    b1 = b.mirror_img(b.root);
    b1.inorder(b1.root);
    return 0;
}