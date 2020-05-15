#include "tree_node.h"
#define INTMAX 1000
#define INTMIN -1000



bool validate_rec(TreeNode* t, int max, int min) {
	if (t) {
		if (t->val_ >= min && t->val_ <= max)
			return validate_rec(t->l_, t->val_, min) && validate_rec(t->r_, max, t->val_);
		else
			return false;
	} else {
		return true;
	}
}
bool validate(TreeNode* t) {
	return validate_rec(t, INTMAX, INTMIN);

}
int main() {
	auto f = create_vec_nodes({5, 8, 7});
	create_tree(f);
	auto ans = validate(f[0]);
	std::cout << std::boolalpha << ans << std::endl;
} 

