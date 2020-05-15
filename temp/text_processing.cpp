#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<tuple<int,int>,int> m;
    ifstream infile{"example.txt"};
    string line;
    while( getline(infile, line) ) {
        int atidx = line.find("@");
        string username = line.substr(0,atidx);
        string host = line.substr(atidx+1);
        cout << username << endl;
        cout << host << endl;
    }
}
