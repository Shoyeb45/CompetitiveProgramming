#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;
#define MAX 1e6 + 1

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int f(int n) {
    int ans = 1;
    while(n >= 1) {
        int digit = n % 10;
        if(digit != 0) {
            ans *= digit;
        }
        n /= 10;
    }
    return ans;
}

int g(int n) {
    
    while(n % 10 != n) {
        int temp = f(n);
        n = temp;
    }
    return n;
}

int l, r, k;
vector<vector<int>> val(10, vector<int>(MAX, 0));

void pre_calc() {
    for(int i = 1; i <= (int)(1e6); i++) {
        int idx = g(i);
        val[idx][i]++;
    }
    
    for(int j = 1; j <= 9; j++) {
        for(int i = 1; i <= (int)(1e6); i++) {
            val[j][i] += val[j][i - 1];
        }
    }
}

void solve() {
    cin >> l >> r >> k;
    int ans = 0;
    
    cout << val[k][r] - val[k][l - 1] << '\n';
}


int main() {
    int tt;
    tt = 1;
    cin >> tt;
    pre_calc();
    while (tt--) {
        solve();
    }
    
    return 0;
}
