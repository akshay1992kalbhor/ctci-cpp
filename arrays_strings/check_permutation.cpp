#include <iostream>
#include <string>
#include <vector>


using namespace std;

#include <map>

bool check_perm(string s1, string s2) {
    /* edge cases */
    if (s1.size() != s2.size()) {
        cout << s1 << " & " << s2 << "; Ans: 0" << endl;
        return false;
    }

    map<char, int> m;
    for (int i = 0; i < s1.size(); i++) {
        char key1 = s1[i];
        char key2 = s2[i];
        if (m.find(key1) != m.end()) {
            // already in
            m[key1] += 1;
            if ( m[key1] == 0 )
                m.erase(key1);
        } else {
            m[key1] = 1;
        }

        if (m.find(key2) != m.end()) {
            m[key2] -= 1;
            // add some steps
            if (m[key2] == 0)
                m.erase(key2);
        } else {
            m[key2] = -1;
        }
    }
    cout << s1 << " & " << s2 << "; Ans: " << m.empty() << endl;
    return m.empty();
}

bool check_perm1(string s1, string s2) {
    cout << s1 << ", " << s2 << endl;  
    if (s1.size() != s2.size()) {
        cout << "A: 0\n";
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (auto i1 = s1.begin(), i2 = s2.begin(); i1 != s1.end() && i2 != s2.end(); i1++, i2++)
        if (*i1 != *i2) {
            cout << "A: 0\n";
            return false;
        }
    cout << "A: 1\n"; 
    return true;
}

int main() {

    bool a1 = check_perm1("AbCde"s, "edACb"s);
    bool a2 = check_perm1("abcde"s, "edacbz"s);
    bool a3 = check_perm1("abcdez"s, "edacb"s);
    bool a4 = check_perm1("aBc"s, "abc"s);

}
