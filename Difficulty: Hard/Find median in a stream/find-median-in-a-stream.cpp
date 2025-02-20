//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        priority_queue<int> leftMaxheap;
        priority_queue<int, vector<int>, greater<int>> rightMinheap;
        for(int i = 0; i < arr.size(); i++){
            leftMaxheap.push(arr[i]);
            
            int temp = leftMaxheap.top();
            leftMaxheap.pop();
            rightMinheap.push(temp);
            
            if(leftMaxheap.size() != rightMinheap.size()){
                temp = rightMinheap.top();
                rightMinheap.pop();
                leftMaxheap.push(temp);
            }
            
            if(leftMaxheap.size() == rightMinheap.size()){
                ans.push_back((leftMaxheap.top() + rightMinheap.top())/2.0);
            }
            else
            ans.push_back(leftMaxheap.top());
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends