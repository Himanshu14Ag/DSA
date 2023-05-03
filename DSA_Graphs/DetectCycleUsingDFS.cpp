
#include<bits/stdc++.h>
using namespace std;


class Graph{
    int v;
    vector<int> *adj;

    public:
        Graph(int v){
            this->v = v;
            adj = new vector<int> [v];
        }

        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool CycleDFS(int node,int parent,vector<int> &visited);
        bool isCyclePresent();

};


bool Graph :: CycleDFS(int node,int parent,vector<int> &visited){
    visited[node] = 1;

    for(auto an : adj[node]){
        if(!visited[an]){
            if(CycleDFS(an,node,visited)==true)
                return true;
        }
        else if(parent!=an){
            return true;
        }
    }
    return false;
}

bool Graph :: isCyclePresent(){
    vector<int> visited(v,false);

    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(CycleDFS(i,-1,visited)==true)
                return true;
        }
    }
    return false;
}


int main(){
    Graph Gp(5);
    Gp.addEdge(0,1);
    Gp.addEdge(0,2);
    Gp.addEdge(1,2);
    Gp.addEdge(1,3);
    Gp.addEdge(2,3);
    Gp.addEdge(2,4);
    Gp.addEdge(3,4);
    if(Gp.isCyclePresent()){
        cout<<"yes cycle is present";
    }
    else 
        cout<<"No cycle present";

    return 0;
}