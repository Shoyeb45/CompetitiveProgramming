#include<bits/stdc++.h>
using namespace std;

int numberShop(int x[], int q, int n) {
    int low = 0;
    int high = n - 1;
    int count = 0;
    while (low <= high) 
    {
        int mid = (low + high)/2;
        if(mid >= 0 && q <= x[mid-1]) {
            count++;
            high = mid + 1;
        } else if(q <= x[mid] ) {
            count++;
            high = mid - 1;
        } else {
            high = mid - 1;
        }
    }
    return count;
}

int main() {
    int n, q;
    cin >> n;
    int x[n];
    for(int i=0; i<n; i++)  cin >> x[i];

    cin >> q;
    sort(x, x+n);

    for(int i=0; i<q; i++)  {
        int y;
        cin >> y;
        int cnt = numberShop(x, y, n);
        cout << cnt << "\n";   
    }

    return 0;
}