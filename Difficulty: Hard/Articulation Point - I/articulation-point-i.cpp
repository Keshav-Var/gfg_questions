//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 0;
    void solve(int V, vector<int>adj[], vector<int>& low,
    vector<int>& dtime, vector<bool>& visited, int parent, int src, vector<bool>& mark){
        visited[src] = true;
        dtime[src] = timer;
        low[src] = timer;
        timer++;
        int child = 0;
        for(auto it:adj[src]){
            if(it == src) continue;
            if(!visited[it]){
                child++;
                solve(V, adj, low, dtime, visited, src, it, mark);
                low[src] = min(low[src], low[it]);
                if(dtime[src] <= low[it] && parent != -1){
                    mark[src] = true;
                }
            }
            else{
                low[src] = min(low[src], dtime[it]);
            }
            if(child > 1 && parent == -1)
            mark[src] = true;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> low(V, -1);
        vector<int> dtime(V, -1);
        vector<bool> visited(V, false);
        vector<int> apoints;
        vector<bool> mark(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                solve(V, adj, low, dtime, visited, -1, i, mark);
            }
        }
        for(int i = 0; i < V; i++){
            if(mark[i])
            apoints.push_back(i);
        }
        if(apoints.empty())
        return {-1};
        return apoints;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
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
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends