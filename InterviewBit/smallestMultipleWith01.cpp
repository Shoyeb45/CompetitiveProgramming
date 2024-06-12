#include<bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

auto init = []() { 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

string solve(int n) {
    vector<bool> visited(n, 0);
    queue<pair<string, long long>> q;
    q.push({"1", 1 % n});
    
    visited[1 % n] = 1;   

    while(true) {
        string curr = q.front().first;
        long long rem = q.front().second;

        if(rem == 0) {
            break;
        }
        q.pop();
        
        long long rem1 = (rem * 10) % n;
        long long rem2 = ((rem * 10) + 1) % n;
        if(!visited[rem1]) {
            visited[rem1] = 1;
            q.push({curr + '0', rem1});
        }
        if(!visited[rem2]) {
            visited[rem2] = 1;
            q.push({curr + '1', rem2});
        }
    }
    return q.front().first;
}

int main() {
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        int n; cin >> n;

        string ans = solve(n);
        cout << ans << '\n';
    }
    
    return 0;
}
