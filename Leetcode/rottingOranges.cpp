#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        int total = 0, rotten = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] != 0)    total++;
                if(a[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }

        int ans = 0;
        int h[4] = {0, 0, 1, -1};
        int v[4] = {1, -1, 0, 0};

        while(!q.empty()) {
            int k = q.size();
            rotten += k;

            while(k--) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int newx = x + h[i], newy = y + v[i];
                    if(newx < 0 || newy < 0 || newx >= n || newy >= m || a[newx][newy] != 1)    continue;
                    a[newx][newy] = 2;
                    q.push(make_pair(newx, newy));
                }
            }
            if(!q.empty())  ans++;

        }

        if(total == rotten) return ans;
        return -1;
    }
};
