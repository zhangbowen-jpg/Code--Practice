/*************************************************************************
	> File Name: leetcode-88.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 14时41分40秒
 ************************************************************************/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n + m - 1, p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 || p2 >= 0) {
            if(p2 < 0 || (p1 >= 0 && nums1[p1] >= nums2[p2])) {
                nums1[k--] = nums1[p1--]; 
            } else {
                nums1[k--] = nums2[p2--];
            }
        }
        return ;
    } //在两个数组尾部放指针，谁大谁放后面
};
