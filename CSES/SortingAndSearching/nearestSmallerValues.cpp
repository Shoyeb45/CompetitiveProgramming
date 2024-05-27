#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

vector<int> calc_prev_small_ind(vector<int> &a) {
    vector<int> ans(a.size(), 0);
    stack<int> st;
    for(int i = a.size() - 1; i >= 0; i--) {
        while(!st.empty() && a[i] < a[st.top()]) {
            ans[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    return ans;
} 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    loop(i, n)
        cin >> a[i];

    vector<int> ind = calc_prev_small_ind(a);
    
    loop(i, n) {
        cout << ind[i] << ' ';
    }
    cout << '\n';
    return 0;
}
