//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void reverse(vector<int>& arr, int i, int j){
        while(i < j)   
        swap(arr[i++], arr[j--]);
    }
    
    void nextPermutation(vector<int>& arr) {
        int index = arr.size()-1;
        while(index > 0 && arr[index] <= arr[index - 1]){
            index--;
        }
        if(index == 0){
            reverse(arr, 0, arr.size() - 1);
            return;
        }
        int greater = index;
        for(int i = index; i < arr.size(); i++){
            if(arr[i] > arr[index - 1])
            greater = i;
        }
        swap(arr[greater], arr[index - 1]);
        reverse(arr, index, arr.size() - 1);
        return;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends