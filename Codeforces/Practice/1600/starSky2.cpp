#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int cnt[11][101][101];

void preprocess(int c) {

    loop(p, c + 1) {
        for(int i = 1; i <= 100; i++) {
            for(int j = 1; j <= 100; j++) {
                cnt[p][i][j] += cnt[p][i - 1][j] + cnt[p][i][j - 1] - cnt[p][i - 1][j - 1];
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, c;
    cin >> n >> q >> c;

    loop(i, n) {
        int x, y, b;
        cin >> x >> y >> b;
        cnt[b][x][y]++;
    }
    preprocess(c);

    while(q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll sum = 0;
        for(int p = 0; p <= c; p++) {
            int brightness = (p + t) % (c + 1);
            int numOfStars = cnt[p][x2][y2] - cnt[p][x2][y1 - 1] - cnt[p][x1 - 1][y2] + cnt[p][x1 - 1][y1 - 1];
            sum +=brightness * numOfStars;
        }
        cout << sum << '\n';
    }
    
    return 0;
}
