//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisJointSet{
    vector<int> parent,size;
    public:
    DisJointSet(int n){
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


class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                edges.push_back({wt,{i,adjNode}});
            }
        }
        
        DisJointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstWt = 0;
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};

//{ Driver Code Starts.


int main()
{
    
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";

    return 0;
}


//  Driver Code Ends


//test case

// 3 3
// 0 1 5
// 1 2 3
// 0 2 1