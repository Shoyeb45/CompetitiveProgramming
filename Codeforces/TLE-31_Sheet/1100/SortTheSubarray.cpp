#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a, b;
void solve() {
    cin >> n;
    a.resize(n), b.resize(n);
    for(auto &x: a) {
        cin >> x;
    }
    for(auto &x: b) {
        cin >> x;
    }

    int mxLen = 0, l = 0, r = 0;
    int i = 0;
    while(i < n - 1) {
        if(b[i] <= b[i + 1]) {
            int initI = i, cnt = 0;
            while(i < n - 1 && b[i] <= b[i + 1]) {
                i++;
                cnt += (b[i] != a[i]);
            }

            if(i - initI + 1 > mxLen && cnt >= 1) {
                mxLen = i - initI + 1;
                l = initI, r = i;
            }
        }
        else {
            i++;
        }
    } 

    cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }


    return 0;
}