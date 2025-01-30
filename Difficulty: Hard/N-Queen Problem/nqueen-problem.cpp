//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    bool isValid(int n, vector<vector<int>>& board, int row, int col){
        for(int i = 0; i < col; i++)
            if(board[row][i]) return false;
        for(int i = row, j = col; i >= 0 && j >= 0; i--,j--)
            if(board[i][j]) return false;
        for(int i = row, j = col; j >= 0 && i < n; i++, j--)
            if(board[i][j]) return false;
        return true;
    }
    
    void fillPos(vector<vector<int>>& pos, vector<vector<int>>& board, int col, int n, vector<int> temp = vector<int>()){
        if(col == n){
            pos.push_back(temp);
            return;
        }
        for(int row = 0; row < n; row++){
            if(isValid(n, board, row, col)){
                board[row][col] = 1;
                temp.push_back(row+1);
                fillPos(pos, board, col+1, n, temp);
                board[row][col] = 0;
                temp.pop_back();
            }
        }
    }
    
  public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> pos;
        vector<vector<int>> board(n, vector<int>(n, 0));
        fillPos(pos, board, 0, n);
        return pos;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends