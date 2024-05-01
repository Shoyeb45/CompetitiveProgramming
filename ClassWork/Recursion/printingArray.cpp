#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void print(vector<int> &a, int i) {
    if(i == 0) {
        cout << "\n";
        return;
    }
    cout << a[i - 1] << " ";
    print(a, i-1);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<int> a(n);
    loop(i, n)  cin >> a[i];

    print(a, n);
    return 0;
}
