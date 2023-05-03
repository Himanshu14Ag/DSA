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

        bool DetectCycle(int start,vector<int> &visited);
        bool isCyclePresent();
};



bool Graph:: DetectCycle(int start,vector<int> &visited){
    visited[start] = 1;
    queue<pair<int,int>> q;
    q.push({start,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
    
        for(auto an : adj[node]){
            if(!visited[an]){
                visited[an] = 1;
                q.push({an,node});
            }
            else if(parent!=an){
                return true;
            }
        }
    }
    return false;
}




bool Graph :: isCyclePresent(){
    vector<int> visited(v,false);

    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(DetectCycle(i,visited))
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