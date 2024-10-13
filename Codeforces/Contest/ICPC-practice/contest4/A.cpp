#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

int n, m, w;
vector<tuple<int, int, int>> a;

ll euclideanDist(int x1, int x2, int y1, int y2) {
    ll a = x1 - x2, b = y1 - y2;
    return (ll)(1LL * a * a + 1LL * b * b);
}

void solve() {
    cin >> n >> m >> w;

    for(int i = 0; i < w; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a.push_back(make_tuple(x, y, z));
    }

    vector<tuple<int, int, int>> temp;

    for(auto it: a) {
        int r = get<2>(it);
        int x = get<0>(it), y = get<1>(it);


        if(-r + x <= 0 || -r + y <= 0 || r + x >= n || r + y >= m) {
            temp.push_back(it);
        }

        if((-r + x <= 0 && -r + y <= 0) || 
            (r + x >= n && r + y >= m)  || (x == 0 && y == 0) || (x == n && y == m) 
        ) {
            cout << "N\n";
            return;
        }
    }


    for(auto it: temp) {
        int x1 = get<0>(it), y1 = get<1>(it), r1 = get<2>(it);

        for(auto i: temp) {
            if(i != it) {
                int x2 = get<0>(i), y2 = get<1>(i), r2 = get<2>(i);
                ll r1r2 = 1LL * (r1 + r2) * (r1 + r2);
                ll c1c2 = euclideanDist(x1, x2, y1, y2);

                if(
                    (-r1 + x1 <= 0 && -r2 + y2 <= 0) || 
                    (-r1 + x1 <= 0 && r2 + y2 >= m)  ||
                    ( r1 + x1 >= n && r2 + y2 >= m)  || 
                    (-r1 + y1 <= 0 && r2 + x2 >= n)  ||
                    (-r1 + y1 <= 0 && r2 + y2 >= m)  || 
                    (-r1 + x1 <= 0 && r2 + x2 >= n) 
                ) {
                    if((r1r2 == c1c2) || (r1r2 > c1c2 && r1r2 > abs(r1 - r2))) {
                        cout << "N\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "S\n";
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
        solve();
    }

    return 0;
}
