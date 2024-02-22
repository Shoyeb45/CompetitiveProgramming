#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;

    while (t--)
    {
        long long n, m, x, y, l;
        cin >> n >> m >> x >> y >> l;

        if(l == 1) {
            long long ans = n * m;
            cout << ans << "\n";
        } else {
            long long row = (y-1)/l + (m - y - 1)/l;
            long long column = (x-1)/l + (n - x - 1)/l;

            row = row == 0 ? row + 1: row;
            column = column == 0 ? column + 1: column;
            cout << row * column << "\n";
        }
    }
    
    return 0;
}
