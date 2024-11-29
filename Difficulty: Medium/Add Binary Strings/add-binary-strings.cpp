//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string removeLeadingZero(string s){
        int i = 0;
        while(s[i] == ' ' || s[i] == '0') i++;
        return s.substr(i);
    }
    string addBinary(string& s1, string& s2) {
        string ans = "";
        s1 = removeLeadingZero(s1);
        s2 = removeLeadingZero(s2);
        int i = s1.length() - 1, j = s2.length() - 1, carry = 0;
        while(i >= 0 && j >= 0){
            int bit1 = s1[i--] - '0';
            int bit2 = s2[j--] - '0';
            int sum = bit1 ^ bit2 ^ carry;
            carry = ((bit1 & bit2) | (carry & (bit1 ^ bit2)));
            ans += sum == 0?'0':'1';
        }
        while(i >= 0){
            int bit1 = s1[i--] - '0';
            int sum = bit1 ^ carry;
            carry = bit1 & carry;
            ans += sum == 0?'0':'1';
        }
        while(j >= 0){
            int bit2 = s2[j--] - '0';
            int sum = bit2 ^ carry;
            carry = bit2 & carry;
            ans += sum == 0?'0':'1';
        }
        if(carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends