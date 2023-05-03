
#include<bits/stdc++.h>
using namespace std;


class Graph{
    int vertex;
    vector<int> *adj;

    public:
    Graph(int vertex){
        this->vertex = vertex;
        this->adj = new vector<int> [vertex];
    }
    void AddEdge(int u,int v){
        adj[u].push_back(v);
    }

    bool DetectCycle();
    bool DFS(int node,vector<int> &visited);
};


bool Graph :: DFS(int node,vector<int> &visited){
    visited[node] = 2;

    for(auto it : adj[node]){
        if(!visited[it]){
            if(DFS(it,visited)==true)
                return true;
        }
        else if(visited[it]==2)
            return true;
    }
    visited[node] = 0;
    return false;
}


bool Graph :: DetectCycle(){
    vector<int> visited(vertex,0);

    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            if(DFS(i,visited))
                return true;
        }
    }
    return false;
}



int main(){
    Graph G(10);
    G.AddEdge(0,1);
    G.AddEdge(1,2);
    G.AddEdge(2,3);
    G.AddEdge(3,4);
    G.AddEdge(4,5);
    G.AddEdge(2,6);
    G.AddEdge(6,4);
    G.AddEdge(7,2);
    G.AddEdge(7,8);
    G.AddEdge(8,9);
    G.AddEdge(9,7);

    if(G.DetectCycle())
        cout<<"Graph has cycle";

    else    
        cout<<"Graph has no cycle";
}