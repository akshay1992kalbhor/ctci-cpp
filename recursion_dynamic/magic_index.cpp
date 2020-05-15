#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
/*
A = [1,2,3,4,5], [-1, 0, 1, 4, 5] [4, 10, 11], [-1, 0, 1], [-10, -4, -1]

Easiest soln: O(n)
O(log(n)): binary search type?
*/

int magic_index_distinct(vector<int> vec) {
    
    if (vec.empty())
        return -1;

    int low = 0;
    int high = vec.size()-1;
    while(low <= high) {
        int mid = (low + high) / 2;
        //cout << mid << endl;
        if (vec[mid] == mid) {
            return mid;
        } else if (vec[mid] > mid) {
            // discard rhs
            high = mid-1;
        } else {
            // discard lhs
            low = mid+1;
        }
    }
    return -1;
}

// [1, 2, 5, 5, 5]
// [1, 2, 4, 4, 4]
// [1, 2, 3, 3, 4]
// [-10, 1]
int magic_index(vector<int> vec) {
    
    if (vec.empty()) { 
        return -1; 
    }
    /*
    for (auto iter = vec.begin(); iter != vec.end(); iter++) {
        
    }*/

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == i) {
            return i;
        } else if (vec[i] > i) {
            int diff = vec[i] - i;
            if (diff > 1) {
                i+=(diff-1);
            }   
        } else {
            
        }
    }
    return -1;
}

int main() {

    vector<int> v1{3,2,1};
    vector<int>&& v = vector<int>{1, 2, 3};
    vector<int>&& rv = v1;


    //A = [1,2,3,4,5], [-1, 0, 1, 4, 5] [4, 10, 11], [-1, 0, 1], [-10, -4, -1]
    for (auto& v : initializer_list<initializer_list<int>>{{-1,1,3,4,5}, {1,2,3}, {-1,0,1,3,5}}) {
        cout << magic_index(v) << endl;
    } 
}
