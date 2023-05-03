
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

    vector<int> TopoSort();
    void DFS(int node,vector<int> &visited,stack<int> &st);
};


void Graph :: DFS(int node,vector<int> &visited,stack<int> &st){
    visited[node] = 1;

    for(auto it : adj[node]){
        if(!visited[it]){
            DFS(it,visited,st);
        }
    }
    st.push(node);
}


vector<int> Graph :: TopoSort(){
    vector<int> visited(vertex,0);
    stack<int> st;
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            DFS(i,visited,st);
        }
    }

    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}



int main(){
    Graph G(6);
    G.AddEdge(5,0);
    G.AddEdge(5,2);
    G.AddEdge(2,3);
    G.AddEdge(3,1);
    G.AddEdge(4,0);
    G.AddEdge(4,1);

    vector<int> ans; 
    ans = G.TopoSort();
    cout<<"Topological Sort :-   ";
    for(int x : ans)
        cout<<x<<" ";
}