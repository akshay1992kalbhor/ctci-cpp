#include "llist.h"
using namespace std;

shared_ptr<Node> partition(shared_ptr<Node> head, int value) {
	shared_ptr<Node> h1, h2 = nullptr;
	shared_ptr<Node> cur = head;
	shared_ptr<Node> curnew = nullptr;
	while (cur) {
		if (cur.get()->value < value) {
			if (h1) {
				curnew.get()->next = shared_ptr<Node> {new Node{cur.get()->value, nullptr}};
				curnew = curnew.get()->next;
			} else {
				h1 = shared_ptr<Node> {new Node{cur.get()->value, nullptr}};
				curnew = h1;
			}
		}
		cur = cur.get()->next;
	}
	cur = head;
    //curnew = nullptr;
    while (cur) {
		if (cur.get()->value >= value) {
			if (curnew) {
				// h1 is not nullptr
				curnew.get()->next = shared_ptr<Node> {new Node{cur.get()->value, nullptr}};
				curnew = curnew.get()->next;
			} else {
				h2 = shared_ptr<Node> {new Node{cur.get()->value, nullptr}};
				curnew = h2;
			}
		}
		cur = cur.get()->next;
	}
		
	return h1 ? h1 : h2;
}



int main() {
	auto llp = make_linked_list({7,5,1,7,2,1,15});
	auto a = partition(llp, 7);
	print_ll(a);
}
