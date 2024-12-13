#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    vector<int> a = {4, 8, 15, 16, 23, 42};

    unordered_map<int, pair<int, int>> mp;

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            mp[a[i] * a[j]] = {a[i], a[j]};
        }
    }   
    vector<int> ans;

    int res1 = ask(1, 2), res2 = ask(1, 3);
    int x = mp[res1].first, y = mp[res1].second, z = mp[res2].first, w = mp[res2].second;


    vector<int> temp = {x, y};
    if (z == x || z == y) {
        temp.push_back(w);
    } 
    else {
        temp.push_back(z);
    }
    ans = temp;
    if (temp[0] * temp[2] != res2) {
        swap(ans[0], ans[1]);
    }

    for (int i = 4; i <= 5; i++) {
        res1 = ask(i - 1, i);
        x = mp[res1].first, y = mp[res1].second;
        if (x == ans.back()) {
            ans.push_back(y);
        }
        else {
            ans.push_back(x);
        }
    }

    for (auto x : a) {
        if (count(range(ans), x) == 0) {
            ans.push_back(x);
            break;
        }
    }

    cout << "! ";
    for (int i = 0; i <= 5; i++) {
        cout << ans[i] << " \n"[i == 5];
    }
}

int main() {
    NFS
    //  #ifndef ONLINE_JUDGE
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\input.in", "r", stdin);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\output.out", "w", stdout);
    //     freopen("E:\\Code\\CompetitveProgramming\\stdin-stdout-stderr\\error.out", "w", stderr);
    // #endif
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}