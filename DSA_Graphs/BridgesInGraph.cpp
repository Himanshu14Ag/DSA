//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 1;
public:
    
    void dfs(int node,int parent,vector<int>& visited,vector<int> adj[],
            int tim[],int low[],vector<vector<int>>& bridges){
            
        visited[node] = 1;
        tim[node] = low[node] = timer;
        timer++;
        
        for(auto it: adj[node]){
            if(it==parent)
                continue;
            
            if(visited[it]==0){
                dfs(it,node,visited,adj,tim,low,bridges);
                low[node] = min(low[node],low[it]);
                
                if(low[it]>tim[node]){
                    bridges.push_back({node,it});
                }
            }
            else
                low[node] = min(low[node],low[it]);   
        }
    }
    
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    vector<int> visited(V,0);
	    int tim[V];
	    int low[V];
	    
	    vector<vector<int>> bridges;
	    dfs(0,-1,visited,adj,tim,low,bridges);
	    return bridges;
	    
	}
};

//{ Driver Code Starts.

int main(){

        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;

	return 0;
}
// } Driver Code Ends
