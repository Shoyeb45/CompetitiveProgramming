#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

vector<vector<int>> prefixSum(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> prefSum(n, vector<int>(0, m));

    // row
    prefSum[0][0] = a[0][0];
    for(int j = 1; j < m; j++)  
        prefSum[0][j] = prefSum[0][j - 1] + a[0][j];
    // Column
    for(int i = 1; i < n; i++)  
        prefSum[i][0] = prefSum[i - 1][0] + a[i][0];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            prefSum[i][j] = (prefSum[i][j - 1] + prefSum[i - 1][j]) + a[i][j] - prefSum[i - 1][j - 1];
        }
    }

    return prefSum;
}

int findMaxSum(int n, int m, vector<vector<int>> a) {
        // code here
        if(n < 3)
            return -1;

        int x = 2, y = 2;
        vector<int> hourGlassSum;
        vector<vector<int>> pS = prefixSum(a);

        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                y += j;

                int matSum = 0;
                if(y - 3 < 0)
                    matSum = pS[x][y];
                else if(x - 3 < 0)
                    matSum = pS[x][y] - ps[x][y - 3];
                else    
                    matSum = pS[x][y] - (pS[x][y - 3] + pS[x - 3][y]) + pS[x - 3][y - 3];

                matSum -= (a[x - 1][y] + a[x - 1][y - 2]);
                hourGlassSum.push_back(matSum);
            }
            x += i;
        }
        ll ans = INT_MIN;
        for(int i = 0; i < hourGlassSum.size(); i++)
            ans = max(ans, hourGlassSum[i]);

        return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        
    }
    
    return 0;
}
