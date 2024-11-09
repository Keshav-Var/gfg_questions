//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string num1 = "";
        string num2 = "";
        for(int i = 0; i < arr.size(); i++){
            if(i%2) num1 += to_string(arr[i]);
            else num2 += to_string(arr[i]);
        }

        int carry = 0;
        string sum = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        while(i>=0 && j>=0){
            int d1 = num1[i--] - '0';
            int d2 = num2[j--] - '0';
            sum += to_string((d1+d2+carry)%10);
            carry = (d1+d2+carry)/10;
        }
        reverse(sum.begin(), sum.end());
        if(i == 0){
            sum = to_string((num1[0] - '0') + carry) + sum;
            carry = 0;
        }
        if(j==0){
            sum = to_string((num2[0] - '0') + carry) + sum;
            carry = 0;
        }
        sum = to_string(carry) + sum;
        i = 0;
        while(sum[i] == '0') i++;
        return sum.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends