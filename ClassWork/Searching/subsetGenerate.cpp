#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

vector<vector<ll>> subset;

void subset_generate(vector<ll> &a, int index, vector<ll> &current) {
    if(index == a.size()) {
        subset.push_back(current);
        return;
    }

    current.push_back(a[index]);    
    subset_generate(a, index + 1, current);
    current.pop_back();
    subset_generate(a, index + 1, current);
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    loop(i, n)  
        cin >> a[i];
    
    vector<ll> curr;
    subset_generate(a, 0, curr);
    loop(i, subset.size()) {
        loop(j, subset[i].size()) {
            cout << subset[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
