//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    bool isValid(vector<vector<int>> &mat, int num, int row, int col){
        for(int i = 0; i < 9; i++){
            if(mat[i][col] == num || mat[row][i] == num)
            return false;
        }
        int bx = row - (row%3), by = col - (col%3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(mat[i + bx][j + by] == num)
                return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<int>> &mat, int row, int col){
        if(row == 8 && col == 9)
        return true;
        
        if(col == 9){
            row++;
            col = 0;
        }
        
        if(mat[row][col] != 0)
        return solve(mat, row, col+1);
        
        for(int i = 1; i <= 9; i++){
            if(isValid(mat, i, row, col)){
                mat[row][col] = i;
                if(solve(mat, row, col+1))
                return true;
                mat[row][col] = 0;
            }
        }
        return false;
    }
    
  public:
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat, 0, 0);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends