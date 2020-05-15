#include "tree_node_p.h"


TreeNodeP::TreeNodeP(int _value, TreeNodeP* _left, TreeNodeP* _right, TreeNodeP* _parent) : value{_value}, parent{_parent}, left{_left}, right{_right} {}


std::vector<TreeNodeP*> create_vec_nodes(std::vector<int> vec) {
	std::vector<TreeNodeP*> result{};

	for (const auto& i : vec) {
		if (i != -1) 
			result.push_back(new TreeNodeP{ i, nullptr, nullptr, nullptr});
		else
			result.push_back(nullptr);
	}	
	return result;
}


void create_tree(std::vector<TreeNodeP*>& vec) {
	size_t s = vec.size();
	// vec [ 1 , 2, 3, nullptr, 4, 5, 6];
	for (size_t i = 0; i < s; ++i) {
		TreeNodeP* p = vec[i];
		size_t left = i * 2 + 1;
		size_t right = i * 2 + 2;

		if (left < s)
			p->left = vec[left];
		if (right < s)
			p->right = vec[right];	
		if (i != 0) {
			if (i % 2 == 1) {
				size_t parent = (i - 1) / 2;
				p->parent = vec[parent];
			} else {
				size_t parent = (i - 2) / 2;
				p->parent = vec[parent];
			}
		}
	}
}

void delete_tree(std::vector<TreeNodeP*>& vec) {
	for ( auto p : vec)
		if (p)
			delete p;
}
