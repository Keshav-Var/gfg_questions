//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    bool isValid(int n, int m, int x, int y, vector<vector<bool>>& visited){
        if(x>=0 && y >= 0 && x < n && y < m && !visited[x][y])
        return true;
        return false;
    }
    
    bool match(vector<vector<char>>& mat, vector<vector<bool>>& visited, string& word, int l, int i, int x, int y){
        int n = mat.size();
        int m = mat[0].size();
        
        if(word[i] != mat[x][y]) return false;
        if(i == l - 1) return true;
        
        for(auto d:dir){
            int nx = x + d.first;
            int ny = y + d.second;
            
            if(isValid(n, m, nx, ny, visited)){
                visited[x][y] = true;
                if(match(mat, visited, word, l, i+1, nx, ny))
                return true;
                visited[x][y] = false;
            }
        }
        return false;
    }
  
  
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false));
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(match(mat, visited, word, word.length(), 0, i, j))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends