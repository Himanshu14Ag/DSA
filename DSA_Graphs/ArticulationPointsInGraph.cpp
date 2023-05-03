//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 1;
  public:
  
    void dfs(int node,int parent,vector<int>& visited,
            int tim[],int low[],vector<int>& mark,vector<int> adj[]){
            
        visited[node] = 1;
        tim[node] = low[node] = timer;
        timer++;
        int child=0;
        
        for(auto it: adj[node]){
            if(it==parent)
                continue;
            
            if(visited[it]==0){
                dfs(it,node,visited,tim,low,mark,adj);
                low[node] = min(low[node],low[it]);
                
                if(low[it]>=tim[node]&&parent!=-1){
                    mark[node] = 1;
                }
                child++;
            }
            else
                low[node] = min(low[node],tim[it]);   
        }
        if(child>1&&parent==-1)
            mark[node] = 1;
    }
  
  
  
  
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> visited(V,0);
        int tim[V];
	    int low[V];
	    vector<int> mark(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	            dfs(i,-1,visited,tim,low,mark,adj);
	    }
	    vector<int> ans;
	    for(int i=0;i<V;i++){
	        if(mark[i]==1)
	            ans.push_back(i);
	    }
	    if(ans.size()==0)
	        return {-1};
	   
	    return ans;
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
		vector<int> ans = obj.articulationPoints(V, adj);
        cout<<"\n\nArticulation Points : ";
		for(auto i: ans)cout << i << " ";
		cout << "\n";

	return 0;
}
// } Driver Code Ends
//Input -
// 8 10
// 0 1
// 1 2
// 2 3
// 3 4
// 4 5
// 1 5
// 5 3
// 2 6
// 6 7
// 7 2