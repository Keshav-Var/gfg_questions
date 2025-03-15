//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int solve(vector<int>& coins, int sum, int i){
        if(sum == 0) return 0;
        if(i < 0 || sum < 0) return 1e5;
        return min(1+solve(coins, sum - coins[i], i), solve(coins, sum, i-1));
    }
    
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<vector<int>> dp(sum+1, vector<int>(coins.size()+1, 0));
        
        for(int i = 1; i <= sum; i++)
        dp[i][0] = 1e6;
        
        for(int i = 1; i <= sum; i++){
            for(int j = 1; j <= coins.size(); j++){
                dp[i][j] = dp[i][j-1];
                if(coins[j-1] <= i)
                dp[i][j] = min(dp[i][j], 1+dp[i-coins[j-1]][j]);
            }
        }
        
        return dp[sum][coins.size()] >= 1e6? -1: dp[sum][coins.size()];
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends