// You have a business with several offices; you want to lease phone lines to connect them
// up with each other; and the phone company charges different amounts of money to
// connect different pairs of cities. You want a set of lines that connects all your offices with
// a minimum total cost. Solve the problem by using weighted graph and applying minimum
// spanning tree algorithm.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    int loc;
    Node() : loc(0), next(NULL) {}
    Node(int x) : loc(x), next(NULL) {}
    Node* next;
};

class Edge {
public:
    int cost;
    Node* n1;
    Node* n2;
    Edge()
    {

        cost=0;
        n1=NULL;
        n2=NULL;
    }
    Edge(Node* x, Node* y, int c){
        n1=x;
        n2=y;
        cost=c;
    }


};


class Graph {
public:
    vector<Edge*> edges;
    vector<Node*> nodes;

    void addNode(int loc) {
        Node* node = new Node(loc);
        nodes.push_back(node);
    }


    void addEdge(int m, int n, int c) {
        Node* x = nodes[m];
        Node* y = nodes[n];
        Edge* edge = new Edge(x, y, c);
        edges.push_back(edge);
    }

    // int getEdgeCost(int m, int n) {
    //     for (Edge* edge : edges) {
    //         if ((edge->n1->loc == m && edge->n2->loc == n) ||
    //             (edge->n1->loc == n && edge->n2->loc == m)) {
    //             return edge->cost;
    //         }
    //     }
    //     return 1000000;s
    // }

    void mst() {

        //prim's algorithm
        vector<Node*> visited;
        if (!nodes.empty()) {
            Node* startNode = nodes[0]; //point to starting node
            visited.push_back(startNode);
            Edge* minEdge = nullptr;
            Node* minNode = nullptr;
            while (visited.size() < nodes.size()) {   //till all nodes are not visited
                int minCost = 1000000;
                for (Node* node : visited) {
                    Edge* edge = findMinEdge(node,visited);
                    if (edge && edge->cost < minCost) {
                        minCost = edge->cost;
                        minEdge = edge;
                        minNode = (edge->n1 == node) ? edge->n2 : edge->n1;
                    }
                }
                if (minEdge) {
                    visited.push_back(minNode);
                    cout << "Edge from " << minEdge->n1->loc << " to " << minEdge->n2->loc
                        << " with cost = " << minEdge->cost << endl;
                } else {
                    break;
                }
            }
        }
    }


    Edge* findMinEdge(Node* node,vector<Node*> visited) {
        Edge* minEdge = nullptr;
        int minCost = 1000000;
        for (Edge* edge : edges) {
            if ((edge->n1 == node || edge->n2 == node) && edge->cost < minCost)  // check for min cost and edge
            {
                if (edge->n1 == node && find(visited.begin(), visited.end(), edge->n2) == visited.end()) // check if n2 is visited or not
                {
                    minCost = edge->cost;
                    minEdge = edge;
                } else if (edge->n2 == node && find(visited.begin(), visited.end(), edge->n1) == visited.end()) {
                    minCost = edge->cost;
                    minEdge = edge;
                }
            }
        }
        return minEdge;
    }
};

int main() {
    Graph G;
    // int n, src, dest;
    // cout<<"Enter number of vertices :";
    // cin>>n;
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
    G.mst();
    return 0;

}

