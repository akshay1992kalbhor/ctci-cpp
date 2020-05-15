#include <iostream>
#include <string>

using namespace std;
bool is_substring(string s1, string sub1) {
	if (s1.find(sub1) != string::npos)
		return true;
	else
		return false;
}
bool str_rotation(string s1, string s2) {
	if (s1.size() != s2.size())
		return false;

	string s3 = s2 + s2;	
    return is_substring(s3, s1);
}

int main() {
	bool a1 = str_rotation("waterbottle", "erbottlewat");
	cout << "ANSWER: " << a1 << endl;
}
