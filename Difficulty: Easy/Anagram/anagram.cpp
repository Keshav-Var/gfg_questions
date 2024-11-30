//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        int hash1[26];
        int hash2[26];
        for(int i = 0; i < 26; i++){
            hash1[i] = 0;
            hash2[i] = 0;
        }
        for(int i = 0; i < s1.length(); i++){
            hash1[s1[i] - 'a']++;
        }
        for(int i = 0; i < s2.length(); i++){
            hash2[s2[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(hash1[i] != hash2[i])
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends