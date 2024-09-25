#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int  n;
string s;
void solve() {
    cin >> n >> s;
    stack<char> st;

    for(auto ch: s) {
        if(ch == '(') {
            st.push(ch);
        }
        else {
            if(!st.empty() && st.top() == '(') {
                st.pop();
            }
        }
    }

    cout << st.size() << '\n';
}

int main() {
    NFS
    int tt;
    tt = 1;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}