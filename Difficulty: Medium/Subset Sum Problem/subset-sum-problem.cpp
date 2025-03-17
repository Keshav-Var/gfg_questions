//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<bool> curr(sum+1, false), prev(sum+1, false);
        
        for(int i = 1; i <= arr.size(); i++){
            prev[0] = true;
            curr[0] = true;
            for(int j = 1; j <= sum; j++){
                if(arr[i - 1] <= j) curr[j] = (prev[j - arr[i-1]] || prev[j]);
                else curr[j] = prev[j];
            }
            prev = curr;
        }
        return curr[sum];
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends