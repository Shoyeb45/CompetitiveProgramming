#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int number_of_subarray(vector<int> &a, int target) {
    int left = 0, right = 0;
    int count = 0;
    ll sum = 0;
        sum += a[right];
    while(right < a.size()) {
        if(sum == target) {
            count++;
            sum -= a[left];
            left++;
            right++;
            sum += a[right];
        } else if(sum > target) {
            sum -= a[left];
            left++;
        } else {
            right++;
            sum += a[right];
        }
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;   cin >> n >> x;
    vector<int> a(n);
    loop(i, n)  cin >> a[i];

    int count = number_of_subarray(a, x);
    cout << count << '\n';
    
    return 0;
}
