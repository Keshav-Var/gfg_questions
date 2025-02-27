//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    stack<int> st;
    stack<int> a;
  public:
    Solution() {
        
    }

    // Add an element to the top of Stack
    void push(int x) {
        st.push(x);
        if(a.empty() || a.top() >= x)
        a.push(x);
    }

    // Remove the top element from the Stack
    void pop() {
        if(st.empty()) return;
        if(st.top() == a.top())
        a.pop();
        st.pop();
    }

    // Returns top element of the Stack
    int peek() {
        return st.empty()?-1:st.top();
    }

    // Finds minimum element of Stack
    int getMin() {
        return a.empty()?-1:a.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends