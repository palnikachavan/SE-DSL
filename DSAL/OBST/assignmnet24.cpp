// Given sequence k = k1 <k2 < … <kn of n sorted keys, with a successful and unsuccessful
// search probability pi and qi for each key ki. Build the Binary search tree that has the least
// search cost given the access probability for each key.

// 1. create + insert
// 2. traverse inorder and preorder
// 3. obst!!


//wrong code

#include <iostream>
using namespace std;

class node
{
    int data;
    node * left, *right;
    public:
    node()
    {
        data = 0;
        left = right = NULL;
    }
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
    friend class OBST;
};

class OBST
{
    public:
    node * root;
    int r[100][100];
    int c[100][100];
    int w[100][100];
    OBST()
    {
        root = NULL;
    }

    int sumOfFreq(int p[], int q[], int low, int high)
    {
        int sum = 0;
        for(int i = low; i <= high; i++)
        {
            sum += p[i] + q[i];
        }
        return sum;
    }

    void calc_wt(int p[], int q[], int low, int high)
    {
        //update weight matrix
        w[low][high] =  sumOfFreq(p, q,low, high);   
    }

    void findOptimalTree(int p[], int q[], int numnodes, int n)
    {
        for (int i = 0; i < n - numnodes; i++)
        {
            int j = numnodes + i;
            int minCost = 9999;
            int minRoot = r[i][j-1];
            for(int k=i+1;k<=j;k++){
                int cost = c[i][k-1] + c[k][j];
                if(cost < minCost){
                    minCost = cost;
                    minRoot = k;
                }
            }
            c[i][j] = minCost + sumOfFreq(p, q,i,j);
            r[i][j] = minRoot;
        }
    }

    void findOBST(int *values,int p[], int q[],int totalNodes){
        int n = totalNodes + 1;

        for(int i=0;i<n;i++){  // init whole of c and r to 0
        // i = j  pe cost is 0
            for(int j=0;j<n;j++){
                c[i][j] = 0;
                r[i][j] = 0;
            }
        }

        for(int i=0;i<n;i++){   // i - j = 1 wali case
            int j = i + 1;
            c[i][j] = sumOfFreq(p,q,i,j);
            r[i][j] = j;
        }

        for(int i=2;i<n;i++){
            findOptimalTree(p,q , i , n);
        }

        cout<<"Cost of OBST is "<<c[0][n-1]<<endl;

        this -> root = new node();
        this -> root = constructOBST(0 , n-1 , values);
    }    
    node *constructOBST(int i,int j,int *values){
        if(i == j){
            return nullptr;
        }
        else{
            node *nod = new node();
            nod -> data = values[r[i][j] - 1];
            nod -> left = constructOBST(i , r[i][j] - 1 , values);
            nod -> right = constructOBST(r[i][j] , j , values);
            return nod;
        }
    }
    void inorder(node * root)
    {
        if(root != NULL)
        {
            inorder(root -> left);
            cout<<root -> data<<" ";
            inorder(root -> right);
        }
    }
    void show(int n) 
    {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
        cout <<"("<< this->w[i][j] << "  " << this->c[i][j] << "  " << this->r[i][j] << " ) ";
        }

        cout << endl;
        }
    }

    void preorder(node * root)
    {
        if(root != NULL)
        {
            cout<<root -> data<<" ";
            preorder(root -> left);
            preorder(root -> right);
        }
    }
};

int main()
{
    OBST t;
    int nodes;
    cout<<"Enter no of nodes: ";
    cin>>nodes;
    int values[nodes];
    int p[nodes];
    int q[nodes + 1];
    // cout<<"Enter probability of first unsuccesful search: ";
    // cin>>q[0];
    // }
    // for(int i=1;i< = nodes;i++){
    //     cout<<"Enter value and probabilty: ";
    //     cin>>values[i]>>p[i]>>q[i];
    // }
    cout<<"Enter Values :";
    for(int i=0;i<nodes;i++){
        cin>>values[i];
    }
    cout<<"Enter Success probability ";
    for(int i=0;i<nodes;i++){
        cin>>p[i];
    }
    cout<<"Enter Unsuccess probability ";
    for(int i=0;i<nodes + 1;i++){
        cin>>q[i];
    }
    cout<<endl;
    t.findOBST(values ,p,q , nodes);
    t.inorder(t.root);
    cout<<endl;
    t.show(nodes);
    
    cout<<endl;
    t.preorder(t.root);
    cout<<endl;

    return 0;
}
