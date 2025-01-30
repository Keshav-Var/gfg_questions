//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCycle(vector<vector<int>>& adj, int s, vector<bool>& visited, vector<bool>& temp){
        visited[s] = true;
        temp[s] = true;
        for(auto u:adj[s]){
            if(visited[u] == false && checkCycle(adj, u, visited, temp))
            return true;
            else if(temp[u])
            return true;
        }
        temp[s] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V, false);
        vector<bool> temp(V, false);
        for(int  i = 0; i < adj.size(); i++){
            if(checkCycle(adj, i, visited, temp))
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends