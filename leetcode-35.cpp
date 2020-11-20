/*************************************************************************
	> File Name: leetcode-35.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 14时19分57秒
 ************************************************************************/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0, tail = nums.size(), mid;
        while(head < tail) {
            mid = (head + tail) >> 1;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) head = mid + 1;
            else tail = mid;
        }
        return head;
    }
};

// 前面n个0，找第一个1。







