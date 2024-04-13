#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll m  = 1e9+7;

vector<vector<int>> twoDPrefixSum(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> prefixSum(n, (vector<int> (m, 0)));

    prefixSum[0][0] = mat[0][0];
    // precalculating prefix sum for column and rows
    for(int i = 1; i < m; i++)  prefixSum[0][i] = prefixSum[0][i - 1] + mat[0][i];

    for(int i = 1; i < n; i++)  prefixSum[i][0] = prefixSum[i - 1][0] + mat[i][0];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            prefixSum[i][j] = (prefixSum[i - 1][j] + prefixSum[i][j - 1]) - (prefixSum[i - 1][j - 1]) + (mat[i][j]);
        }
    }
    return prefixSum;
}

int trees(vector<vector<int>> &prefixSum, int x1, int y1, int x2, int y2) {
    if(x1 == 0 && y1 == 0)  return prefixSum[x2][y2];
    else if(x1 == 0 && y1 != 0) return prefixSum[x2][y2] - prefixSum[x2][y1 -1];
    else if(x1 != 0 && y1 == 0)  return prefixSum[x2][y2] - prefixSum[x1 - 1][y2];

    return prefixSum[x2][y2] - (prefixSum[x2][y1 -1] + prefixSum[x1 - 1][y2]) + prefixSum[x1 - 1][y1 - 1];
} 

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> mat;

    loop(i, n) {
        vector<int> m;
        loop(j, n) {
            char x;
            cin >> x;
            if(x == '.')    m.push_back(0);
            else    m.push_back(1);
        }
        mat.push_back(m);
    }
    vector<vector<int>> prefixSum = twoDPrefixSum(mat);

   
    while(q--) {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = trees(prefixSum, x1 -1, y1 -1, x2 -1, y2 -1);

        cout << ans << "\n";
    }

}