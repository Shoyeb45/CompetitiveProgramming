#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int mapSky[11][101][101];
vector<pair<int, int>> startPos;

// void preProcess(int c) {
//     for(int i = 1; i <= c; i++) {
//         for(auto &coordinate: startPos) {
//             mapSky[i][coordinate.first][coordinate.second] = mapSky[i - 1][coordinate.first][coordinate.second] + 1;
//             if(mapSky[i][coordinate.first][coordinate.second] > c) {
//                 mapSky[i][coordinate.first][coordinate.second] = 0;
//             }
//         }
//     }
// }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, c;
    cin >> n >> q >> c;

    loop(i, n) {
        int x, y, b;
        cin >> x >> y >> b;
        startPos.push_back({x, y});
        
        loop(i, 11) {
            mapSky[t][x][y] += b;
            b = (b + 1) % (c + 1);
        }
        // mapSky[0][x][y] += b;
        // if(mapSky[0][x][y] > c)
        //     mapSky[0][x][y] = 0;
    }
    // preProcess(c);
    
    while(q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t = t % (c + 1);
        
        ll sum = 0;
        for(int i = x1; i <= x2; i++) {
            for(int j = y1 ; j <= y2; j++) {
                sum += mapSky[t][i][j];
            }
        }

        cout << sum << '\n';
    }
    return 0;
}
