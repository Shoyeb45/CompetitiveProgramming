#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

pair<int, int> sum_pair(vector<pair<int, int>> a, int target) {
    int left = 0, right = a.size() - 1;

    while(left < right) {
        if(a[left].first + a[right].first == target) 
            return {a[left].second, a[right].second};
        else if(a[left].first + a[right].first > target)
            right--;
        else
            left++;
    }
    return {-1, -1};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    loop(i, n)  {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    pair<int, int> indices = sum_pair(a, x);
    if(indices.first == -1 && indices.second == -1) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << indices.first << " " << indices.second << '\n';
    }

    return 0;
}
