#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for(int i = 0; i < n; i++)  cin >> a[i];
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == k) {
                cout << "YES\n";
                break;
            }
            cnt++;
        }
        if(cnt == n)    cout << "NO\n";
    }

    return 0;
}