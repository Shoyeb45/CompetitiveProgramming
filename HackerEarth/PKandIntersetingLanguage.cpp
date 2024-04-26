#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

vector<vector<int>> matMult(vector<vector<int>> &a1, vector<vector<int>> &a2) {
    int n = a1.size(), m = a2[0].size();
    vector<vector<int>> ans(n, vector<int>(m, 0));
        
    for(int i = 0; i < n; i++ ) 
        for(int j = 0; j < m; j++) 
            for(int p = 0; p < m; p++) 
                ans[i][j] += ((a1[i][p]) * (a2[j][p]));
                
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
    } else
        return matMult(temp, temp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> A(26, vector<int>(26, 0));

    for(int i = 0; i < 26; i++) {
        loop(j, 26) {
            cin >> A[i][j];
        }
    }

    int t;
    cin >> t;
    
    while(t--) {
        char c;
        int l;
        cin >> c >> l;
    }
    return 0;
}
