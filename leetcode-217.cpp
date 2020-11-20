/*************************************************************************
	> File Name: leetcode-217.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 14时48分00秒
 ************************************************************************/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
}; //裸哈希


/*
 *class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(nums[i]) != s.end()) return true;
            s.insert(nums[i]);
        }
        return false;
    }
}; //更快的哈希
 */
 
