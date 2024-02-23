#include<bits/stdc++.h>
using namespace std;

int count(int a[], int target, int n) {
    int low = 0;
    int high = n - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if(a[mid] <= target) {
            ans = mid+1;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    sort(a, a+n);
    for(int i=0; i<m; i++) {
        int cnt = count(a, b[i], n);
        cout << cnt << " ";
        }
        
    return 0;
    }
