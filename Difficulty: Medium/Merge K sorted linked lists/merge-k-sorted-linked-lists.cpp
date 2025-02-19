//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    Node* merge(Node *head1, Node *head2){
        if(!head1) return head2;
        if(!head2) return head1;
        Node *head = NULL;
        Node *temp = NULL;
        while(head1 && head2){
            if(head1->data < head2->data){
                if(!head) {head = head1; temp = head1;}
                else {temp->next = head1; temp = temp->next;}
                head1  = head1->next;
            }
            else{
                if(!head) {head = head2; temp = head2;}
                else {temp->next = head2; temp = temp->next;}
                head2 = head2->next;
            }
        }
        while(head1){
            temp->next = head1;
            head1 = head1->next;
            temp = temp -> next;
        }
        while(head2){
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
        }
        return head;
    }
    
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        Node *head = NULL;
        for(int i = 0; i < arr.size(); i++){
            head = merge(arr[i], head);
        }
        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends