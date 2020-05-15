#include "tree_node.h"

bool cbr(TreeNode* tn, int& m) {
	if (tn) {
		int m1 = 0;
		int m2 = 0;
		if (cbr(tn->l_, m1) && cbr(tn->r_, m2)) {
			if (m1 - m2 >= -1 && m1-m2 <= 1) {
				m = std::max(m1, m2) + 1;
				return true;
			} else {
				return false;
			}	
		} else {
			return false;
		}
	} else {
		return true;
	}	
}


bool check_balanced(TreeNode* tn) {
	if (tn) {
		int m = 0;
		return cbr(tn, m);	
	} else {
		return false;
	}
}



int main() {

	auto v = create_vec_nodes( { 1 , 2, -1, 3 } );		
	create_tree( v );

	bool ans = check_balanced(v[0]);
	std::cout << std::boolalpha << ans << '\n';
}
