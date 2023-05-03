
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

        void DFS_Graph(int start);
        void DFS_Traversal(int start,int visited[],vector<int> &ls);

};


void Graph :: DFS_Traversal(int start,int visited[],vector<int> &ls){
    visited[start] = 1;
    ls.push_back(start);

    for(auto it : adj[start]){
        if(!visited[it]){
            DFS_Traversal(it,visited,ls);
        }
    }
}

void Graph :: DFS_Graph(int start){
    int visited[v] = {0};
    vector<int> ls;
    DFS_Traversal(start,visited,ls);

    for(auto x : ls){
        cout<<x<<" ";
    }
}


int main(){
    int start =0;
    Graph Gp(8);
    Gp.addEdge(0,1);
    Gp.addEdge(0,2);
    Gp.addEdge(2,3);
    Gp.addEdge(3,4);
    Gp.addEdge(4,5);
    Gp.addEdge(5,2);
    Gp.addEdge(1,6);
    Gp.addEdge(1,7);
    Gp.DFS_Graph(start);
    return 0;
}