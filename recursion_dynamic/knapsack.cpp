#include <vector>
#include <iostream>
using namespace std;


/*
 * sum
 * no of coins available
 * 0
 * 1
 * 2
 * 3
 */ 
//size + 1

bool possible_sum(int sum, vector<int> coins) {
    vector<vector<bool>> matrix;
    
    //for (auto b : vec0)
        //cout << b << endl;
    for (size_t i = 0; i <= coins.size(); ++i) {
        vector<bool> vec0 (sum+1, false);
        vec0[0] = true;
        matrix.push_back(vec0);
    }

    for (size_t row = 1; row <= coins.size(); ++row) {
        for (size_t col = 1; col <= sum; ++col) {
            int cur_coin = coins[row-1];
            auto with_cur = cur_coin <= col ? matrix[row-1][col - cur_coin] : false;
            auto without_cur = matrix[row-1][col];
            matrix[row][col] = with_cur || without_cur;
        }
    }

    return matrix[coins.size()][sum];

}

int main() {
    cout << possible_sum(2, {1, 3, 3, 5}) << endl;
}
