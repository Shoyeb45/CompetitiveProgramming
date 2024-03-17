#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++)  cin >> a[i];
        int maxDifference = -12;
        for(int i = n - 1; i >= 1; i--) {
            int temp = a[i] - a[i-1];
            if(maxDifference <= temp)   maxDifference = temp;
        }

        if(maxDifference <= a[0] - 0)   maxDifference = a[0] - 0;
        if(maxDifference > 2 * (x - a[n-1]) )    cout << maxDifference << '\n';
        else    cout << 2 * (x - a[n-1]) << '\n';
    }
    
}