//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        int start = 0;
        int maxLen = 1;
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j <= 1; j++){
                // j = 0 for odd length palindrome
                // j = 1 for even length palindrome
                int low = i;
                int high = i + j;
                while(low >= 0 && high < s.length() && s[low] == s[high]){
                    if(high - low + 1 > maxLen){
                        maxLen = high - low + 1;
                        start = low;
                    }
                    low--; high++;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends