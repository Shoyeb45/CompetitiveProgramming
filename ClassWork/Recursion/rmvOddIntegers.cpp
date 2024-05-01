#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void removeOdd(vector<int> &a, int &n, int i, int j) {
    if(i == n) {
        n == j;
        return;
    }
    if(a[i] % 2 == 0)   
        a[j++] = a[i];
    removeOdd(a, n, i + 1, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> a(n);
    loop(i, n) cin >> a[i];
    removeOdd(a, n, 0, 0);

    loop(i, n) 
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
