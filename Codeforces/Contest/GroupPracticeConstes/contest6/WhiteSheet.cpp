#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;

class Rectangle {
public:
    int x1;
    int x2;
    int y1;
    int y2;

    Rectangle() {
        cin >> x1 >> y1 >> x2 >> y2; 
        x1 *= 2;
        x2 *= 2;
        y1 *= 2;
        y2 *= 2;
    }

    bool isOutside(int x, int y) {
        return x < x1 || x > x2 || y < y1 || y > y2;
    }
};

void solve() {
    Rectangle w;    
    Rectangle b1;    
    Rectangle b2;    

    for(int x = w.x1; x <= w.x2; x++) {
        if(b1.isOutside(x, w.y1) && b2.isOutside(x, w.y1)) {
            cout << "YES\n";
            return;
        }
        if(b1.isOutside(x, w.y2) && b2.isOutside(x, w.y2)) {
            cout << "YES\n";
            return;
        }
    }

    for(int y = w.y1; y <= w.y2; y++) {
        if(b1.isOutside(w.x1, y) && b2.isOutside(w.x1, y)) {
            cout << "YES\n";
            return;
        }
        if(b1.isOutside(w.x1, y) && b2.isOutside(w.x1, y)) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
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