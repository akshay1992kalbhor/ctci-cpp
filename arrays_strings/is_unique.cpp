#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool all_unique(string s) {
    for (auto i = s.begin(); i != s.end(); i++) {
        char s1 = *i; // a, b, c
        for (auto j = i+1; j != s.end(); j++) {
            char s2 = *j; // b , c, c
            if (s1 == s2) {
                return false;
            }
        }
    } 
    return true;
}



bool all_unique1(string s) {
    vector<bool> v (128, false);
    for (auto i = s.begin(); i != s.end(); i++) {
        int idx = *i;
        if (v[idx])
            return false;
        v[idx] = true;
    }
    return true;
}

/* all_unique2: sort the string first */
bool all_unique2(string s) {
    sort(s.begin(), s.end());
    cout << s << endl;
    for (auto i = s.begin(); i != s.end() - 1; i++) {
        if (*i == *(i+1))
            return false;
    }
    return true;
}

void test_function(vector<string> in, vector<bool> out, bool(*f)(string), int fno) {
   
    cout << "Start\n"; 
    vector<bool> f1;
    for (auto s : in)
       f1.push_back(f(s));
    cout << "Done pushing\n";
    for (int i = 0; i < f1.size(); i++)
        if (f1[i] != out[i]) {
            cout << "F" << fno << is not correct\n";
            return;
        }
    cout << "F" << fno << is not incorrect\n";
}

int main() {
    vector<string> v_in {"abc", "axa"};
    vector<bool> v_out {true, false};
    test_function(v_in, v_out, all_unique);
}
