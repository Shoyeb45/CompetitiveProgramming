#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> a(n);

        for(int i = 0; i < n ; i++) cin >> a[i];

        int cnt = 0; 
        int min = INT_MAX, max = INT_MIN;
        for(int i = 0; i < n ; i++) {
            if(a[i] >= l && a[i] <= r)  cnt++;
            else    cnt--;

            if(cnt >= max)  max = cnt;
            if(cnt <= min)  min = cnt;
        }

        cout << max << " " << min << '\n';
    }
    
}