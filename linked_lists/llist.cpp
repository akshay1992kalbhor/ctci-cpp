#include "llist.h"
using namespace std;
void print_ll(shared_ptr<Node> head) {


	while (head) {
		cout << head.get()->value << " -> ";
		head = head.get()->next;
	}
	cout << "X" << endl;
}

shared_ptr<Node> make_linked_list(vector<int> vec) {
    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> current = nullptr;
	for (auto& i : vec) {
		auto temp = shared_ptr<Node> {new Node{i, nullptr}};

		if (current) {
			current.get()->next = temp;
			current = temp;	
		} else {
			current = temp;
	    	head = current; 
		}
	}
    return head;
}
