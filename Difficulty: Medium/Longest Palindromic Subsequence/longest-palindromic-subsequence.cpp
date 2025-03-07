//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
    int longestCommonSubseq(string &s1, string &s2){
        vector<int> prev(s1.length() + 1, 0);
        vector<int> next(s1.length() + 1, 0);
        
        for(int i = 0; i < s2.length(); i++){
            next[0] = 0;
            for(int j = 0; j < s1.length(); j++){
                if(s1[i] == s2[j])
                next[j+1] = prev[j] + 1;
                else
                next[j+1] = max(prev[j+1], next[j]);
            }
            prev = next;
        }
        return next[s1.length()];
    }
    
  public:
    int longestPalinSubseq(string &s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return longestCommonSubseq(s, s1);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends