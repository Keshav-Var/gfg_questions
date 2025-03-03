//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> mini, maxi; // Deques for min & max indices
    int i = 0, j = 0;
    int st = 0, end = 0, maxLen = 0;

    while (j < arr.size()) {
        // Maintain max deque
        while (!maxi.empty() && arr[maxi.back()] <= arr[j])
            maxi.pop_back();
        maxi.push_back(j);

        // Maintain min deque
        while (!mini.empty() && arr[mini.back()] >= arr[j])
            mini.pop_back();
        mini.push_back(j);

        // Shrink the window if the difference is more than x
        while (!maxi.empty() && !mini.empty() && (arr[maxi.front()] - arr[mini.front()]) > x) {
            i++;
            if (!maxi.empty() && maxi.front() < i) maxi.pop_front(); // Remove outdated max
            if (!mini.empty() && mini.front() < i) mini.pop_front(); // Remove outdated min
        }

        // Update the longest subarray
        if ((j - i + 1) > maxLen) {
            st = i;
            end = j;
            maxLen = j - i + 1;
        }
        j++;
    }

    // Construct the result
    vector<int> ans(arr.begin() + st, arr.begin() + end + 1);
    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends