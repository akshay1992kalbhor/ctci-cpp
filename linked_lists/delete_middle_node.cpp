#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v, Node* n) : value{v}, next{n} {}
};

// a - b - c - d - e - f - g

void delete_middle_node(Node* m) {
    if (!m)
        return;
    Node* c = m;
    
    while (c->next->next != nullptr) {
        c->value = c->next->value;
        c = c->next;
    }

    // second-last node
    c->value = c->next->value;
    c->next = nullptr;
}

void iter(Node* h) {
    while (h != nullptr) {
        cout << h->value << endl;
        h = h->next;
    }
}

int main() {
    Node h3 {4, nullptr};
    Node h2 {3, &h3};
    Node h1 {2, &h2};
    Node h {1, &h1};
    iter(&h); 
    delete_middle_node(&h1);
    iter(&h);
}
