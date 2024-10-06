#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, q;
vector<int> a;

bool bs(vector<pair<int, int>> &a, int target, int index) {
    int high = a.size(), low = 0;
    
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid].first == target && a[mid].second != index) {
            return true;
        }
        else if(a[mid].first > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return false;
}
void solve() {
    cin >> n >> m >> q;
    a.resize((int)2 * n + 1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, j = n;

    // vector<pair<int, int>> tempb;
    // unordered_set<int> b;
    vector<int> b(m);
    map<int, int> mp;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        mp[b[i]] = i;
    } 

  
    // sort(range(tempb));
    for(int k = 0; k < m ; ) {
        // debug("ai", a[i]);
        // debug("bi", b[k]);
        if(a[i] != b[k]) {
            cout << "TIDAK\n";
            return;
        }
        int c = b[k];
        while(k < m && b[k] == c) {
            k++;
        }
        if(mp[c] == k - 1) {
            a[j++] = a[i++];
        }
        else {
            swap(a[i], a[i + 1]);
        }
        // k++;    
        // for(int d = i ; d < j; d++) {
        //     cout << a[d] << " ";
        // }
        // cout << "\n";
    }
    cout << "YA\n";
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