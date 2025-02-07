//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs(int V, vector<int> adj[], vector<bool>& visited, int src){
        visited[src] = true;
        for(auto it:adj[src]){
            if(!visited[it]){
                dfs(V,adj,visited,it);
            }
        }
    }
    
    int noOfComponents(int V, vector<int> adj[]){
        vector<bool> visited(V, false);
        int count = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                count++;
                dfs(V,adj,visited,i);
            }
        }
        return count;
    }
    
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int pre = noOfComponents(V, adj);
        auto ne = remove((adj[c]).begin(), adj[c].end(), d);
        adj[c].erase(ne, adj[c].end());
        ne = remove((adj[d]).begin(), adj[d].end(), c);
        adj[d].erase(ne, adj[d].end());
        return !(pre == noOfComponents(V,adj));
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends