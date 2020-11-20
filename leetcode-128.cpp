/*************************************************************************
	> File Name: leetcode-128.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月24日 星期日 16时35分36秒
 ************************************************************************/
class UnionSet {
    public: 
        vector<int> fa, size; //不知道多大，动态创建
        void init(int n) {
            fa.clear();
            for(int i = 0; i <= n; i++) {
                fa.push_back(i);
                size.push_back(1);
            }
            return ;
        }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) {
        int aa = get(a), bb = get(b);
        if(aa == bb) return ;
        fa[aa] = bb;
        size[bb] += size[aa];
        return ;
    }
};


class Solution {
public: 
    int longestConsecutive(vector<int>& nums){
        u.init(nums.size());
        unordered_map<int, int> ht;
        for(int i = 0; i < nums.size(); i++) {
            int k = nums[i];
            if(ht.find(k) != ht.end())  continue;//k在前面出现过
            if(ht.find(k - 1) != ht.end()) {
                u.merge(i, ht[k - 1]);
            }
            if(ht.find(k + 1) != ht.end()) {
                u.merge(i, ht[k + 1]);
            }
            ht[k] = i;
        }
        int ans = 0; 
        for(int i = 0; i < nums.size(); i++) {
            ans = max(ans, u.size(i));
        }
        return ans;
    }
    UnionSet u;
};


