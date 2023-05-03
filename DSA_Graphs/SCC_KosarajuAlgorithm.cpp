//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	private:
    void dfs(int node,vector<int>& visited,vector<vector<int>>& adj,stack<int>& st){
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it])
                dfs(it,visited,adj,st);
        }
        st.push(node);
    }
    
    private:
    void newdfs(int node,vector<int>& visited,vector<int> adj2[]){
        visited[node] = 1;
        for(auto it: adj2[node]){
            if(!visited[it])
                newdfs(it,visited,adj2);
        }
    }
    
        
    public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V,0);
        stack <int> st;
        
        for(int i=0;i<V;i++){
            if(!visited[i])
                dfs(i,visited,adj,st);
        }    
        
         vector<int> adj2[V];
        for(int i=0; i<V ; i++){
            visited[i]=0;
            for (int j=0; j<adj[i].size(); j++){
                adj2[adj[i][j]].push_back(i);
            }
        }
        
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                scc++;
                newdfs(node,visited,adj2);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends


// test case

// 5 5
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4