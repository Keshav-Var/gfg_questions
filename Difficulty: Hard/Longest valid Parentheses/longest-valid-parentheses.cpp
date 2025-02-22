//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        stack<int> st;
        st.push(-1);
        int len = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '(')
            st.push(i);
            else if(st.size() == 1){
                st.pop();
                st.push(i);
            }
            else{
                st.pop();
                len = max(len, i - st.top());
            }
        }
        return len;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends