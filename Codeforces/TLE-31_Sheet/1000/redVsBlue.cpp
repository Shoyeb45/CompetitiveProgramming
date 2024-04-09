#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, r, b;
        cin >> n >> r >> b;
        
        int x = r / (b + 1), y = r % (b + 1);

        loop(i, y)  cout << string((x+1), 'R') << 'B';
        for(int i = y; i < b; i++)  cout << string((x), 'R') << 'B';
        cout << string((x), 'R') << "\n";
    }
    return 0;
}
