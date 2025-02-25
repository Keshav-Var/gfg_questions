//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<int> previousSmaller(vector<int> v){
        stack<int> st;
        vector<int> ans(v.size());
        ans[0] = -1;
        st.push(0);
        for(int i = 1; i < v.size(); i++){
            while(!st.empty() && v[st.top()] >= v[i])
            st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> nextSmaller(vector<int> v){
        int n = v.size();
        stack<int> st;
        vector<int> ans(n);
        ans[n-1] = n;
        st.push(n-1);
        for(int i = n-2; i>=0; i--){
            while(!st.empty() && v[st.top()] >= v[i])
            st.pop();
            if(st.empty()) ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    
  public:
    int getMaxArea(vector<int> &arr) {
        vector<int> prev = previousSmaller(arr);
        vector<int> next = nextSmaller(arr);
        
        // for(auto i:prev)
        // cout<<i<<" ";
        // cout<<endl;
        // for(auto i:next)
        // cout<<i<<" ";
        // cout<<endl;
        
        int maxArea = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
            int left = prev[i] + 1;
            int right = next[i] - 1;
            // cout<<((right-left+1)*arr[i])<<" ";
            maxArea = max(maxArea, (right - left + 1)*arr[i]);
        }
        return maxArea;
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends