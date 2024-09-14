#include<bits/stdc++.h>
using namespace std;
#define range(x) (x).begin(), (x).end()
#define NFS ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
const ll mod = 1000000007;

int n, m, q;
vector<int> teacher, query;

int upperBound(vector<int> &a, int target) {
    int low = 0, high = a.size() - 1;
    int ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid] <= target) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    } 
    return ans;
}
int lowerBound(vector<int> &a, int target) {
    int low = 0, high = a.size() - 1;
    int ans = high;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(a[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    } 
    return ans;
}
void solve() {
    cin >> n >> m >> q;
    teacher.resize(m);
    query.resize(q);

    for(auto &x: teacher) {
        cin >> x;
    }
    for(auto &x: query) {
        cin >> x;
    }

    sort(range(teacher));
    vector<int> ans;

    for(auto pos: query) {
        int tempAns = 0;
        if(pos > teacher.back()) {
            int t2 = teacher.back();
            tempAns += (n - pos);
            t2 += tempAns;
            tempAns += (n - t2);
        }
        else if(teacher.front() > pos) {
            int t1 = teacher.front();
            tempAns += (pos - 1);
            t1 -= tempAns;
            tempAns += (t1 - 1);
        }
        else {
            int d = pos;
            int t2 = teacher[lowerBound(teacher, pos)], t1 = teacher[upperBound(teacher, pos)];
            // cout << t1 << " " << t2 << '\n';
            int mid = ((t1 + 1) + (t2 - 1)) / 2;
            tempAns += abs(d - mid);
            if(d > mid) {
                d -= tempAns;
            }
            else {
                d += tempAns;
            }
            t1 += tempAns;
            t2 -= tempAns;
            tempAns += min(t2 - d, d - t1);
        }
        ans.push_back(tempAns);
    }

    for(auto x: ans) {
        cout << x << '\n';
    }
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
