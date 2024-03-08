#include<bits/stdc++.h>
using namespace std;

int min(vector<int> &v) {
    int ans = INT_MAX;
    for(int i=0; i<v.size(); i++)  {
        if(ans >= v[i]) ans = v[i];  
    }
    return ans;
}

int max(vector<int> &v) {
    int ans = INT_MIN;
    for(int i=0; i<v.size(); i++)   {
        if(ans <= v[i]) ans = v[i];
    }
    return ans;
}

int sum(vector<int> &v) {
    int ans = 0;
    for(int i=0; i<v.size(); i++)   ans += v[i];
    return ans;
}

double avg(vector<int> &v) {
    double ans = 0;
    for(int i=0; i<v.size(); i++)   ans += v[i];
    return ans/v.size();
}

int mode(vector<int> &v) {
    sort(v.begin(), v.end());
    int maxCnt = 1;
    int mode = v[0];
    int currentCnt = 1;

    for (int i = 1; i < v.size(); ++i) {
        if (v[i] == v[i - 1]) {
            currentCnt++;
        } else {
            currentCnt = 1;
        }

        if (currentCnt > maxCnt) {
            maxCnt = currentCnt;
            mode = v[i];
        }
    }

    return mode;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];

    vector<int> v;

    for(int i = 0 ; i < n; i++) {
        v.push_back(a[i]);
        printf("min, max, sum, average and mode after addition of %d is %d %d %d %.2lf %d\n", a[i], min(v), max(v) , sum(v), avg(v), mode(v));
    }
    return 0;
}