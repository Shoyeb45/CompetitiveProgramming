#include<bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
using namespace std;
#define range(x) (x).begin(), (x).end()
#define rrange(x) (x).rbegin(), (x).rend()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int w, h, eye_a, mouth_a;
    cin >> w >> h >> eye_a >> mouth_a;
    
    auto f = [&](int x, int y) -> double {
        double t1 = pow((double) (2 * x) / w, 2), t2 = pow((double) (2 * y) / h, 2);
        return t1 + t2;
    };
    auto is_inside_ellipse = [&](int x, int y) -> bool {
        double res = f(x, y);
        return res < 1.0 - DBL_EPSILON;
    };

    auto check_eye = [&](int width, int height) -> bool {
        int x1 = 1, y2 = 1;
        int y1 = height + y2, x2 = width + x1;
        if (is_inside_ellipse(x1, y1) && is_inside_ellipse(x2, y2) && is_inside_ellipse(x2, y1) && is_inside_ellipse(x1, y2)) { 
            cout << -x2 << " " << y1 << " " << -x1 << " " << y2 << "\n"; // left eye
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n"; // right eye
            return true;
        }
        return false;
    };
    
    auto check_mouth = [&](int width, int height) -> bool {
        int y1 = -1, y2 = y1 - height;
        int x1, x2;
        if (width % 2 == 0) {
            x1 = -width / 2, x2 = -x1;
        } else {
            x2 = width / 2, x1 = -(x2 + 1);
        }
     
        if (is_inside_ellipse(x1, y1) && is_inside_ellipse(x2, y2) && is_inside_ellipse(x2, y1) && is_inside_ellipse(x1, y2)) { 
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n"; // mouth
            return true;
        }
        return false;
    };
    for (int i = 1; i * i <= eye_a; i++) {
        if (eye_a % i == 0) {
            int width = i, height = eye_a / i;
            swap(width, height);
            if (check_eye(height, width)) {
                break;
            }
            if (check_eye(width, height)) {
                break;
            }
            
        }
    }
    
    for (int i = 1; i * i <= mouth_a; i++) {
        if (mouth_a % i == 0) {
            int width = i, height = mouth_a / i;
            if (check_mouth(height, width)) {
                break;
            }
            if (check_mouth(width, height)) {
                break;
            }
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
    cin >> tt;

    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ":\n";
        solve();
    }

    return 0;
}