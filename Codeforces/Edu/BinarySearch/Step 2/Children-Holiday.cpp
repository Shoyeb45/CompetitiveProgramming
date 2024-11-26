#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
using ll = long long;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const int mod = 1000000007;

ll n, m;
vector<ll> t, numOfBallons, restTime;

bool check(ll mid) {
    ll ballon = 0;

    for (int i = 0; i < n; i++) {
        ll cycleTime = 1LL * t[i] * numOfBallons[i] + restTime[i];
        ballon += (mid / cycleTime) * 1LL * numOfBallons[i] + min ((mid % (cycleTime)) / t[i], numOfBallons[i]);
    }
    return ballon >= m;
}

void solve() {
    cin >> m >> n;
    t.resize(n), numOfBallons.resize(n), restTime.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> numOfBallons[i] >> restTime[i];
    }    
    ll low = 0, high = 1e9, ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }

    ll ballons = 0;
    cout << ans << "\n";
    for (int i = 0; i < n; i++) {
        if (ballons >= m) {
            cout << 0 << " \n"[i == n - 1];
        }
        else {
            ll cycleTime = 1LL * t[i] * numOfBallons[i] + restTime[i];
            ll currBallon = ans / cycleTime * 1LL * numOfBallons[i] + min ((ans % (cycleTime)) / t[i], numOfBallons[i]);
            if (currBallon > m - ballons) {
                cout << m - ballons << " \n"[i == n - 1];
            }
            else {
                cout << currBallon << " \n"[i == n - 1];
            }
            ballons += currBallon;
        }
    }
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}