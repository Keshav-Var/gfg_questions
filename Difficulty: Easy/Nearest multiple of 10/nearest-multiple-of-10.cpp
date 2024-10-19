//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int i = str.length() - 1;
        if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5'){
            str[i] = '0';
            return str;
        }
        else{
            int carry = 1;
            str[i--] = '0';
            do{
                int temp = str[i] - '0';
                temp += carry;
                str[i] = char('0' + temp % 10);
                temp = temp/10;
                carry = temp % 10;
                i--;
            }while(carry != 0 && i >= 0);
            
            if(carry == 1)
            return '1' + str;
            else
            return str;
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends