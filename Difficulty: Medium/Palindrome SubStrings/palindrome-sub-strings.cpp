//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < 2; j++){
                int low = i;
                int high = i + j;
                while(low >= 0 && high < s.length() && s[low] == s[high]){
                    if(high - low + 1 >= 2)
                    count++;
                    low--; high++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends