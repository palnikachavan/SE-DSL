#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

template <class T>
class Node{
    T data;
    Node* next;
public:
    Node(){
        data=0;
        next=NULL;
    }
    Node(T data){
        this->data=data;
        next=NULL;
    }
    class Graph{
        map<T,Node*> adjList;
        unordered_map<T,bool> visited;
        public:

        void ins(Node* &head,T data){
            if(!head){
                head = new Node(data);
            }
            else{
                Node* nptr=head;
                while(nptr->next){
                    nptr=nptr->next;
                }
                nptr->next = new Node(data);
            }
        }

        void createAdjList(T u,T v,bool flag){
            ins(adjList[u],v);
            //flag->0 = undirected graph and flag->1 = directed graph
            if(!flag){
                ins(adjList[v],u);
            }
        }

        void bfs(map<T,Node*> adjList,unordered_map<T,bool> &visited,T node){
            queue<T> q;
    
            q.push(node);
            visited[node]=1;
            
            
            while(!q.empty()){
                T frontNode = q.front();
                q.pop();
                cout<<frontNode<<" ";
                Node<T>* current = adjList[frontNode];
                while (current) {
                    if (!visited[current->data]) {
                        q.push(current->data);
                        visited[current->data] = 1;
                    }
                    current = current->next;
                }
            }
            
        }

        void dfs(map<T,Node*> adjList,unordered_map<T,bool> &visited,T node){
            stack<T> s;
            s.push(node);
            visited[node]=1;
            while(!s.empty()){
                T topNode=s.top();
                s.pop();
                cout<<topNode<<" ";
                Node<T>* current = adjList[topNode];
                while (current) {
                    if (!visited[current->data]) {
                        s.push(current->data);
                        visited[current->data] = 1;
                    }
                    current = current->next;
                }
            }
        }

        void printAdjList(){
            for(auto i:adjList){
                Node<T>* current = adjList[i.first];
                cout<<i.first<<"->";
                while(current){
                    cout<<current->data<<",";
                    current=current->next;
                }
                cout<<endl;
            }
        }

        void travese(){
            for(auto i:adjList){
                if(!visited[i.first]){
                    bfs(adjList,visited,i.first);
                }
            }
            cout<<endl;
        } 

        void travese1(){
            unordered_map<T,bool> visited1;
            for(auto i:adjList){
                if(!visited1[i.first]){
                    dfs(adjList,visited1,i.first);
                }
            }
            cout<<endl;
        } 


    };
};

int main(){
    int n;
    cout<<"Enter number of edges of graph :- ";
    cin>>n;
    Node<string>::Graph g;
    bool flag;
    cout<<"Enter 1 for creating directed graph else enter 0 :- ";
    cin>>flag;
    for(int i=0;i<n;i++){
        string u;
        string v;
        cout<<"Enter source :- ";cin>>u;
        cout<<"Enter destination :- ";cin>>v;
        g.createAdjList(u,v,flag);
    }
    g.printAdjList();
    g.travese();
    g.travese1();
}