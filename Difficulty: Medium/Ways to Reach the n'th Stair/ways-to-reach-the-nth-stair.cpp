//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        if(n == 1 || n == 2) return n;
        int n1 = 1;
        int n2 = 2;
        int temp;
        for(int i = 2; i < n; i++){
            temp = n1 + n2;
            n1 = n2;
            n2 = temp;
        }
        return temp;
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends