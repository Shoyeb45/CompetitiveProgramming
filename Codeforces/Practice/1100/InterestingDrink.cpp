#include<bits/stdc++.h>
using namespace std;

int upperBound(int a[], int x, int n) {
        int lower = 0;
        int upper = n - 1;
        int UB = 0;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(a[mid] > x) {
                upper = mid - 1;
            } else {
                UB = mid+1;
                lower = mid + 1;    
            }
        }
        return UB;
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
        int cnt = upperBound(x, y, n);
        cout << cnt << "\n";   
    }

    return 0;
}