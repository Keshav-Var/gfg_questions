//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

struct Node{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
  private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

    void add(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void rm(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    // ~LRUCache() {
    //     Node* curr = head;
    //     while (curr) {
    //         Node* next = curr->next;
    //         delete curr;
    //         curr = next;
    //     }
    // }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        Node* node = cache[key];
        rm(node);
        add(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            rm(node);
            add(node);
            return;
        }

        Node* node = new Node(key, value);
        cache[key] = node;
        add(node);

        if (cache.size() > capacity) {
            Node* nodeToDelete = tail->prev;
            rm(nodeToDelete);
            cache.erase(nodeToDelete->key);
            delete nodeToDelete;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends