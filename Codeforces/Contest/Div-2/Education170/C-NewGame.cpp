#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, k;
vector<int> a;

int bs(vector<pair<int, ll>> &a, int x, int idx) {
    int low = idx + 1, high = a.size() - 1, ans = idx;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid].first <= x) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}

int bs(vector<pair<int, ll>> &a, int idx) {
    int low = 1, high = k - 1;
    int ans = -1;
    int x = a[idx].first;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        int idx2 = bs(a, x + mid, idx);
        if(idx2 != idx) {
            ans = idx2;
            idx = idx2;
            x = a[ans].first;
            high -= mid;
            low = 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    map<int, ll> mp;
    for(auto &x: a) {
        cin >> x;
        mp[x]++;
    }

    vector<pair<int, ll>> b;
    for(auto it: mp) {
        b.push_back(make_pair(it.first, it.second));
    }

    sort(b.begin(), b.end());
    ll ans = 0;

    vector<ll> pref(b.size());
    pref[0] = b[0].second;
    for(int i = 1; i < b.size(); i++) {
        pref[i] += pref[i - 1] + b[i].second;
    }

    for(int i = 0; i < b.size(); i++) {
        if(mp.find(b[i].first + 1) != mp.end()) {
            int idx = bs(b, i);
            if(idx == -1) {
                ans = max(ans, (ll)b[i].second);
            } 
            else {
                if(i == 0) {
                    ans = max(ans, 1ll * pref[idx]);
                }
                else {
                    ans = max(ans, 1LL * (pref[idx] - pref[i - 1]));
                }
            }
        }
        else {
            ans = max(ans, (ll)b[i].second);
        }
        // cout << idx << "\n";
    }
    cout << ans << "\n";
}


void solve(int _) {
    cin >> n >> k;
    a.resize(n);
    for(auto &x: a) {
        cin >> x;
    }

    sort(range(a)); 
    int left = 0, ans = 0;
    for(int right = 0; right < n; right++) {
        left = max(left, right);
        while(left + 1 < n && a[left + 1] <= a[left] + 1 && a[left + 1] < k + a[right]) {
            left++;
        }
        ans = max(ans, left - right + 1);
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
    cin >> tt;

    while (tt--) {
        solve(3);
    }


    return 0;
}