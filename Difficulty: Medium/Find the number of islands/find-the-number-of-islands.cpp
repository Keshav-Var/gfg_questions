//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    vector<pair<int,int>> directions = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
    bool isValid(int n, int m, int x, int y){
        if(x < 0 || y < 0 || x >= n || y >= m)
        return false;
        return true;
    }
  public:
    // Function to find the number of islands.
    void traverse(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        if(x < 0 || y < 0 || x >= n || y >= m)
        return;
        for(auto move:directions){
            int nx = move.first + x, ny = move.second + y;
            if(isValid(n, m, nx, ny) && grid[nx][ny] == '1' && !visited[nx][ny]){
                visited[nx][ny] = true;
                traverse(grid, visited, nx, ny);
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    count++;
                    visited[i][j] = true;
                    traverse(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends