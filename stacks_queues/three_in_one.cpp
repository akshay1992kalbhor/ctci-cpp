#include <iostream>
#include <vector>

using namespace std;


struct Stack {
    
    vector<int> store;
    Stack() : store(0) {}
    void push(const int& e) {
        store.push_back(e);
    }
    int pop() {
        int e = store.back();
        store.pop_back();
        return e;
    }
};


/*
sz = 5
01234
p < store + 5
*/
struct Stack_CArray {
    int* store;
    int sz = 0;
    int cap;
    const static int errval = -1; 
    Stack_CArray(int cap) : store{new int[cap]}, cap{cap} {}
    void push(int e) {
        if (sz < cap) {
            *(store + sz) = e;
            sz++;
        } else {
            // increase size of the storage
            cout << "No space in the container\n";
        }
    }
    void pop() {
        if (sz > 0)
            sz--;
    }
    ~Stack_CArray() {
        delete[] store;
    }
    const int& back() {
        if (sz > 0)
            return store[sz-1];
        else
            return errval;
    }
};

struct ThreeStack {
    int* store;
    int sz[3] = {0, 0, 0};
    int cap;
    const static int errval = -1;
    ThreeStack(int cap) : store{new int[cap*3]}, cap{cap} {}
    void push(int stack_no, int e) {
        if (sz[stack_no] < cap) {
            *(store + (cap*stack_no) + sz[stack_no]) = e;
            sz[stack_no]++;
        } else {
            // increase size of the storage
            cout << "No space in the container\n";
        }
    }
    void pop(int stack_no) {
        if (sz[stack_no] > 0)
            sz[stack_no]--;
    }
    ~ThreeStack() {
        delete[] store;
    }
    const int& back(int stack_no) {
        if (sz[stack_no] > 0)
            return store[(cap*stack_no) + sz[stack_no] - 1];
        else
            return errval;
    }
};


void print_stack(const Stack& s) {
    for (auto& e : s.store)
        cout << e << endl;
}

void print_cstack(const Stack_CArray& s) {
    for (int i = 0; i < s.sz; i++)
        cout << s.store[i] << endl;
}

int main() {
    /*
    Stack s;
    s.push(1);
    s.push(3);
    s.push(2);
    print_stack(s);
    s.pop();
    print_stack(s);
    */

    Stack_CArray sc{3};
    sc.push(9);
    sc.push(10);
    sc.push(11);
    print_cstack(sc);
    //const int& e = sc.back();
    //sc.pop();
    //cout << "Popped element: " << e << endl;
    //print_cstack(sc);
}
