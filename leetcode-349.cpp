/*************************************************************************
	> File Name: leetcode-349.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 15时05分22秒
 ************************************************************************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        map<int, int> s;
        for(int i = 0; i < nums1.size(); i++) {
            s[nums1[i]] = 1;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(s[nums2[i]] == 0) continue;
            ret.push_back(nums2[i]);
            s[nums2[i]] -= 1;
        }
        return ret;
    }
};

