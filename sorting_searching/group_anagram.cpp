#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool comp(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a.compare(b) < 0;
}
void group_anagrams(vector<string>& vec) {
		
	sort(vec.begin(), vec.end(), comp);
}




int main() {

	vector<string> in {"abc","zd", "Abc", "azd", "des", "bca", "abC", "bAc"};
	vector<string> in1 {"a", "A", "B"};
	group_anagrams(in1);
	for (auto& s : in1)
		cout << s << endl;
}
