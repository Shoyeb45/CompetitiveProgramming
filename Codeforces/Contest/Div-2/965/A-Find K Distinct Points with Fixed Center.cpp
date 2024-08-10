#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int x, y, k;
void solve() {
    cin >> x >> y >> k;
    
    if(k == 1) {
        cout << x << " " << y << '\n';
    } else {
        vector<int> xCoor(k), yCoor(k);
        
        if(k % 2 == 1) {
            xCoor[0] = x * k;
            yCoor[0] = y * k;
            int assign = 1e6;
            int i = 1;
            loop(j, (k - 1) / 2) {
                xCoor[i++] = assign;
                xCoor[i++] = -assign;
                assign--;
            }

            assign = 1e7;
            i = 1;
            loop(j, (k - 1) / 2) {
                yCoor[i++] = assign;
                yCoor[i++] = -assign;
                assign--;
            }
        } else {
            xCoor[0] = 1, xCoor[1] = x * k - 1;
            yCoor[0] = 1, yCoor[1] = y * k - 1;

            int assign = 1e6;
            int i = 2;
            loop(j, (k - 2) / 2) {
                xCoor[i++] = assign;
                xCoor[i++] = -assign;
                assign--;
            }
            assign = 1e7, i = 2;

            loop(j, (k - 2) / 2) {
                yCoor[i++] = assign;
                yCoor[i++] = -assign;
                assign--;
            }
        }
        loop(i, k) {
            cout << xCoor[i] << " " << yCoor[i] << '\n';
        }
    }
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}
