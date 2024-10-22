#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


int n, k, a1, a2, b1, b2;

int nextPos(int i) {
    if(i >= a1 && i <= a2) {
        i = a1 + a2 - i; 
    }
    if(i >= b1 && i <= b2) {
        i = b1 + b2 - i;
    }
    return i;
}

void solve() {
    cin >> n >> k >> a1 >> a2 >> b1 >> b2;

    vector<int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        int x = 1, currPos = nextPos(i);
        while(currPos != i) {
            x++, currPos = nextPos(currPos);
        }
        int temp = k % x;
        for(int j = 0; j < temp; j++) {
            currPos = nextPos(currPos);
        }
        ans[currPos] = i;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    NFS
    string file = "swap";
    // #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    // #endif
        freopen((file + ".in").c_str(), "r", stdin);
        freopen((file + ".out").c_str(), "w", stdout);

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}