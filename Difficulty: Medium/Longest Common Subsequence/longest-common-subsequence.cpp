//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lcs(string &s1, string &s2) {
        vector<int> prev(s1.length()+1, 0);
        vector<int> curr(s1.length()+1, 0);
        
        for(int i = 0; i < s2.length(); i++){
            curr[0] = 0;
            for(int j = 0; j < s1.length(); j++){
                if(s2[i] == s1[j]){
                    curr[j+1] = prev[j] + 1;
                }
                else{
                    curr[j+1] = max(prev[j+1], curr[j]);
                }
            }
            prev = curr;
        }
        return curr[s1.length()];
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends