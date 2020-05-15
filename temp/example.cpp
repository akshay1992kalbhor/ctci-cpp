#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


void replace_and_print() {
    string s {"a#>b#>c"};
    while (s.find("#") != string::npos) {
        s.replace(s.find("#>"), 2, "");
    }
    cout << s << "\n";
}

void read_and_print() {
    ifstream infile {"example.txt"};
    int a, b = 0;
    while (infile >> a >> b)
        cout << "Read: " << a << ", " << b << "\n";
}

void read_and_print1() {
    ifstream infile {"example.txt"};
    string s;
    int last = -1;
    int start = 0;
    // akshay 23 100.50
    while (getline(infile, s)) {
        while (s.find(" ") != string::npos) {
            last = s.find(" ");
            string p = s.substr(start, last-start);
            s = s.substr(last+1);
            cout << "Read: " << p << "\n";
            cout << "Mod: " << s << "\n";
        }
        cout << "Read last: " << s << "\n";
    }
}

int main() {
    //read_and_print1();
    vector<vector<int>> graph {{1, 2}, {0}, {0}};
    cout << graph[0][0] << endl;
}
