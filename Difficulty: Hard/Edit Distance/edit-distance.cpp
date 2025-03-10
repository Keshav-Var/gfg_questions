//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        vector<int> prev(s1.length()+1);
        vector<int> curr(s1.length()+1);
        for(int i = 0; i <= s1.length(); i++)
        prev[i] = i;
        for(int i = 1; i <= s2.length(); i++){
            curr[0] = i;
            for(int j = 1; j <= s1.length(); j++){
                if(s1[j-1] == s2[i-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min({prev[j], prev[j-1], curr[j-1]});
            }
            prev = curr;
        }
        return curr[s1.length()];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends