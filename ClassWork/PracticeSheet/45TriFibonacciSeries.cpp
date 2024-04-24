#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const long long mod = 1000000007;

    vector<vector<ll>> matMult(vector<vector<ll>> &a1, vector<vector<ll>> &a2) {
        ll n = a1.size(), m = a2[0].size();
        vector<vector<ll>> ans(n, vector<ll>(m, 0));
        
        for(int i = 0; i < n; i++ ) {
            for(int j = 0; j < m; j++) {
                for(int p = 0; p < m; p++) {
                    ans[i][j] = (ans[i][j] + ((a1[i][p] % mod) * (a2[j][p] % mod)) % mod) % mod;
                }
            }
        }
        return ans;
    }

    vector<vector<ll>> matPower(vector<vector<ll>> &a, int n) {
            if(n == 0)
                return {{1, 0}, {0, 1}};
            
            if(n == 1)
                return a;
            
            vector<vector<ll>> temp = matPower(a, n/2);
            
            if(n % 2 == 1){
                vector<vector<ll>> temp2 = matMult(temp, temp);
                return matMult(temp2, a);
                }
            else
                return matMult(temp, temp);
        }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<ll>> a = {{1, 1}, {1, 0}};
    vector<vector<ll>> fibMat = matPower(a, n);

    cout << fibMat[1][0];
    return 0;
}
