//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        string st = "";
        string temp = "";
        for(int i = s.length()-1; i >= 0; i--){
            if((s[i] <='z' && s[i] >= 'a') || s[i] == ']') st += s[i];
            else if(s[i] <= '9' && s[i] >= '0'){
                int num = 0, mul = 1;
                while(i >= 0 && s[i] <= '9' && s[i] >= '0'){
                    int bit = s[i] - '0';
                    num += (bit*mul);
                    mul *= 10;
                    i--;
                }
                i++;
                for(int j = 0; j < num; j++){
                    st += temp;
                }
                temp = "";
            }
            else if(s[i] == '['){
                while(st.back() != ']'){
                    temp += st.back();
                    st.pop_back();
                }
                reverse(temp.begin(), temp.end());
                st.pop_back();
            }
        }
        reverse(st.begin(), st.end());
        return st;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends