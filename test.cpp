#include<bits/stdc++.h>
using namespace std;


         
    bool search(vector<int>& nums, int target) {
        int minInd = nums.size();
        int lower = 0;
        int upper = nums.size()-1;
        
        while(lower <= upper) {
            int mid = (lower + upper)/2;
            if(mid < nums.size()-1 && nums[mid] > nums[mid+1]) {
                minInd = mid+1;
                break;
            } else if(nums[0] > nums[mid]) {
                upper = mid - 1;
            } else if(nums[nums.size() - 1] < nums[mid]){
                lower = mid + 1;
            } else {
                break;
            }
        } 

        if(nums[0] > target) {
            lower = minInd;
            upper = nums.size() - 1;
        } else {
            lower = 0;
            upper = minInd - 1;
        }
        cout << minInd << '\n';
        int ans = false;
        while (lower <= upper) {
            int mid = (lower + upper)/2;
            if(nums[mid] == target) {
                ans = true;
                break;
            } else if(nums[mid] > target) {
                upper = mid - 1;
            } else {
                lower = mid + 1;
            }
        }
        return ans;
    }


int main() {
    int n, q;
    cin >> n;
    vector<int> x;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        x.push_back(temp);
    }

    cin >> q;
    
    bool ans = search(x, q);
    cout << ans ;
    return 0;
}