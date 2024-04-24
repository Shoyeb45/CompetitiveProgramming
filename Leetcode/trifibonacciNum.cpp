#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const long long mod = 1000000007;

vector<vector<int>> matMult(vector<vector<int>> &a1, vector<vector<int>> &a2) {
        int n = a1.size(), m = a2.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++ ) {
            for(int j = 0; j < m; j++) {
                for(int p = 0; p < m; p++) {
                    ans[i][j] += ((a1[i][p]) * (a2[p][j]));
                }
            }
        }
        return ans;
    }

vector<vector<int>> matPower(vector<vector<int>> &a, int n) {
            if(n == 0)
                return {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
            
            if(n == 1)
                return a;
            
            vector<vector<int>> temp = matPower(a, n/2);
            
            if(n % 2 == 1){
                vector<vector<int>> temp2 = matMult(temp, temp);
                return matMult(temp2, a);
                }
            else
                return matMult(temp, temp);
        }
 

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    vector<vector<int>> fibMat = matPower(a, n);

    for(int i = 0; i < 3 ; i++) {
        for(int j = 0; j < 3; j++) {
            cout << fibMat[i][j] << " ";
        }
        cout << endl;
    }
}