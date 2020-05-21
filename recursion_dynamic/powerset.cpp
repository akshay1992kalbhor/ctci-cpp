#include <iostream>
#include <vector>
using namespace std;

void pvec(vector<int>& v) {
  cout << "{ ";
  for (auto &e : v) {
    cout << e << " ";
  }
  cout << "}\n";
}

vector<vector<int>> subsets(const vector<int>& nums) {

  vector<vector<int>> v{{}};
  vector<vector<int>> tmp{};

  for (auto &num : nums) {
    for (vector<int> prev : v) {
      prev.push_back(num);
      tmp.push_back(prev);
    }
    move(tmp.begin(), tmp.end(), back_inserter(v));
    tmp.clear();
  }
  return move(v);
}



vector<int> move_out(vector<int>& ref) {
	//vector<int> mout = move(ref);
	return move(ref);
}

int main() { 
	
	auto answer = subsets({1, 2, 3});
	for (auto& v : answer) {
		pvec(v);
	}
}
