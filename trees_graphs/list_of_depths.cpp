#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    Node* next = nullptr;
    int value;
    Node(int v) : value{v} {}
};

struct BNode {
    BNode* left = nullptr;
    BNode* right = nullptr;
    int value;
    BNode(int v) : value{v} {}
};




void depth_rec(int depth, vector<Node*>& v, BNode* bt) {
    if (bt) {
        cout << "Depth rec\n";
        Node* n = new Node(bt->value);
        if (v.size() >= depth+1) {
            n->next = v[depth];
            v[depth] = n;
        } else {
            v.push_back(n);
        }
        depth_rec(depth+1, v, bt->left);
        depth_rec(depth+1, v, bt->right);
    }
}

void list_of_depths(vector<Node*>& v, BNode* bt) {
    int depth = 0;
    depth_rec(depth, v, bt);
}

void pll(Node* h) {
    while (h) {
        cout << h->value << " -> ";
        h = h->next;
    }
    cout << "X\n";
}

int main() {

    vector<Node*> v;
    BNode b3 {11};
    BNode b2 {9};
    BNode b1 {10};
    b1.left = &b2;
    b2.left = &b3;
    cout << "Start processing\n";
    list_of_depths(v, &b1);
    cout << "Done processing\n";
    cout << v.size() << endl;
    for (auto& n : v) {
        pll(n);
    }
}
