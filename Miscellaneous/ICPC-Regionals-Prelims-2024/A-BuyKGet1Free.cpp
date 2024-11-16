#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

       
        sort(arr.begin(), arr.end());

        
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        
        vector<int> ans(n);
        ans[0] = arr[0];

        for (int i = 1; i < n; i++) {
            if (i >= k) {
                ans[i] = prefix[i] - prefix[i - k] + (i > k ? ans[i - k - 1] : 0);
            } else {
                ans[i] = prefix[i];
            }
        }

        
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}