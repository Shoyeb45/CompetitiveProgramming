#include <bits/stdc++.h>
using namespace std;
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const double EPS = 1e-6; // Precision tolerance

int n, d;
vector<int> a;
int leftIdx = 0, rightIdx = 0;
bool check(double mid) {
    vector<double> pref(n, 0);
    vector<pair<double, int>> idx(n);

    idx[0] = {a[0] - mid, 0};
    pref[0] = a[0] - mid;

    for (int i = 1; i < n; i++) {
        pref[i] += pref[i - 1] + a[i] - mid;
    }

    for (int i = 1; i < n; i++) {
        if (pref[i] <= idx[i - 1].first) {
            idx[i].first = pref[i];
            idx[i].second = i;
        }
        else {
            idx[i] = idx[i - 1];
        }
    }
    for (int r = n - 1; r + 1 - d >= 0; r--) {
        cout << "r: " << r << "\n";
        if (r + 1 - d >= 0&& pref[r] >= 0) {
            leftIdx = 1, rightIdx = r + 1;
            return true;
        }
        if (idx[r - d + 1].first <= pref[r]) { 
            cout << "r - d "<<  r - d << "\n";
            leftIdx = idx[r - d + 1].second + 2, rightIdx = r + 1;
            return true;    
        }
    }
    return false;
}

void solve() {
    cin >> n >> d;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }

    double low = 0, high = 110; 
    int iter = 110;
    while (iter--) {
        double mid = (low + high) / 2;

        auto res = check(mid);
        if (res) {
            low = mid;        
        } else {
            high = mid;       
        }
    }

    cout << leftIdx << " " << rightIdx << "\n";
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

    while (tt--) {
        solve();
    }

    return 0;
}
