#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int w, h;
    cin >> w >> h;
    int x_c, y_c;
    cin >> x_c >> y_c;
    int r;
    cin >> r;
    // int x1, y1, x2, y2;
    // cin >> x1 >> y1 >> x2 >> y2;

    loop(x, h) {
        loop(y, w) {
            double x_d = x - x_c;
            double y_d = y - y_c;
            if(x_d * x_d + y_d * y_d <= r * r) {
                cout << "#" ;
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    
    return 0;
}
