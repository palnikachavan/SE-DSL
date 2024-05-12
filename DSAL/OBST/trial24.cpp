#include <iostream>
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
    node *root;
    int **r; // Dynamic arrays for storing optimal root indices
    int **c; // Dynamic arrays for storing optimal costs
    int *w;  // Dynamic array for storing cumulative weights

    OBST()
    {
        root = NULL;
        r = nullptr;
        c = nullptr;
        w = nullptr;
    }

    int sumOfFreq(int p[], int q[], int low, int high)
    {
        int sum = 0;
        for (int i = low; i <= high; i++)
        {
            sum += p[i] + q[i];
        }
        return sum;
    }

    void calc_wt(int p[], int q[], int numnodes)
    {
        w = new int[numnodes + 1];
        w[0] = 0;
        for (int i = 1; i <= numnodes; i++)
        {
            w[i] = sumOfFreq(p, q, i - 1, numnodes - 1) + w[i - 1];
        }
    }

    void findOptimalTree(int p[], int q[], int numnodes)
    {
        r = new int *[numnodes];
        c = new int *[numnodes];
        for (int i = 0; i < numnodes; i++)
        {
            r[i] = new int[numnodes];
            c[i] = new int[numnodes];
            r[i][i] = i + 1;   // at i = j probability is of unsucess
            c[i][i] = q[i];
        }


        //ithun 
        for (int diagonal = 1; diagonal < numnodes; diagonal++)
        {
            for (int i = 0; i < numnodes - diagonal; i++)
            {
                int j = i + diagonal;
                int minCost = 9999999;
                int minRoot = r[i][j - 1];
                for (int k = i + 1; k <= j; k++)
                {
                    int cost = c[i][k - 1] + c[k][j];
                    if (cost < minCost)
                    {
                        minCost = cost;
                        minRoot = k;
                    }
                }
                c[i][j] = minCost + sumOfFreq(p, q, i, j);
                r[i][j] = minRoot;
            }
        }
    }

    node *constructOBST(int i, int j, int values[])
    {
        if (i > j)
        {
            return nullptr;
        }
        int mid = r[i][j] - 1;
        node *nod = new node(values[mid]);
        nod->left = constructOBST(i, mid - 1, values);
        nod->right = constructOBST(mid + 1, j, values);
        return nod;
    }


    //ithe

    void inorder(node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    

    void show(int numnodes)
    {
        for (int i = 0; i < numnodes; i++)
        {
            for (int j = 0; j < numnodes; j++)
            {
                cout << "(" << w[j + 1] - w[i] << "  " << c[i][j] << "  " << r[i][j] << " ) ";
            }
            cout << endl;
        }
    }

    void buildOBST(int values[], int p[], int q[], int numnodes)
    {
        calc_wt(p, q, numnodes);
        findOptimalTree(p, q, numnodes);

        cout << "Cost of OBST is " << c[0][numnodes - 1] << endl;

        root = constructOBST(0, numnodes - 1, values);
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
    cout << "Enter no of nodes: ";
    cin >> nodes;
    int values[nodes];
    int p[nodes];
    int q[nodes + 1];

    cout << "Enter Values: ";
    for (int i = 0; i < nodes; i++)
    {
        cin >> values[i];
    }
    cout << "Enter Success probability: ";
    for (int i = 0; i < nodes; i++)
    {
        cin >> p[i];
    }
    cout << "Enter Unsuccess probability: ";
    for (int i = 0; i <= nodes; i++)
    {
        cin >> q[i];
    }
    cout << endl;

    t.buildOBST(values, p, q, nodes);

    cout << "Inorder Traversal: ";
    t.inorder(t.root);
    cout << endl;
    t.preorder(t.root);
    cout<<endl;

    cout << "Optimal BST Details: " << endl;
    t.show(nodes);

    return 0;
}
