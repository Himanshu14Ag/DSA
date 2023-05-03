
#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
    vector<int> rank,parent,size;
    public:
    DisJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }

    }

    int findUPar(int node){
        if(node==parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if(ult_u == ult_v)
            return;

        if(rank[ult_u] < rank[ult_v])
            parent[ult_u] = ult_v;

        else if(rank[ult_u] > rank[ult_v])
            parent[ult_v] = ult_u;

        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }

    }

    void unionBySize(int u, int v){
        int ult_u = findUPar(u);
        int ult_v = findUPar(v);

        if(ult_u == ult_v)
            return;

        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }

        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};



int main(){
    DisJointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);


    // ds.unionBySize(1,2);
    // ds.unionBySize(2,3);
    // ds.unionBySize(4,5);
    // ds.unionBySize(6,7);
    // ds.unionBySize(5,6);              for union by size.................


    cout<<"BEFORE\n";
    if(ds.findUPar(3) == ds.findUPar(7))
        cout<<"Same\n";
    else    
        cout<<"not same\n";

    ds.unionByRank(3,7);

    cout<<"AFTER\n";
    if(ds.findUPar(3) == ds.findUPar(7))
        cout<<"Same\n";
    else    
        cout<<"not same\n";
}