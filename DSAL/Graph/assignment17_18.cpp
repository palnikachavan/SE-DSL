// Write menu driven C++ program to
// 1) Represent a given graph using adjacency list/Adjacency Matrix. Use the map of the
// area around the college as the graph
// 2) Display Graph
// 3) Perform DFS traversal using recursive/non-recursive algorithm.
// 4) Perform BFS traversal.
// 5) Calculate degree of each node.

// 1. create + insert       done
// 2. display               done
// 3. DFS
// 4. BFS
// 5. degree of nodes

#include <iostream>
// #define Max = 15;
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class vertex
{
    int data;
    vertex * next;
    public:
    vertex()
    {
        data = 0;
        next = NULL;
        // down = NULL;
    }
    vertex(int x)
    {
        data = x;
        next = NULL;
        // down = NULL;
    }
    friend class graph;
};

class graph
{
    vertex arr[15];
    int cnt;

    public:
    graph()
    {
        cnt = 0;
    }

    void insert(int source, int dest)
    {
        vertex *newnode =new vertex(dest);
        int ind = search(source);
        if(ind == -1)
        {
            
            arr[cnt].data = source;
            arr[cnt].next = newnode;
            cnt++;
            cout<<"Data inserted"<<endl;
            return;
        }
        vertex * temp = arr[ind].next;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        cout<<"Data in chain"<<endl;

    }

    int search(int x)
    {
        int i = 0;
        while(i < cnt)
        {
            if(arr[i].data == x)
            {
                return i;
            }
            i++;
        }
        return -1;
    }

    // void DFS(int node)
    // {
    //     stack <int> s;
    //     vector <int> visited;
    //     s.push(node);
    //     visited.push_back(node);
    //     while(1)
    //     {
    //         if(!s.empty())
    //         {
    //             node = s.top();
    //             s.pop();
    //             cout<<node<<" ";
    //             vertex *temp = arr[search(node)].next;
    //         }
    //         else
    //         {
    //             cout<<endl;
    //             break;
    //         }
    //         vertex *currentNode = &arr[0];
    //         bool found = false;
    //         while ( currentNode != nullptr ) {
    //         if( currentNode->data == node ) {
    //             found = true;
    //             vertex *currentListNode = currentNode->next;
    //             while( currentListNode != nullptr ) {
    //                 if( find( visited.begin(), visited.end(), currentListNode->data ) == visited.end() ) {
    //                     s.push( currentListNode->data );
    //                     visited.push_back( currentListNode->data );
    //                 }
    //                 currentListNode = currentListNode->next;
    //             }
    //             break;
    //         }
    //         currentNode = currentNode->down;
    //         }
    //         if( !found ) {
    //             cout<< "Given node doesn't exist in the graph" <<endl;
    //             return;
    //         }
    //     }
    // }

    void dfs()
    {
        vector<int> visited;
        stack<int> s;
        
    }

    void display()
    {
        for(int i = 0; i < cnt; i++)
        {
            vertex *temp = &arr[i];
            cout<<arr[i].data<<"-->";
            while(temp->next != NULL)
            {
                temp = temp->next;
                cout<<temp->data<<"-->";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graph g;
    
    g.insert(10,20);
    g.insert(20,10);
    g.insert(10,30);
    g.display();
    // g.DFS(10);
    return 0;
}