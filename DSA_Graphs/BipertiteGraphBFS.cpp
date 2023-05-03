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
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    bool isBipertite();
    bool BFS(int start, vector<int> &colour);
};


bool Graph :: BFS(int start, vector<int> &colour){
    queue<int> q;
    q.push(start);
    colour[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : adj[node]){
            if(colour[it]== -1){
                colour[it] = !colour[node];
                q.push(it);
            }
            else if(colour[it]==colour[node])
                return false;
        }
    }
    return true;
}



bool Graph :: isBipertite(){
    vector<int> colour(vertex,-1);

    for(int i=0;i<vertex;i++){
        if(colour[i]==-1){
            if(BFS(i,colour) == false)
                return false;
        }
    }
    return true;
}



int main(){
    Graph G(10);
    G.AddEdge(0,1);
    G.AddEdge(1,2);
    G.AddEdge(2,3);
    G.AddEdge(3,4);
    G.AddEdge(4,5);
    G.AddEdge(5,6);
    G.AddEdge(6,7);
    G.AddEdge(2,8);
    G.AddEdge(8,9);
    G.AddEdge(9,5);

    if(G.isBipertite()==true)
        cout<<"Graph is Bipertite";

    else    
        cout<<"Graph is not Bipertite";
}