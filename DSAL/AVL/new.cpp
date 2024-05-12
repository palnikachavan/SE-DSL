#include <iostream>
#include <algorithm>
using namespace std;

class node {
public:
    int data;
    int height;
    node *lchild, *rchild;

    node(int val) {
        data = val;
        height = 1;
        lchild = nullptr;
        rchild = nullptr;
    }
};

class avl {
public:
    node *root;

    avl() {
        root = nullptr;
    }

    int getHeight(node *n) {
        if (!n)
            return 0;
        return n->height;
    }

    int getBalanceFactor(node *n) {
        if (!n)
            return 0;
        return getHeight(n->lchild) - getHeight(n->rchild);
    }

    node *ll_rot(node *node1) {
        node *temp = node1->lchild;
        node1->lchild = temp->rchild;
        temp->rchild = node1;

        // Update heights
        node1->height = 1 + max(getHeight(node1->lchild), getHeight(node1->rchild));
        temp->height = 1 + max(getHeight(temp->lchild), node1->height);

        cout << "Performed LL rotation" << endl;
        return temp;
    }

    node *rr_rot(node *node1) {
        node *temp = node1->rchild;
        node1->rchild = temp->lchild;
        temp->lchild = node1;

        // Update heights
        node1->height = 1 + max(getHeight(node1->lchild), getHeight(node1->rchild));
        temp->height = 1 + max(getHeight(temp->rchild), node1->height);

        cout << "Performed RR rotation" << endl;
        return temp;
    }

    node *lr_rot(node *node1) {
        // {
        node1->lchild = rr_rot(node1->rchild);
        return ll_rot(node1);
    }


    node *insert(node *root1, int a) {
        // Perform standard BST insertion
        if (!root1) {
            root1 = new node(a);
            cout << "Node Added ----> " << a << endl;
            return root1;
        }

        if (a < root1->data)
            root1->lchild = insert(root1->lchild, a);
        else if (a > root1->data)
            root1->rchild = insert(root1->rchild, a);
        else
            return root1; // Duplicate keys are not allowed in AVL

        // Update height of the current node
        root1->height = 1 + max(getHeight(root1->lchild), getHeight(root1->rchild));

        // Get the balance factor of this node
        int balance = getBalanceFactor(root1);

        // Perform rotations if needed to balance the tree

        // Left Left Case (LL)
        if (balance > 1 && a < root1->lchild->data)
            return ll_rot(root1);

        // Right Right Case (RR)
        if (balance < -1 && a > root1->rchild->data)
            return rr_rot(root1);

        // Left Right Case (LR)
        if (balance > 1 && a > root1->lchild->data)
            return lr_rot(root1);

        return root1;
    }

    void inorder(node *root) {
        if (!root)
            return;
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
};

int main() {
    avl a;
    a.root = a.insert(a.root, 40);
    a.root = a.insert(a.root, 30);
    a.root = a.insert(a.root, 20);
    a.root = a.insert(a.root, 25);

    cout << "Inorder Traversal: ";
    a.inorder(a.root);
    cout << endl;

    return 0;
}