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

void print(string msg, vector<int> &a) {
    cout << msg << " ";
    for (auto x : a) {
        cout << x << " ";
    }
    cout << "\n";
}

// void solve() {
//     cin >> n;
//     a.resize(n);
//     for (auto &x : a) {
//         cin >> x;
//     }

//     vector<int> pref_mx(n), pref_mn(n), suff_mx(n), suff_mn(n);

//     pref_mx[0] = a.front(), pref_mn[0] = a.front(); 
//     suff_mx[n - 1] = a.back(), suff_mn[n - 1] = a.back(); 

//     for (int i = 1; i < n; i++) {
//         pref_mx[i] = max(pref_mx[i - 1], a[i]);
//         pref_mn[i] = min(pref_mn[i - 1], a[i]);

//         suff_mx[n - i - 1] = max(suff_mx[n - i], a[n - i - 1]);
//         suff_mn[n - i - 1] = min(suff_mn[n - i], a[n - i - 1]);
//     }
//     // print("pref_mx", pref_mx);
//     // print("pref_mn", pref_mn);
//     // print("suff_mx", suff_mx);
//     // print("suff_mn", suff_mn);

//     unordered_map<int, int> mp;
//     for (int i = 0; i < n; i++) {
//         mp[a[i]] = i;
//     }
//     vector<int> ans;
//     for (int i = 0; i < n; i++) {
//         if (a[i] == 1) {
//             ans.push_back(i);

//             // left side
//             int idx = i;
//             bool isMax = true;
//             while (idx != 0) {
//                 if (isMax) {
//                     idx = mp[pref_mx[idx]];
//                     ans.push_back(idx);
//                     isMax = false;
//                 }
//                 else {
//                     idx = mp[pref_mn[idx]];
//                     ans.push_back(idx);
//                     isMax = true;
//                 }
//                 // if (idx == 0) {
//                 //     break;
//                 // }
//             }

//             // right side 
//             idx = i;
//             isMax = true;
//             while (idx != n - 1) {
//                 if (isMax) {
//                     idx = mp[suff_mx[idx]];
//                     ans.push_back(idx);
//                     isMax = false;
//                 }
//                 else {
//                     idx = mp[suff_mn[idx]];
//                     ans.push_back(idx);
//                     isMax = true;
//                 }
//                 // if (idx == n - 1) {
//                 //     break;
//                 // }
//             }
//         }
//     }
//     sort(range(ans));
//     cout << ans.size() << "\n";

//     for (auto x : ans) {
//         cout << a[x] << " ";
//     }
//     cout << '\n';
// }


void solve() {
    cin >> n;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<int> ans = {a[0]};
    for (int i = 1; i < n - 1; i++) {
        if ((a[i] > a[i + 1] && a[i] > a[i - 1]) || (a[i] < a[i + 1] && a[i] < a[i - 1])) {
            ans.push_back(a[i]);
        }
    }
    
    ans.push_back(a[n - 1]);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
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
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}