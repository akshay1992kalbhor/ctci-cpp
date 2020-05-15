#include "tree_node_p.h"

TreeNodeP* first_parent_with_left_child(TreeNodeP* c) {
	while (c->parent != nullptr) {
		if (c->value <= c->parent->value) {
			return c->parent;
		} else {
			c = c->parent;
		}
	}
	return nullptr;
}
int successor(TreeNodeP* n) {
	if (n) {
		if (n->right) {
			auto c = n->right;	
			while (c->left) {
				c = c->left;	
			}
			return c->value;
		} else {
			if (n->parent) {
				TreeNodeP* p = first_parent_with_left_child(n);
				if (p) {
					return p->value;
				} else {
					return -1;
				}
			} else {
				return -2;
			}
		}
	} else {
		return -3;
	}
}

int main() {
	std::vector<TreeNodeP*> nodes = create_vec_nodes({7,4,8,2,5});
	create_tree(nodes);
	int r = successor(nodes[4]);
	std::cout << "Ans: " << r << std::endl;
}
