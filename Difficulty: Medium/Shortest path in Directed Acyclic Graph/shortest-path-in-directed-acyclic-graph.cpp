//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    void topoSort(vector<vector<pair<int, int>>>& gp, int src, vector<bool>& visited, stack<int> &st){
        visited[src] = true;
        for(auto u:gp[src]){
            if(!visited[u.first])
            topoSort(gp, u.first, visited, st);
        }
        st.push(src);
    }
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> gp(V);
        vector<bool> visited(V, false);
        stack<int> st;
        for(auto edge:edges){
            gp[edge[0]].push_back({edge[1], edge[2]});
        }
        
        topoSort(gp, 0, visited, st);
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while(!st.empty()){
            int u = st.top();
            st.pop();
            for(auto v:gp[u]){
                if(dist[v.first] > dist[u] + v.second)
                dist[v.first] = dist[u] + v.second;
            }
        }
        
        for(int i = 0; i < V; i++){
            if(dist[i] == INT_MAX)
            dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends