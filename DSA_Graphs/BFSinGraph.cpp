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

        void BFS_Traversal(int start);
};

void Graph :: BFS_Traversal(int start){
    int visited[v+1] = {0};
    queue<int>q;
    visited[start] = 1;
    q.push(start);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout<<u<<" ";

        for(auto it : adj[u]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}

int main(){
    int start =0;
    Graph Gp(5);
    Gp.addEdge(0,1);
    Gp.addEdge(0,2);
    Gp.addEdge(1,2);
    Gp.addEdge(1,3);
    Gp.addEdge(2,3);
    Gp.addEdge(2,4);
    Gp.addEdge(3,4);
    Gp.BFS_Traversal(start);
    return 0;
}