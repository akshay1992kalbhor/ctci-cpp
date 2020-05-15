#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int last_k_lines() {
	
	return 1;
}


int main() {
	string filepath;
	size_t ink;
	cin >> ink >> filepath;
	ifstream infile { filepath, ios::in };
	
	string line;
	vector<string> vec{};
	
	while (getline(infile, line))
		vec.push_back(line);
	size_t k = min(ink, vec.size());	
	for (auto i = vec.begin() + (vec.size() - k) ; i != vec.end(); ++i)
		cout << *i << '\n';
	
}
