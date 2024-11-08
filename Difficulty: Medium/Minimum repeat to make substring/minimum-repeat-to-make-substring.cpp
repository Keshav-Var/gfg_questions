//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        string temp = s1;
        int count = 1;
        while(temp.length() < s2.length()){
            temp += s1;
            count++;
        }
        if(temp.find(s2) != string::npos)
        return count;
        temp +=s1;
        count++;
        if(temp.find(s2) != string::npos)
        return count;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends