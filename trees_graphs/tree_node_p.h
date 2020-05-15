#include <iostream>
#include <vector>

struct TreeNodeP {
	int value;
	TreeNodeP* parent;
	TreeNodeP* left;
	TreeNodeP* right;
	TreeNodeP(int _value, TreeNodeP* _left, TreeNodeP* _right, TreeNodeP* _parent);
};

std::vector<TreeNodeP*> create_vec_nodes(std::vector<int> vec);
void create_tree(std::vector<TreeNodeP*>& vec);
void delete_tree(std::vector<TreeNodeP*>& vec);
