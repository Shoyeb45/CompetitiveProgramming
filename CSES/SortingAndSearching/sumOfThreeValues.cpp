#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
const ll mod = 1000000007;

int elementPosition(vector<pair<int, int>> &a, int target, int compare1, int compare2) {
    int left = 0 , right = a.size() - 1; 

    while(left < right) {
        int mid = (left + right)/2;
        if((a[mid].second != compare1 && a[mid].second != compare2) && a[mid].first == target) {
            return a[mid].second;
        } else if(a[mid].first > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;   cin >> n >> x;
    vector<pair<int, int>> a(n);
    loop(i, n) {  
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());

    vector<int> indices(3);
    bool not_present = false;

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ll two_sum = a[i].first + a[j].first;
            if(two_sum > x) 
                break;
            else {
                int pos3 = elementPosition(a, x - two_sum, a[i].second, a[j].second);
                if(pos3 != 0) {
                    indices[0] = a[i].second;
                    indices[1] = a[j].second;
                    indices[2] = pos3;
                    not_present = true;
                } else {
                    not_present = false;
                }
            }
            if(not_present)
                break;

        }
        if(not_present)
            break;
    }
    
    if(not_present) {
            cout << indices[0] << " " << indices[1] << " " << indices[2] << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
