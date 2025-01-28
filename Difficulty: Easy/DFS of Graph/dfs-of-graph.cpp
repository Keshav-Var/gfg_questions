//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<vector<int>>& gp, vector<int>& traversal, vector<bool>& visited, int source){
        for(auto adj:gp[source]){
            if(!visited[adj]){
                visited[adj] = true;
                traversal.push_back(adj);
                dfs(gp, traversal, visited, adj);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> traversal;
        vector<bool> visited(n, false);
        traversal.push_back(0);
        visited[0] = true;
        dfs(adj, traversal, visited, 0);
        return traversal;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends