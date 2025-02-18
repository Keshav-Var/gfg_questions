//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    struct comp{
      bool operator()(const vector<int> &v1, const vector<int> &v2)  {
          return ((v1[0]*v1[0])+(v1[1] * v1[1])) > ((v2[0] * v2[0])+(v2[1] * v2[1]));
      }
    };
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        for(auto point:points){
            pq.push(point);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends