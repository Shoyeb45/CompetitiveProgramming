#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n;
void solve() {
    cin >> n;
    
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    } 
    map<int, set<int>> mp;

    for (int i = 0, k; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x; 
            cin >> x;
            mp[i].insert(x);
        }
    }
    vector<int> ans(n);

    map<int, int> assigned;

    sort(a.rbegin(), a.rend());

    for (int i = 0; i < n; i++) {
        int index = a[i].second;
        
        for (auto x: mp[index]) {
            // if not assigned yet
            if (assigned.find(x) == assigned.end()) {
                ans[index] = x;
                assigned[x] = index;
            } else {
                int assignedIndex = assigned[x];

                for (auto y: mp[assignedIndex]) {
                    if (assigned.find(y) == assigned.end()) {
                        // found new answer
                        ans[assignedIndex] = y;
                        assigned[y] = assignedIndex;
                        
                        ans[index] = x;
                        assigned[x] = index;
                    }
                }
            }
        }

    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    // cout << "\n";
}

int main() {
    NFS
    //  #ifndef ONLINE_JUDGE
    //     freopen("beloved.in", "r", stdin);
    //     freopen("beloved.out", "w", stdout);
    // #endif
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}