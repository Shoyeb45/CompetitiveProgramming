#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }

#include<bits/stdc++.h>

using ll = long long;
const ll mod = 10000003;
int paint(int A, int B, vector<int> &C) {
    int n = C.size();
    vector<ll> arr(C.size());
    for (int i = 0; i < C.size(); i++) {
        arr[i] = 1LL * C[i] * B;
    }
    
    ll low = *max_element(arr.begin(), arr.end()), high = 1LL * accumulate(arr.begin(), arr.end(), 0LL);
    ll ans = 0;
    
    auto check = [&] (ll mid) -> bool {
        int cnt = 1;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum > mid) {
                cnt++;
                sum = arr[i];
            }
            if (cnt > A) {
                return false;
            }
        }
        return true;
    };
    // debug("check", check(12890));
    
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
    return ans % mod;
}


int main() {
    NFS
     #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    #endif
   
    int n, workers, time;
    cin >> n >> workers >> time;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    cout << paint(workers, time, a);
    return 0;
}