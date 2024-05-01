#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;


void print(vector<int> &a, int i) {
    if(i == (a.size() - 1)/2) {
        cout << a[i] << " " << a[a.size() - 1 - i] << endl;
        return;
    }

    cout << a[i] << " " << a[a.size() - 1 - i] << endl;
    print(a, i + 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> a(n);
    loop(i, n)  cin >> a[i];

    print(a, 0);
    return 0;
}
