//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
    void dfs(vector<vector<int>> &adj, int src, vector<bool> &visited, stack<int> &st){
        visited[src] = true;
        for(auto u:adj[src]){
            if(!visited[u])
            dfs(adj, u, visited, st);
        }
        st.push(src);
    }
    
    void dfs(vector<vector<int>> &adj, int src, vector<bool> &visited){
        visited[src] = true;
        for(auto u:adj[src]){
            if(!visited[u])
            dfs(adj, u, visited);
        }
        
    }
    
  public:
    int kosaraju(vector<vector<int>> &adj) {
        vector<vector<int>> transpose(adj.size(),vector<int>());
        vector<bool> visited(adj.size(), false);
        stack<int> st;
        for(int i = 0; i < adj.size(); i++){
            if(!visited[i])
            dfs(adj, i, visited, st);
        }
        
        //reverse the adj
        for(int i = 0; i < adj.size(); i++){
            for(auto v:adj[i]){
                transpose[v].push_back(i);
            }
        }
        
        int count = 0;
        fill(visited.begin(), visited.end(), false);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]){
                count++;
                dfs(transpose, node, visited);
            }
        }
        return count;
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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends