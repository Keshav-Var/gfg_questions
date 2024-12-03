//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
        int n = s.length();
        string rvs = s;
        reverse(rvs.begin(), rvs.end());
        s = s + '$' + rvs;
        vector<int> lps(2 * n + 1, 0);
        lps[0] = 0;
        for(int i = 1, length = 0; i < 2 * n + 1;){
            if(s[i] == s[length]){
                length++;
                lps[i++] = length;
            }
            else{
                if(length > 0)
                length = lps[length - 1];
                else{
                    length = 0;
                    i++;
                }
            }
        }
        return n - lps[2*n];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends