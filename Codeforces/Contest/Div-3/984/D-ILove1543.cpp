#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
template<typename T> void debug(string v1, T t1) { cout << v1 << ": " << t1 << "\n"; }
template<typename T, typename K> void debug(string v1, T t1, string v2, K t2) { cout << v1 << ": " << t1 << " " << v2 << ": " << t2 << "\n"; }
const ll mod = 1000000007;


int n, m;
vector<string> a;

pair<int, int> next(int i, int j, int &direction, int n, int m, int in, int im) {
    if(direction == 1) {
        // Right
        if(j == m) {
            direction = 2;
            return {i + 1, j};
        }
        else {
            return {i, j + 1};
        }
    } 
    else if(direction == 2) {
        // down
        if(i == n) {
            direction = 3;
            return {i, j - 1};
        }
        else {
            return {i + 1, j};
        }
    }
    else if(direction == 3) {
        // left
        if(j == im) {
            direction = 4;
            return {i - 1, j};
        }
        else {
            return {i, j - 1};
        }
    }
    else {
        // up
        if(i == in) {
            direction = 1;
            return {i , j + 1};
        }
        else {
            return {i - 1, j};
        }
    }
}

char checkChar(pair<int, int> ind) {
    return a[ind.first][ind.second];
}

void print(pair<int,int> p) {
    cout << p.first << " " << p.second << "\n";
}
bool is1543(pair<int, int> ind, int &direction, int n, int m, int in, int im ) {

    int temp1 = direction;
    auto it = next(ind.first, ind.second, temp1, n, m, in, im);

    auto it2 = next(it.first, it.second, temp1, n, m, in, im);
    auto it3 = next(it2.first, it2.second, temp1, n, m, in, im);

    return checkChar(it) == '5' && checkChar(it2) == '4' && checkChar(it3) == '3';
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }   

    int startRow = 0, endRow = n - 1, startCol = 0, endCol = m - 1;

    int ans = 0;

    while(endRow >= startRow && endCol >= startCol) {
        pair<int, int> start = {startRow, startCol};
        auto it = start;
        int direction = 1;

        do {    
            if(a[it.first][it.second] == '1') {
                ans += is1543(it, direction, endRow, endCol, startRow, startCol);
            }
            // print(it);
            it = next(it.first, it.second, direction, endRow, endCol, startRow, startCol);
        }
        while(start != it);

        startRow++, startCol++, endRow--, endCol--;
    }

    // int dire = 1;
    // print(next(0, 3, dire, 3, 3, 0, 0));
    // cout << dire << "\n";
    cout << ans << "\n";
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

    while (tt--) {
        solve();
    }

    return 0;
}