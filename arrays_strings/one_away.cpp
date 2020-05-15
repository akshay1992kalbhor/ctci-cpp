#include <iostream>
#include <string>
using namespace std;

bool chk_for_add(string s1, string s2) {
    bool added_seen = false;
    
    for (int i = 0, j = 0; i < s1.size(); i++, j++) {
        if (s1[i] != s2[j]) {
            if (added_seen) {
                return false;
            } else {
                added_seen = true;
                j = j + 1;
            }
        }
    }

    return true;
}

bool chk_for_replace(string s1, string s2) {
    bool replaced_seen = false;
    
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            if (replaced_seen) {
                return false;
            } else {
                replaced_seen = true;
            }
        }
    }

    return true;
}

bool one_away(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();

    if (l1 == l2) {
        return chk_for_replace(s1, s2);
    } else if (l1 - l2 == 1) {
        return chk_for_add(s2, s1);
    } else if (l2 - l1 == 1) {
        return chk_for_add(s1, s2);
    } else {
        return false;
    }
}


int main() {
    bool ans = one_away("pale", "aple");
    cout << ans << endl;
}
