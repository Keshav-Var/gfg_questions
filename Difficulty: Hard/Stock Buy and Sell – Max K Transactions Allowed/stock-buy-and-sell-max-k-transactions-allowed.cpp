//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1)));
        
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j <= 1; j++){
                for(int cap = 1; cap <= k; cap++){
                    if(!j){
                        dp[i][j][cap] = max(0 + dp[i+1][0][cap], 
                                            -prices[i] + dp[i+1][1][cap]);
                    }
                    else{
                        dp[i][j][cap] = max(0 + dp[i+1][1][cap], prices[i] + dp[i+1][0][cap - 1]);
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends