#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v, Node* n) : val{v}, next{n} {}
    void setNext(Node* n) {
        next = n;
    }
};



/*
Space Complexity: O(n);
Time Complexity: O(n); */
void remove_dups(Node* h) {
   
 
    unordered_map<int,bool> m;
    
    Node* it = h;
    Node* prev = nullptr;
    while (it != nullptr) {
        
        if (m.find(it->val) != m.end()) {
            // seen before, so its a dup
            // remove the current node
            // p -> c -> n
            // p -> n
            prev->next = it->next;
            cout << "Removed one node with val: " << it->val << endl;
            // dont change prev
        } else {
            // new val
            cout << "Not seen " << it->val << " before\n";
            m[it->val] = true;
            prev = it;
        }
        
        it = it->next;
    }
    
    // iterate through the list
    // store seen nodes
    // remove if seen
        
}


// 1 -> 2 -> 2
// 
void remove_dups1(Node* h) {
    if (!h) {
        return;
    }
    Node* t = h;
    /* removed premature optimization */
    while (t != nullptr) {
        Node* c = t->next;
        Node* prev = t;
        while (c != nullptr) {
            if (c->val == t->val) {
                // remove c
                prev->next = c->next;
            } else {
                prev = c;
            }
            c = c->next;
        }
        t = t->next;
    }
}

void iter_list(Node* h) {
    while (h) {
        cout << h->val << endl;
        h = h->next;
    }
}

int main() {
    Node h {1, nullptr};
    Node h1 {2, nullptr};
    Node h2 {2, nullptr};
    h.setNext(&h1);
    h1.setNext(&h2);
    iter_list(&h);
    remove_dups1(&h);
    iter_list(&h);
}
