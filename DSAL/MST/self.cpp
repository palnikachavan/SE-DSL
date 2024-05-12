#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
    int loc;
    // Node * next;
    public:
    Node() : loc(0){};//, next(NULL){};
    Node(int l) : loc(l){};//, next(NULL){};
    friend class Graph;
};

class Edge
{
    Node *n1, *n2;
    int cost;

    public:
    friend class Graph;
    Edge() : n1(), n2(), cost(0) {};
    Edge(Node* x, Node* y, int c){
        n1=x;
        n2=y;
        cost=c;
    }
};

class Graph
{
    public:
    vector<Node*> nodes;
    vector<Edge*> edges;
    Graph(){};


    void addNode(int x)
    {
        Node *n = new Node(x);
        nodes.push_back(n);
    }

    void addEdge(int x, int y, int c)
    {
        Node *n1 = nodes[x];
        Node *n2 = nodes[y];
        Edge *e = new Edge(n1,n2,c);
        edges.push_back(e);
    }

    Edge * minEdge(Node *node, vector<Node *> visited)
    {
        Edge *minEdge = nullptr;
        int minCost = 10000000;
        for(Edge* ed : edges) // enhanced for loop
        {
            if((ed->n1 == node || ed->n2 == node) && ed->cost < minCost)
            {
                if(ed->n1 == node && find(visited.begin(), visited.end(), ed->n2) == visited.end())
                {
                    minEdge = ed;
                    minCost = ed->cost;
                }
                if(ed->n2 == node && find(visited.begin(), visited.end(), ed->n1) == visited.end())
                {
                    minEdge = ed;
                    minCost = ed->cost;
                }
            }
        }
        return minEdge;
    }

    int search_node(int node)
    {
        int ind = 0;
        for(ind; ind<nodes.size(); ind++)
        {
            if(nodes[ind]->loc == node)
            {
                break;
            }
        }
        cout<<"Starting from "<<nodes[ind]->loc<<endl;
        return ind;
    }



    void mst(int start)
    {
        vector <Node*> visited;
        int cost = 0;
        Node *startNode = nodes[search_node(start)];
        visited.push_back(startNode);
        Edge *minedge = nullptr;
        Node *minNode = nullptr;
        while(visited.size() < nodes.size())
        {
            int minCost = 10000000;
            for (Node * node : nodes)
            {
                Edge * edge = minEdge(node, visited);
                if(edge && edge->cost < minCost)
                {
                    minedge = edge;
                    minNode = (edge->n1 == node) ? edge->n2: edge->n1;
                    minCost = edge->cost;
                }
            }
            if(minedge)
            {
                visited.push_back(minNode);
                cout<<"Source :"<<minedge->n1->loc<<" to Destination :"<<minedge->n2->loc<<" Cost :"<<minedge->cost<<endl;
                cost += minedge->cost;
            }
            else
                break;

        }
        cout<<"Total Cost :"<<cost<<endl;
    }
};

int main()
{
    Graph G;
    for (int i = 0; i < 5; ++i) {
        // cout<<"Enter source :";
        // cin>>src;
        G.addNode(i);
    }
    G.addEdge(0, 1, 20);
    G.addEdge(2, 3, 100);
    G.addEdge(0, 3, 10);
    G.addEdge(3, 4, 10);
    G.addEdge(1, 2, 30);
    G.addEdge(1, 4, 50);
    cout<<"Nodes are :"<<endl;
    // for (int i = 0; i < G.nodes.size(); ++i) {
    //     cout<<G.nodes[i]->loc<<" ";
    // }
    // int vert;
    cout<<endl;
    // cout<<"Enter vertex of start ";
    // cin>>vert;
    cout << "Minimum Spanning Tree:" << endl;
    G.mst(3);
    return 0;
}