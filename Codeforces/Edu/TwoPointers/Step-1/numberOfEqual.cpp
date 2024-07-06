#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i = 0; i < n; i++)
#define range(x) (x).begin(), (x).end()
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int n, m;
void solveBS() {
    // Binary Search Solution 
    // TC : O(n * log(m))
    cin >> n >> m;
    vector<int> a(n), b(m);
    loop(i, n)
        cin >> a[i];
    loop(j, m) 
        cin >> b[j];
    
    ll ans = 0;
    loop(i, n) {
        ans += (upper_bound(range(b), a[i]) - lower_bound(range(b), a[i]));
    }
    cout << ans << '\n';
}

void solveTP() {
    // Two pointers solution

    cin >> n >> m;
    vector<int> a(n), b(m);
    loop(i, n)
        cin >> a[i];
    loop(j, m) 
        cin >> b[j];

    int i = 0, j = 0;
    ll ans = 0;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            ll num1 = 1, num2 = 1;
            while(i < n - 1 && a[i] == a[i + 1]) {
                i++;
                num1++;
            }
            while(j < m - 1 && b[j] == b[j + 1]) {
                j++;
                num2++;
            }
            ans += 1LL * num1 * num2;
            i++;
            j++;
        } else if(a[i] > a[j]) {
            while(j < m) {
                if(b[j] > a[i]) 
                    break;
                if(b[j] == a[i])
                    break;
                j++;
            }
            if(j < m && b[j] != a[i]) {
                j++;
            }
        } else {
            while(i < n) {
                if(a[i] > b[j])
                    break;
                if(b[j] == a[i])
                    break;
                i++;
            }
            
            if(i < n && a[i] != b[j]) {
                i++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    int tt;
    tt = 1;
    // cin >> tt;

    while (tt--) {
        solveTP();
    }
    
    return 0;
}
