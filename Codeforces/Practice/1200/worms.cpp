#include<bits/stdc++.h>
using  namespace std;

int ind (int target, vector<pair<int, int> > vp) {
    int low = 0;
    int high = vp.size()-1;
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(target >= vp[mid].first && target <= vp[mid].second) {
            ans = mid+1;
            break;
        } else if(target > vp[mid].second) {
            low = mid + 1;
        } else if(target < vp[mid].second ){
            high = mid - 1;
        }
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int temp; cin >> temp;
        a.push_back(temp);
    }
    cin >> m;
    vector<int> q;
    for(int i=0; i<m; i++) {
        int temp; cin >> temp;
        q.push_back(temp);
    }

    vector<pair <int, int> > vp;
    vp.push_back(make_pair(1, a[0]));

    for(int i=1; i<n; i++) {
        vp.push_back(make_pair(vp[i-1].second+1, vp[i-1].second+a[i]));
    }
    for(int i=0; i<m ; i++) {
        int index = ind(q[i], vp);
        cout << index << "\n";
    }


    return 0;
}

// TC Code - n * log(sum of elements in a)