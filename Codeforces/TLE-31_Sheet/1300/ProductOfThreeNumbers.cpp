#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


ll n;
pair<int, int> check(int y, int x) {
    vector<int> div;

    for(ll i = 2; 1LL * i * i < y; i++) {
        if((y % i) == 0) {
            div.push_back(i);
            div.push_back(y / i);
        }
    }
    sort(range(div));
    for(int i = 0; i < div.size() / 2; i++) {
        if(div[i] != x && div[div.size() - i - 1] != x) {
            return { div[i], div[div.size() - i - 1] };
        }
    }

    return {-1, -1};
} 

void solve() {
    cin >> n;

    vector<int> div;
    for(ll i = 2; 1LL * i * i < n; i++) {
        if((n % i) == 0) {
            div.push_back(i);
            div.push_back(n / i);
        }
    }
    sort(range(div));

    for(int i = 0; i < div.size() / 2; i++) {
        int x = div[i], y = div[div.size() - i - 1];

        auto ans = check(x, y);
        if(ans.first != -1 && ans.second != -1) {
            cout << "YES\n" << y << " " << ans.first << " " << ans.second << "\n";
            return;
        }

        ans = check(y, x);
        if(ans.first != -1 && ans.second != -1) {
            cout << "YES\n" << x << " " << ans.first << " " << ans.second << "\n";
            return;
        }

    }
    cout << "NO\n";
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