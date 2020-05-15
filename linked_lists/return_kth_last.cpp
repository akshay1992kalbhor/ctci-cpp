#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v, Node* n) : val{v}, next{n} {}
};

Node* return_kth_last(Node* h, int k) {
    if (k < 1)
        return nullptr;

    int l = 0;
    Node* c = h;
    while (c != nullptr) {
        l += 1;
        c = c->next;
    }
    if (k > l)
        return nullptr;
    
    c = h;
    for (int i = 0; i < (l-1) ;i++) {
        c = c->next;
    }
    return c;
}

// 1 - 2 - 4
Node* return_kth_last_rec(Node* h, int k, int& i) {
    if (h == nullptr)
        return nullptr;
    Node* a = return_kth_last_rec(h->next, k, i);
    i = i + 1;
    if (i == k)
        return h;
    return a;
}

Node* return_kth_last1(Node* h, int k) {
    int i = 0;
    return return_kth_last_rec(h, k, i);
}

int main() {
    Node h {1, nullptr};
    Node h1 {2, nullptr};
    Node h2 {4, nullptr};
    h.next = (&h1);
    h1.next = (&h2);
    Node* a = return_kth_last1(&h, 3);
    cout << a->val << endl;
}
