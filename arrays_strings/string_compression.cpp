#include <iostream>
#include <string>

using namespace std;

string compress_string(string s) {
    if (s.empty()) {
	return s;
    }
    char lseen = s[0]; 
    int n = 1;
    string ret {""};
    for (int i = 1; i < s.size(); i++) {
	if (s[i] != lseen) {
	    if (n > 1) { 
		ret = ret + lseen + to_string(n); 
	    } else {
		ret = ret + lseen;
	    }
	    lseen = s[i];
	    n = 1;
	} else {
	    n += 1;
	}
    }
    if (n > 1) {
        ret = ret + lseen + to_string(n);
    } else {
	ret = ret + lseen;
    }
    return ret;
}

int main() {
    string comp_str = compress_string("abcde");
    cout << comp_str << endl;
}
