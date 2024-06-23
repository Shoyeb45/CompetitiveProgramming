# Practice questions on Bit-Manipulation

## 1. Minimum Bit Flips to Convert Number - Leetcode
* [Link of problem](https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/)<br>
* [Solution](https://leetcode.com/submissions/detail/1297492738/)

## 2. Print all the subsets(Power Set)
* [Recursive solution](./../Searching/subsetGenerate.cpp)
* [BitMask solution](./../Searching/subsetGenBitMask.cpp)
## 3. Single Number - I  Leetcode
* [Link of problem](https://leetcode.com/problems/single-number/description/)<br>
* Solution Code: <br>
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int unique=0;
        for(int i=0;i<nums.size();i++)
            unique=unique^nums[i];
        return unique;
    }
};
```
## 3. 3. Single Number - II  Leetcode
* [Link of problem](https://leetcode.com/problems/single-number-ii/description/)
* Solutions:

1. Using Hash Map
```
class Solution {
public:
    int singleNumber(vector<int>& a) {
        map<int, int> m;
        for(auto & x : a)
            m[x]++;

        for(auto & it: m) 
            if(it.second == 1)
                return it.first;

        return 0;
    }
};
```
2. [Using Bit Manipulation - I](https://leetcode.com/submissions/detail/1297602713/)
3. [Sorting](https://leetcode.com/submissions/detail/1297617559/)
4. [Bit Manipulation - II : Bucket](https://leetcode.com/submissions/detail/1297812914/)

