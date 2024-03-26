#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        for(int i = 0 ; i < matrix.size(); i++) {
            for(int j = i ; j < matrix[0].size(); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
          
        return matrix;
    }
int main () {
    vector<vector<int>> matrix;
    matrix.push_back({1, 4});
    matrix.push_back({-7 , -9});
    // matrix = transpose(matrix);
    for(int i = 0 ; i < 0; i++) {
        for(int j = 0 ; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}