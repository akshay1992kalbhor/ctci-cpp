#include "tree_node.h"


TreeNode::TreeNode(int _value, TreeNode* _left, TreeNode* _right) : value{_value}, left{_left}, right{_right} {}


std::vector<TreeNode*> create_vec_nodes(std::vector<int> vec) {
	std::vector<TreeNode*> result{};

	for (const auto& i : vec) {
		if (i != -1) 
			result.push_back(new TreeNode{ i, nullptr, nullptr });
		else
			result.push_back(nullptr);
	}	
	return result;
}


void create_tree(std::vector<TreeNode*>& vec) {
	size_t s = vec.size();
	// vec [ 1 , 2, 3, nullptr, 4, 5, 6];
	for (size_t i = 0; i < s; ++i) {
		TreeNode* p = vec[i];
		size_t left = i * 2 + 1;
		size_t right = i * 2 + 2;
		if (left < s)
			p->left = vec[left];
		if (right < s)
			p->right = vec[right];	
	}
}

void delete_tree(std::vector<TreeNode*>& vec) {
	for ( auto p : vec)
		if (p)
			delete p;
}
