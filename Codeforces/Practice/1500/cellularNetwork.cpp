#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int lowerBound(vector<int> &a, int target) {
    int low = 0, high = a.size() - 1, ans = a.size();
    // cout << ans;
    while(low <= high) {
        int mid = (low + high)/2;
        if(a[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;   cin >> n >> m;
    vector<int>  a(n), b(m);
    loop(i, n)  cin >> a[i];
    loop(i, m)  cin >> b[i];

    int ans = 0;
    loop(i, n) {
        int rightTower = lowerBound(b, a[i]);
        int leftTower = rightTower - 1;
        int distance = INT_MAX;
        if(rightTower < m) {
            distance = min(distance, b[rightTower] - a[i]);
        }

        if(leftTower >= 0) {
            distance = min(distance, a[i] - b[leftTower]);
        }

        ans = max(distance, ans);
        // cout << "Ans: " << ans << "lb: " << rightTower << "dist: " << distance <<'\n';
    }
    // cout << endl;
    cout << ans << '\n';
   
    return 0;
}
