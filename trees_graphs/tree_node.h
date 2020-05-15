#include <iostream>
#include <vector>

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int _value, TreeNode* _left, TreeNode* _right);
};

std::vector<TreeNode*> create_vec_nodes(std::vector<int> vec);
void create_tree(std::vector<TreeNode*>& vec);
void delete_tree(std::vector<TreeNode*>& vec);
