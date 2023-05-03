
#include<bits/stdc++.h>
using namespace std;


class Graph{
    int vertex;
    vector<pair<int,int>> *adj;

    public:
    Graph(int vertex){
        this->vertex = vertex;
        this->adj = new vector<pair<int,int>> [vertex];
    }
    void AddEdge(int u,int v,int wt){
        adj[u].push_back(make_pair(v,wt));
    }

    void TopoSort(int node, vector<int> &visited, stack<int> &st);
    vector<int> ShortestPath(int M);
};


void Graph :: TopoSort(int node, vector<int> &visited, stack<int> &st){
    visited[node] = 1;

    for(auto it : adj[node]){
        int v = it.first;
        if(!visited[v]){
            TopoSort(v,visited,st);
        }
    }
    st.push(node);
}


vector<int> Graph :: ShortestPath(int M){
    stack<int> st;
    vector<int> visited(vertex,0);
    for(int i=0;i<vertex;i++){
        if(!visited[i])
            TopoSort(i,visited,st);
    }

    vector<int> dist(vertex);
    for(int i=0;i<vertex;i++){
        dist[i] = INT_MAX;
    }

    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();

        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node]+wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
        }
    }
    return dist;
}


int main(){
    Graph G(6);
    G.AddEdge(0,1,2);
    G.AddEdge(0,4,1);
    G.AddEdge(4,5,4);
    G.AddEdge(4,2,2);
    G.AddEdge(1,2,3);
    G.AddEdge(2,3,6);
    G.AddEdge(5,3,2);
    int edges = 7;

    vector<int> ans; 
    ans = G.ShortestPath(edges);
    cout<<"Distance :-   ";
    for(int x : ans)
        cout<<x<<" ";
}