#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& prefixSum, int target) {
    int low = 0;
    int high = prefixSum.size()-1;
    int ans = -1;

    while(low <= high) {
        int mid = (high + low) / 2;

        if(target <= prefixSum[mid]) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefixSum(n);
    prefixSum[0] = a[0];
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i-1] + a[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        int q;
        cin >> q;
        int index = lowerBound(prefixSum, q);
        cout << index + 1 << "\n"; 
    }

    return 0;
}
