#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


/// Using map : time complexity -> O(nlogn)
void solveNLogN() {
    int n;
    ll k;
    map<ll, int> mp;
    vector<ll> a;

    cin >> n >> k;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }     

    int left = 0;
    ll ans = 0, mn = 0, mx = 0;

    auto good = [&](ll mn, ll mx) -> bool {
        return mp.empty()? false: mx - mn <= k;
    };

    auto add = [&] (int index) {
    mp[a[index]]++;
    };

    auto update = [&](ll &mn, ll &mx) {
        if(!mp.empty()) {
            mn = mp.begin() -> first, mx = mp.rbegin() -> first;
        }
    };

    auto remove = [&](int index) {
        mp[a[index]]--;
        if(mp[a[index]] == 0) {
            mp.erase(mp.find(a[index]));
        }
    };

    for(int right = 0; right < n; right++) {
        add(right);
        update(mn, mx);

        while(left < n && !good(mn, mx)) {
            remove(left++);
            update(mn, mx);
        }
        ans += right - left + 1;
    }
    cout << ans << "\n";
}

/// Using deque and observation : time complexity -> O(n)
void solveN() {
    int n;
    ll k;
    vector<ll> a;

    cin >> n >> k;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    deque<ll> for_mn, for_mx;

    auto add = [&](int idx) {
        while (!for_mn.empty() && a[idx] < for_mn.back()) {
            for_mn.pop_back();
        }
        for_mn.push_back(a[idx]);

        while (!for_mx.empty() && a[idx] > for_mx.back()) {
            for_mx.pop_back();
        }
        for_mx.push_back(a[idx]);
    };

    auto remove = [&](int idx) {
        if (a[idx] == for_mn.front()) {
            for_mn.pop_front();
        }

        if (a[idx] == for_mx.front()) {
            for_mx.pop_front();
        }
    };

    ll ans = 0;

    for (int left = 0, right = 0; right < n; right++) {
        add(right);

        while (left <= right && for_mx.front() - for_mn.front() > k) {
            remove(left++);
        }

        ans += right - left + 1;
    }   

    cout << ans << "\n";
}

int main() {
    NFS
    #ifndef ONLINE_JUDGE
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
        freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    #endif

    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solveN();
    }


    return 0;
}