//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int parent(int index){
        return index == 0? -1 : (index - 1)/2;
    }
    
    int left(int index){
        return 2*index + 1;
    }
    
    int right(int index){
        return 2*index + 2;
    }
    
    void maxHeapify(vector<int> &v, int index, int n){
        int largest = index, l = left(index), r = right(index);
        if(l < n && v[l] > v[largest]) largest = l;
        if(r < n && v[r] > v[largest]) largest = r;
        if(largest != index){
            swap(v[index], v[largest]);
            maxHeapify(v, largest, n);
        }
    }
    
    void buildHeap(vector<int> &v){
        for(int i = parent(v.size() - 1); i >= 0; i--)
        maxHeapify(v, i, v.size());
    }
    
    void heapSort(vector<int> &v){
        buildHeap(v);
        for(int i = v.size() - 1; i >= 0; i--){
            swap(v[0], v[i]);
            maxHeapify(v, 0, i);
        }
    }
    
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        vector<int> ans;
        heapSort(arr);
        for(int i = 1; i <= k; i++)
        ans.push_back(arr[arr.size() - i]);
        return ans;
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
        vector<int> ans = ob.kLargest(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends