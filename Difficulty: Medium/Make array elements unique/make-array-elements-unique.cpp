//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int> arr) {
        int ans = 0;
        sort(arr.begin(), arr.end());
        unordered_set<int> ht;
        ht.insert(arr[0]);
        for(int i = 1; i < arr.size(); i++){
            if(ht.find(arr[i]) == ht.end()){
                ht.insert(arr[i]);
            }
            else{
                ans += arr[i - 1] - arr[i] + 1;
                arr[i] += arr[i - 1] - arr[i] + 1;
                ht.insert(arr[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends