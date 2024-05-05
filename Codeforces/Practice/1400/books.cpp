#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];

    int left = 0, right = 0;
    ll sum = 0;
    int ans = 0;

    while (left < n && right < n) {
        while(right < n) {
            sum += a[right];
            right++;
            if(sum > t) {
                right--;
                sum -= a[right];
                break;
            }
        }

        ans = max(ans, right - left + 1);
        sum -= a[left];
        left++;
    }

    cout << ans << endl;
    return 0;
}
