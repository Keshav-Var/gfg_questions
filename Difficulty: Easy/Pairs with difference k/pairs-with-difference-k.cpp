//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> ht;
        int count = 0;
        for(auto it:arr){
            if(ht.find(it - k) != ht.end()){
                count += ht[it - k];
                // cout<<"1"<<endl;
            }
            
            if(ht.find(k + it) != ht.end()){
                count += ht[k + it];
                // cout<<"2"<<endl;
            }
            ht[it]++;
            // cout<<it<<" "<<ht[it]<<" "<<count<<endl;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends