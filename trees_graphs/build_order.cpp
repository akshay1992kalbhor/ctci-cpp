#include <unordered_map>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include <set>
using namespace std;

void fill_up(unordered_map<string, vector<string>>& dg, vector<tuple<string, string>>& deps) {
	// every entry = "a":["b", "c"]
	for (tuple<string, string>& t : deps) {
		
		string& possible_key = get<1>(t);
		
		if (dg.find(possible_key) != dg.end()) {
			
			//vec present
			cout << "P: " << possible_key << endl;
			dg[possible_key].push_back(get<0>(t));
		} else {
			
			cout << "N: " << possible_key << endl;
			dg[possible_key] = vector<string>{get<0>(t)};
		}
	}
}

bool loop_found(const string& start_node, const unordered_map<string, vector<string>>& dg) {
	vector<string> q {start_node};
	set<string> seen {start_node};
	while (!q.empty()) {
		string cnode = q.back();
		q.pop_back();	
		
		const vector<string>& ns = dg.at(cnode);
		for (const string& s : ns) {
			if (seen.find(s) != seen.end()) {
				return true;	
			} else {
				seen.insert(s);
				q.push_back(s);
			}		
		}
	}
	return false;
}

bool is_valid_build_order(unordered_map<string, vector<string>>& dg) {
	for (pair<const string,vector<string>>& what : dg) {
		const string& k = what.first;	
		const vector<string>& n = what.second;
		if (loop_found(k, dg)) {
			return false;
		}
	}
	return true;
}



int main(int argc, char* argv[]) {

	vector<string> projects {"a", "b", "c", "d", "e"};

	vector<tuple<string, string>> deps {make_tuple("c", "f"), make_tuple("a", "d"), make_tuple("f", "b"), make_tuple("b", "d"), make_tuple("f","a"), make_tuple("d", "c")};

	unordered_map<string, vector<string>> dg;

	fill_up(dg, deps);

	for (pair<const string, vector<string>>& p : dg) {
		cout << "K: " << p.first;
		cout << " V: [";
		for (string& s : p.second) {
			cout << " " << s;
		}
		cout << " ]\n";
	}

	bool answer = is_valid_build_order(dg);
	cout << "Ans: " << boolalpha << answer << endl;
}
