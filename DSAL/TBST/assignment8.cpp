// Construct In ordered Threaded binary Search Tree. Perform its inorder traversal. Display
// Smallest and largest value in it. Display lbit and rbit of each node.

// 1. create + insert                   done
// 2. inorder traversal                 done
// 3. smallest and largest value        done
// 4. display lbit and rbit             done

// 5. delete
// 6. preorder                          done

#include <iostream>
using namespace std;

class node
{
    int data;
    node *left, *right;
    bool lbit, rbit;    // true if pointer is to child
    // false if pointer is to successor

public:
friend class TBST;
    node()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
        lbit = 0;
        rbit = 0;
    }

    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
        lbit = false;
        rbit = false;        
    }
};

class TBST
{
    
    node *head;
    node *root = nullptr;

    public:
    TBST()
    {
        this->head->data = 0;
        this->head->right = this->head;
        this->head->left = this->head;
        this->head->lbit = 0;
        this->head->rbit = 1;

        this->root = nullptr;
    }

    void smallest_print()
    {
        node *current = root;
        while(current->lbit == 1)
        {
            current = current->left;
        }
        cout<<current->lbit<<"|"<<current->data<<"|"<<current->rbit<<endl;
    }

    void insert(int x)
    {
        node *newnode = new node(x);
        if(this->root == nullptr)
        {
            this->root = newnode;
            this->root->lbit = 0;
            this->root->left = this->head;
            this->root->rbit = 0;
            this->root->right = this->head;

            this->head->left = this->root;
            this->head->lbit = 1;
        }

        else
        {

            node *current = this -> root;
            node *previous = nullptr;

            while(true){  //find position
                previous = current;
                if(x < current -> data){
                    if(current -> lbit == 1){
                        current = current -> left;
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(current -> rbit == 1){
                        current = current -> right;
                    }
                    else{
                        break;
                    }
                }
            }
            if(x < previous -> data){
                newnode -> lbit = previous -> lbit;
                newnode -> left = previous -> left;
                newnode -> rbit = 0;
                newnode -> right = previous;
                previous -> lbit = 1;
                previous -> left = newnode;
            }
            else{
                newnode -> rbit = previous -> rbit;
                newnode -> right = previous -> right;
                newnode -> lbit = 0;
                newnode -> left = previous;
                previous -> rbit = 1;
                previous -> right = newnode;
            }
        }
    }

    void inOrder()
    {
        node * curr = this->head;
        while(1)
        {
            curr = inOrderSuccessor(curr);
            if(curr == this->head)
            {
                cout<<endl;
                return;
            }
            cout<<curr->lbit<<"|"<<curr->data<<"|"<<curr->rbit<<"   ";
        }
    }   
    node *inOrderSuccessor(node *nod)
    {
        node *temp = nod->right;
        if(nod -> rbit == 1){
            while(temp -> lbit != 0){
                temp = temp -> left;
            }
        }
        return temp;
    }

    void largest_print()
    {
        node * temp = root;
        while(temp->rbit == 1)
        {
            temp = temp->right;
        }
        cout<<temp->lbit<<"|"<<temp->data<<"|"<<temp->rbit<<endl;
    }

};


int main()
{
    TBST t;
    t.insert(50);
    t.insert(60);
	t.insert(30);
	t.insert(10);
	t.insert(20);
	t.insert(40);
	t.insert(80);
	t.insert(75);

    t.largest_print();
    t.smallest_print();
    t.inOrder();
    return 0;
}