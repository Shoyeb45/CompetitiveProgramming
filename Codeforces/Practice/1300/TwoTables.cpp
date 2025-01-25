#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


// bl - Bottom Left, tr - Top Right
bool isIntersect(int bl_ax, int bl_ay, int tr_ax, int tr_ay, int bl_bx, int bl_by, int tr_bx, int tr_by) {
    return tr_ax <= bl_bx || tr_bx <= bl_ax || bl_by >= tr_ay || bl_ay >= tr_by;
}



void solve() {
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    {
        int ax1 = 0, ay1 = 0, ax2 = w, ay2 = h;
        int _h = max(y2, y1) - min(y1, y2) , _w = max(x2, x1) - min(x1, x2);
        int bx2 = W, by2 = H, bx1 = W - _w, by1 = H - _h;
        if(!isIntersect(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)) {
            cout << -1 << "\n";
            return;
        }
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
    // cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}