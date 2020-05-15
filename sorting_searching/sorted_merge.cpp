#include <iostream>
#include <vector>
using namespace std;



void shift_by_one(vector<int>& array, int idx) {
    for (int j = array.size()-1; j > idx ;j--) {
        array[j] = array[j-1];
    }
}
/* assuming just enough space */
void sorted_merge(vector<int>& A, vector<int>& B) {
    
    int indexA = 0;
    int indexB = 0;

    int nelems_in_A = A.size() - B.size();
    int elems_placed = 0;
    // how do we figure out if all elems from A have found their proper place
    while (indexB < B.size() && elems_placed < nelems_in_A) {
        // we need to place A.size() elements in A
        
        // compare two elements
        if (A[indexA] > B[indexB]) {
            shift_by_one(A, indexA);
            A[indexA] = B[indexB];
            indexA++; indexB++;
        } else {
            indexA++;
            elems_placed++;
        }
    }

    // check if b has any elements left
    while (indexB < B.size()) {
        A[indexA] = B[indexB];
        indexA++; indexB++;
    }
}


int main() {
    vector<int> A {3, 5, 7, 0, 0, 0};
    vector<int> B {1, 4, 10};
    //shift_by_one(A, 1);
    sorted_merge(A, B);
    for (auto e : A) {
        cout << e << endl;
    }
}
