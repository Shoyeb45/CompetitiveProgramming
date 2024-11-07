#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, k;


void solve() {
    cin >> n >> m >> k;

    vector<int> b(m);
    for(auto &x : b) {
        cin >> x;
    }
    vector<int> cows(n + 1, -1);
    vector<bool> hasTaken(n + 1, 0);

    for(int i = 0, c, idx; i < k; i++) {
        cin >> c >> idx;
        cows[idx] = c;
        hasTaken[c] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(cows[i] == 1) {
            cout << i << "\n";
            return;
        }
    }
    vector<int> order = cows;
    vector<bool> ht2 = hasTaken;

    int j = m - 1;
    for(int i = n; i >= 1 && j >= 0; ) {
        if(hasTaken[b[j]]) {
            while(i >= 1 && cows[i] != b[j]) {
                i--;
            }
            while(j >= 0 && hasTaken[b[j]]) {
                j--;
            }
        }
        else {
            while(i >= 1 && cows[i] != -1) {
                i--;
            }
            cows[i] = b[j--];
            i--;
        }
    }


    int ans2 = INT_MAX;

    if (count(range(b), 1)) {
       int j = 0;
       for(int i = 1; i <= n && j < m; ) {
            if(ht2[b[j]]) {
                while(i <= n && order[i] != b[j]) {
                    i++;
                }
                while(j < m && ht2[b[j]]) {
                    j++;
                }
            }
            else {
                while(i <= n && order[i] != -1) {
                    i++;
                }
                order[i++] = b[j++];
            }
       }

       for(int i = 1; i <= n; i++) {
            if(order[i] == 1) {
                ans2 = i;
                break;
            }
       }
    }

    bool toCheck = count(range(b), 1);

    if(toCheck) {
        for(int i = 1; i <= n; i++) {
            if(cows[i] == 1) {
                ans2 = min(ans2, i);
                break;
            }
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(cows[i] == -1) {
                ans2 = min(ans2, i);
                break;
            }
        }
    }

    cout << ans2 << "\n";
}

int main() {
    NFS
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}