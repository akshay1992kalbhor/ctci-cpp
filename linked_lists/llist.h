#include <iostream>
#include <memory>
#include <vector>

class Node {
public:
	int value;
	std::shared_ptr<Node> next;
};

void print_ll(std::shared_ptr<Node> head); 
std::shared_ptr<Node> make_linked_list(std::vector<int> vec);
