#include <iostream>
#include <array>
#include <string>

using namespace std;

void move_forward(string& s, int sIdx, int eIdx) {
    //std::cout << "Entered\n";
    for (int t = eIdx; t >= sIdx; t--) {
        //std::cout << 1 << std::endl;
        s[t+2] = s[t];
    }
    //std::cout << s << std::endl;
}       

void urlify(string s, int l) {
    int eIdx = l-1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            // move everything forward from i+1
            move_forward(s,i+1,eIdx);
            eIdx += 2;
            s[i++] = '%';
            s[i++] = '2';
            s[i] = '0';
        }
    }
    cout << s << endl;
}

void urlify1(string s, int l) {
    
    // get the final count
    int spaces = 0;
    for (int i = 0; i < l ; i++)
        if (s[i] == ' ')
            spaces++;

    cout << spaces << endl;
    // move forward appropriately
    for (int i = l-1; i >= 0 ;i--) {
        if (s[i] != ' ') {
            int fby = spaces * 2;
            s[i+fby] = s[i];
        }
        else {
            int fby = --spaces * 2;
            s[i+fby] = '%';
            s[i+fby+1] = '2';
            s[i+fby+2] = '0';
        }
    }
    
    cout << s << endl;
}

void urlify2(string s, int l) {
    int spaces = 0;
    for (int j = 0; j < l; j++)
        if (s[j] == ' ')
            spaces++;

    int fidx = 2 * spaces + l - 1;
    for (int i = l - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            s[fidx--] = '0';
            s[fidx--] = '2';
            s[fidx--] = '%';
        } else {
            s[fidx--] = s[i];
        }
    }
    cout << s << endl;
}

int main() {
    std::string s{"Mr John00"};
    urlify(s, 7);
    urlify1(" AB C0000X"s, 5);
    urlify2(" MR John Smith000000"s, 14); 
}
