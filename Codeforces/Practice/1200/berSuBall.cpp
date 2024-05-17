#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)  cin >> a[i];

    int m;
    cin >> m;
    vector<int> b(m);
    for(int i=0; i<m; i++)  cin >> b[i];

    int cnt = 0;

    // Brute Force
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(abs(a[i] - b[j]) <= 1) {  
                cnt++;
                b[j] = INT_MAX;
                break;
            }
        }
    }
    cout << cnt;
}