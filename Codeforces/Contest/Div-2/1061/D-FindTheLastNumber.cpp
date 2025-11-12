#include<bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "algo/debug.h"
// #else
// #define debug(...) 42
// #endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int k;
bool ask(int pos, int x) {
    cout << "? " << pos << " " << x << endl;
    int bit;
    cin >> bit;
    return (bool) bit;
}

int get_num(int pos) {
    int num = 0;x
    for (int i = 0; i < k; i++) {
        bool is_bit_present = ask(pos, (1 << i));
        if (is_bit_present) {
            num = (num | (1 << i));
        }
    }
    return num;
}


void solve() {
    int n;
    cin >> n;
    k = (int) log2(n) + 1;
    set<int> p;

    for (int i = 1; i < n; i++) {
        p.insert(get_num(i));
    }

    for (int i = 1; i <= n; i++) {
        if (p.find(i) == p.end()) {
            cout <<"! " <<  i << endl;
            return;
        }
    }
}

int main() {
    NFS
   
    int tt;
    tt = 1;
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        solve();
    }

    return 0;
}