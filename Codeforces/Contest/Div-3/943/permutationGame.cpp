#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

void solve() {
    int n, k, p_b, p_s;
    cin >> n >> k >> p_b >> p_s;
    p_b--;
    p_s--;
    vector<int> p(n);
    vector<int> a(n);
    loop(i, n)  {
        cin >> p[i];
        p[i]--;
    }
    loop(i, n)  cin >> a[i];

    vector<int> bodya;
    vector<int> sasha;

    int i = p_b;
    bodya.push_back(a[p_b]);
    int temp = k - 1;
    while(temp--) {
        i = p[i];
        if(i == p_b)
            break;
        
        bodya.push_back(a[i]);
    }
    
    temp = k - 1;
    i = p_s;
    sasha.push_back(a[p_s]);
    while(temp--) {
        i = p[i];
        if(i == p_s)
            break;
        
        sasha.push_back(a[i]);
    }
    
    
    int mx_sasha = *max_element(sasha.begin(), sasha.end());
    int mx_bodya = *max_element(bodya.begin(), bodya.end());
    ll sasha_score = 0;
    ll bodya_score = 0;

    int cnt = 0;
    i = 0;
    while(sasha[i] != mx_sasha) {
        sasha_score += sasha[i];
        cnt++;
        i++;
    }
    sasha_score += mx_sasha * (k - cnt);
    sasha_score = 1LL * k * sasha[0] >= sasha_score? 1LL * k * sasha[0]: sasha_score;
    i = 0, cnt = 0;
    while(bodya[i] != mx_bodya) {
        bodya_score += bodya[i];
        cnt++;
        i++;
    }
    bodya_score += mx_bodya * (k - cnt);
    bodya_score = 1LL * k * bodya[0] >= bodya_score? 1LL * k * bodya[0]: bodya_score;

    if(bodya_score > sasha_score) {
        cout << "Bodya\n"; 
    } else if(bodya_score < sasha_score) {
        cout << "Sasha\n";
    } else {
        cout << "Draw\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
