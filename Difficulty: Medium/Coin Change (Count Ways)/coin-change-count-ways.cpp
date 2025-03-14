//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        vector<vector<int>> dp(sum+1, vector<int>(coins.size()+1, 0));
        
        for(int i = 0; i <= coins.size(); i++)
        dp[0][i] = 1;
        
        for(int  i = 1; i <= sum; i++){
            for(int j = 1; j <= coins.size(); j++){
                dp[i][j] = dp[i][j-1];
                if(coins[j-1] <= i)
                dp[i][j] += dp[i - coins[j-1]][j];
            }
        }
        
        return dp[sum][coins.size()];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends