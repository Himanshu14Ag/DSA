
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int vertex;
    vector<int> *adj;

    public:
    Graph(int vertex){
        this->vertex = vertex;
        this->adj = new vector<int> [vertex];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }

    void KahnSort();
};

void Graph::KahnSort()
{
	vector<int> in_degree(vertex, 0);

	for (int u = 0; u < vertex; u++) {
		for (auto it : adj[u])
			in_degree[it]++;
	}

	queue<int> q;
	for (int i = 0; i < vertex; i++)
		if (in_degree[i] == 0)
			q.push(i);

	int count = 0;

	while (!q.empty()) {
	
    	int u = q.front();
		q.pop();
        count++;

    	for (auto it : adj[u]){
            if (--in_degree[it] == 0)
				q.push(it);

        }
	}

	if(count == vertex) 
        cout<<"The Graph is Acyclic";
    
    else
        cout<<"The Graph is Cyclic";
}


int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	g.KahnSort();

	return 0;
}
