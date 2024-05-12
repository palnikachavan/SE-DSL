#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class graph
{        
    int v;
    int **mat;
    int *inDeg;
    int *outDeg;
public:
    graph(int vertices)
    {
        v = vertices + 1;
        mat = new int*[v];
        inDeg = new int[v];
        outDeg = new int[v];
        for (int i = 0; i < v; i++)
        {
            inDeg[i] = 0;
            outDeg[i] = 0;
            mat[i] = new int[v];
        }
        
        for (int x = 0; x < v; x++)
        {
            for (int y = 0; y < v; y++)
            {
                mat[x][y] = 0;
            }   
        }
    }

    void add_edge(int u, int v)
    {
        mat[u][v] = 1;
        mat[v][u] = 1;
        inDeg[u]++;
        outDeg[u]++;
        inDeg[v]++;
        outDeg[v]++;
    }

    void display()
    {
        cout << 0 << "  ";
        for (int i = 1; i < v; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << endl;

        for (int x = 1; x < v; x++)
        {
            cout << x << "  ";
            for (int y = 1; y < v; y++)
            {
                cout << mat[x][y] << " ";
            }
            cout << endl;
        }
    }

    void display_deg()
    {
        cout << "Out Degree:" << endl;
        for (int i = 1; i < v; i++)
        {
            cout << "Node " << i << ": " << outDeg[i] << endl;
        }

        cout << "\nIn Degree:" << endl;
        for (int i = 1; i < v; i++)
        {
            cout << "Node " << i << ": " << inDeg[i] << endl;
        }
    }

    void bfs(int b)
    {
        int *visited = new int[v];
        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            visited[i] = 0;
        }
        cout << b << " ";
        visited[b] = 1;
        q.push(b);
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            for (int x = 0; x < v; x++)
            {
                if (mat[c][x] == 1 && visited[x] == 0)
                {
                    cout << x << " ";
                    visited[x] = 1;
                    q.push(x);
                }   
            }   
        }        
    }

    void dfs(int d)
    {
        int *visited = new int[v];
        stack<int> s;
        for (int i = 0; i < v; i++)
        {
            visited[i] = 0;
        }   
        s.push(d);
        while (!s.empty())
        {
            int x = s.top();
            s.pop();
            if (visited[x] == 0)
            {
                cout << x << " ";
                visited[x] = 1;
                for (int i = v - 1; i >= 0; i--)
                {
                    if (mat[x][i] == 1 && visited[i] == 0)
                    {
                        s.push(i);
                    }   
                }
            }
        }
    }
};

int main()
{
    graph g(5);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 5);
    g.add_edge(3, 4);
    g.add_edge(4, 5);

    g.display();
    cout << endl;
    g.bfs(1);
    cout << endl;
    g.dfs(1);

    cout<<endl;
    g.display_deg();

    return 0;
}
