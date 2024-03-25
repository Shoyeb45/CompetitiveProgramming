#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void swap(vector<int> &v, int x, int y) {
        int temp = v[x];
        v[x] = v[y];
        v[y] = temp;
    } 

    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int i = 0;
        while(i <= high) {
            if(nums[i] == 1)    i++;
            else if(nums[i] == 0) {
                swap(nums ,i , low);
                low++;
                i++;
            } else {
                swap(nums, i, high);
                high--;
            }
        }
    }
};