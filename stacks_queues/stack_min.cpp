#include <iostream>
#include <stdexcept>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* nmin;
    Node(int v) : value{v}, next{nullptr}, nmin{nullptr} {}
    ~Node() {

    }
};

struct Stack {
    Node* mint;
    Node* tail;
    Stack() : mint{nullptr}, tail{nullptr} {}
    void push(int val) {
        Node* n = new Node(val);
        if (n) {
            if (!tail) {
                mint = n;
                tail = n;
            } else {
                if (val < mint->value)
                    n->nmin = mint;
                    mint = n;
                n->next = tail;
                tail = n;
                
            }
        }
    }
    int pop() {
        if (tail) {
            int v = tail->value;
            Node* new_tail = tail->next;
            delete tail;
            tail = new_tail;
            return v;
        } else {
            throw std::runtime_error {"No item to pop"};
        }
    }
    int min() {
        if (mint) {
            return mint->value;
        } else {
            throw std::runtime_error {"Empty Stack"};
        }
    }
};

int main() {

}
