// Write menu driven C++ program to 
// 1. Represent a given graph using adjacency list/Adjacency Matrix. Use the map of 
// the area around the college as the graph
// 2. Display Graph
// 3. Perform BFS traversal/DFS
// 4. Calculate degree of each node.
// Note: Write your own Queue class 

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class graph
{
public:         
    int v;
    int **mat;
    int *visited1 = new int[v];
    graph(int vertices)
    {
        v = vertices+1;
        mat = new int*[v];
        for (int i = 0; i < v; i++)
        {
            mat[i]=new int[v];
        }
        
        for (int x = 0; x < v; x++)
        {
            for (int y = 0; y < v; y++)
            {
                mat[x][y]=0;
            }   
        }
        
        for (int i = 0; i < v; i++)
        {
            visited1[i]=0;
        }  
    }

    void add_edge(int u ,int v)
    {
        mat[u][v]=1;
        mat[v][u]=1;
    }

    void display()
    {
        cout<<0<<"  ";
        for (int i = 1; i < v; i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<endl;

        for (int x = 1; x < v; x++)
        {
           cout<<x<<"  ";
           for (int y = 1; y < v; y++)
           {
                cout<<mat[x][y]<<" ";
           }
           cout<<endl;
        }
    }

    void bfs(int b)
    {
        int *visited = new int[v];
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            visited[i]=0;
        }
        cout<<b<<" ";
        visited[b]=1;
        q.push(b);
        while (!q.empty())
        {
            int c=q.back();
            q.pop();
            for (int x = 0; x < v; x++)
            {
                if (mat[c][x]==1 && visited[x]==0)
                {
                    cout<<x<<" ";
                    visited[x]=1;
                    q.push(x);
                }   
            }   
        }        
    }

    void dfs(int d)
    {///WRONG.....!!!!!!!!!  ---->>>>>correcteddddddddd
        int *visited = new int[v];
        stack<int> s;
        for (int i = 0; i < v; i++)
        {
            visited[i]=0;
        }   
        s.push(d);
        while (!s.empty())
        {
            int x= s.top();
            s.pop();
            if (visited[x]==0)// not added
            {
                cout<<x<<" ";
                visited[x] =1;
                for (int i = 0; i < v; i++)
                {
                    if (mat[x][i]==1 && visited[i]==0)
                    {
                         s.push(i);
                    }   
                }
            }
        }
    }

    void DFS(int i)
   {
        int * visited = new int[v];
        for (int j=0 ;j < v; j++)
        {
            visited[j]=0;
        }
        stack<int> s;
        s.push(i);

        while (!s.empty())
        {
            int u = s.top();
            s.pop();

            if (visited[u]== 0)
            {
                cout<<u<<" ";
                visited[u]=1;

                for (int i = 0; i < v;  i++)
                {
                    if (mat[u][i] == 1 && visited[i] ==0)
                    {
                        s.push(i);
                    }
                    
                }
                
            }
            
        }
   }

    void dfs_rec(int r)
    { 
        if (visited1[r]==0)
        {
            
            cout<<r<<" ";
            visited1[r]=1;
            for (int i = 1; i < v; i++)
            {
               if (mat[r][i]==0 && visited1[i]==0)
               {
                    dfs_rec(i);
               }
               
            }
            
        }
        
    }
   
};

int main()
{
    graph g(5);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,5);
    g.add_edge(3,4);
    g.add_edge(4,5);

    g.display();
    cout<<endl;
    g.bfs(1);
    cout<<endl;
   // g.dfs_rec(1);
   g.dfs(1);

    return 0;
}