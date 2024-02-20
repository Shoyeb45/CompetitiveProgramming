#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    for(int i=0; i<m; i++) {
        int cnt = 0;
        for(int j=0; j<n; j++) {
            if(a[j] <= b[i]) 
                cnt++;
        }
    cout << cnt << " ";
    }
    return 0;
}
