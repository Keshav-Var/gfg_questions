//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    static bool comp(vector<int>& v1, vector<int>& v2){
        return v1[2] < v2[2];
    }
    
    void initSet(vector<int> &parent, vector<int> &rank, int n){
        for(int i = 0; i < n; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }
    
    int findParent(int node, vector<int> &parent){
        if(parent[node] == node)
        return node;
        return parent[node] = findParent(parent[node], parent);
    }
    
    void unionByRank(int node1, int node2,vector<int> &parent, vector<int> &rank){
        if(rank[node1] == rank[node2]){
            parent[node2] = node1;
            rank[node1]++;
        }
        else if(rank[node1] < rank[node2])
            parent[node1] = node2;
        else
            parent[node2] = node1;
    }
    
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        int cost = 0;
        vector<vector<int>> edges;
        
        //intializing set
        vector<int> parent(V);
        vector<int> rank(V);
        initSet(parent, rank, V);
        
        //converting into edges
        for(int i = 0; i < V; i++){
            for(auto u:adj[i]){
                edges.push_back({i, u[0], u[1]});
            }
        }
        
        //kruskal's algo
        sort(edges.begin(), edges.end(), comp);
        for(auto e:edges){
            int c1 = findParent(e[0], parent);
            int c2 = findParent(e[1], parent);
            if(c1 != c2){
                unionByRank(c1, c2, parent, rank);
                cost += e[2];
            }
        }
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends