/*************************************************************************
	> File Name: leetcode-219.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 14时54分10秒
 ************************************************************************/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        k += 1;
        unordered_map<int, int> s;
        for(int i = 0; i < nums.size(); i++) {
            s[nums[i]] += 1;
            if(i >= k) s[nums[i - k]] -= 1;
            if(s[nums[i]] == 2) return true;
        }
        return false;
    }
};

