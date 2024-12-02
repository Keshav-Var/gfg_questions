//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void fillLPS(string& str, vector<int>& lps){
    int n = str.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < n){
        if(str[i] == str[len]){
            len++; 
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len - 1];
            }
        }
    }
  }
  
    vector<int> search(string& pat, string& txt) {
        vector<int> lps(pat.length(), 0);
        vector<int> ans;
        int N = txt.length();
        int M = pat.length();
        fillLPS(pat, lps);
        int  i = 0, j = 0;
        while(i < N){
            if(pat[j] == txt[i]){
                i++; j++;
            }
            if(j == M){
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if(i < N && pat[j] != txt[i]){
                if(j == 0) i++;
                else{
                    j = lps[j - 1];
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends