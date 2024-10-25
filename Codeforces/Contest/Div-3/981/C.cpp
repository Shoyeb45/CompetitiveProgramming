#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
vector<int> a;
void solve() {
    cin >> n;
    a.resize(n);

    for(auto &x: a) {
        cin >> x;
    }

    if(n == 2) {
        cout << (a[0] == a[1]? 1: 0) << "\n";
        return;
    }

    for(int i = 0; i < n / 2; i++) {
        if(a[i] == a[n - i - 1]) {
            continue;
        }

        int j = n - i - 1;
        int temp[2] = {0};

        if(a[i] == a[i + 1]) {
            temp[0]++;
        }
        if(i >= 1 && a[i] == a[i - 1]) {
            temp[0]++;
        }
        if(j <= n - 2 && a[j] == a[j + 1]) {
            temp[0]++;
        }
        if(a[j] == a[j - 1]) {
            temp[0]++;
        }
        swap(a[i], a[j]);

        if(a[i] == a[i + 1]) {
            temp[1]++;
        }
        if(i >= 1 && a[i] == a[i - 1]) {
            temp[1]++;
        }

        if(j <= n - 2 && a[j] == a[j + 1]) {
            temp[1]++;
        }
        if(a[j] == a[j - 1]) {
            temp[1]++;
        }

        if(temp[0] < temp[1]) {
            swap(a[i], a[j]);
        }
    }


    int ans = 0;

    for(auto x: a) {
        cout << x << " ";
    }
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    NFS
     #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}