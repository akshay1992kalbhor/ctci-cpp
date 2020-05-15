#include "llist.h"
using namespace std;

shared_ptr<Node> sum_lists(shared_ptr<Node> first, shared_ptr<Node> second) {
  int carryover = 0;
  shared_ptr<Node> head;
  shared_ptr<Node> current;
  while (first != nullptr || second != nullptr) {
    int fval = first ? first->value : 0;
    int sval = second ? second->value : 0;
    int total = fval + sval + carryover;
    carryover = total >= 10 ? 1 : 0;
    int digit = total >= 10 ? total - 10 : total;
    
	if (!head) {
      head = shared_ptr<Node>{new Node{digit, nullptr}};
      current = head;
    } else {
      current->next = shared_ptr<Node>{new Node{digit, nullptr}};
      current = current->next;
    }
    
	first = first ? first->next : nullptr;
    second = second ? second->next : nullptr;
  }

  if (carryover) {
    current->next = shared_ptr<Node>{new Node{1, nullptr}};
  }
  return head;
}

int main() {
  auto ll1 = make_linked_list({9, 9});
  auto ll2 = make_linked_list({1});
  auto sumll = sum_lists(ll1, ll2);
  print_ll(sumll);
}
