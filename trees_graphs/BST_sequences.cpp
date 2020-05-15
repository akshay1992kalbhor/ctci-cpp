#include "tree_node.h"
#include <string>
using namespace std;

vector<vector<int>> base(vector<int> &l, vector<int> &r) {

  vector<vector<int>> res(1, r);
  
  int ll = 0;
  for (int i = 0; i < l.size(); i++) {
	vector<vector<int>> tmp{};
	int something = 0;
	int j = r.size()+1;
	while ( res.size() > 0 ) {
		int start = ll;	
		int n = j;
		while (n > 0) {
			auto copy = res.back();
			copy.insert(copy.begin() + start , l[i]);	
			tmp.push_back(copy);
			start = start + 1;
			n--;
		}	
		j--;
		res.pop_back();
		something++; 
	}
	move(tmp.rbegin(), tmp.rend(), back_inserter(res));
	ll += 1;
  }
  return res;
}

vector<vector<int>> perms(vector<int> &l, vector<int> &r) {

  vector<vector<int>> res{};
  for (int i = 0; i < l.size(); i++) {
    vector<int> v{};
    int j = 0;
    while (j < i) {
      v.push_back(l[j]);
      j++;
    }
    copy(r.begin(), r.end(), back_inserter(v));
    while (j < l.size()) {
      v.push_back(l[j]);
    }
  }
  return {};
}

vector<vector<int>> magick(vector<int> &left, vector<int> &right) {
  int m = left.size();
  int n = right.size();
  vector<vector<int>> res{};
  for (int i = 1; i <= n; i++) {
    // block of n of size i
    for (int j = 0; j < m; i++) {
      // pos of block
    }
  }

  return {};
}

vector<vector<int>> get_seqs(TreeNode *root) {
  if (!root) {
    return {};
  }

  auto left = get_seqs(root->left);
  auto right = get_seqs(root->right);

  vector<vector<int>> res{};
  for (auto &vl : left) {
    for (auto &vr : right) {
      auto rest = magick(vl, vr);
      move(rest.begin(), rest.end(), back_inserter(res));
    }
  }

  for (auto &v : left) {
    v.insert(v.begin(), root->value);
  }

  return {};
}

int main() {

  vector<int> d1 {1, 2};
  vector<int> d2 {5, 6};
  auto aa = base(d1, d2);
  for ( auto v : aa ) {
	  for (auto e : v) {
		cout << e << " ";
	  }
	  cout << "\n";
  }
  return 0;
  vector<TreeNode *> ns = create_vec_nodes({5, 3, 7, 2, 4});
  create_tree(ns);
  auto ans = get_seqs(ns[0]);
  for (auto &v : ans) {
    for (auto &e : v) {
      cout << e << " ";
    }
    cout << "\n";
  }
  std::string s{};
  delete_tree(ns);
}
