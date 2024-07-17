#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;
#define MAX 3e5

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int a, b;
vector<int> xorOfNums(MAX, 0);
void precompute() {
    for(int i = 1; i < MAX; i++) {
        xorOfNums[i] = ((xorOfNums[i] ^ i) ^ xorOfNums[i - 1]);
    }
}
void solve() {
    cin >> a >> b;

    int _xor = xorOfNums[a - 1];

    if(_xor == b) {
        cout << a << '\n';
    } else {
        if((_xor ^ b == a)) {
            cout << a + 2 << '\n';
        } else {
            cout << a + 1 << '\n';
        }
    }
    cout << _xor << '\n';
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;
    precompute();
    while (tt--) {
        solve();
    }
    
    return 0;
}
