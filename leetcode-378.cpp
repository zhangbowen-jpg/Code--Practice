/*************************************************************************
	> File Name: leetcode-378.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 16时08分33秒
 ************************************************************************/
class Solution {
public:
    int bs_min(vector<vector<int>> &g, int val) {
        int cnt = 0, i = -1;
        while (i + 1 < g.size() && g[i + 1][0] < val) i += 1;
        cnt += i + 1;
        for(int j = 1; j < g.size(); j++) {
            while(i >= 0 && g[i][j] >= val) --i;
            cnt += i + 1;
        }
        return cnt;
    } 
    int bs_max(vector<vector<int>> &g, int val) {
        int cnt = 0, i = g.size();
        while (i > 0 && g[i - 1][0] > val) i -= 1;
        cnt += g.size() - i;
        for(int j = 1; j < g.size(); j++) {
            while(i > 0 && g[i - 1][j] > val) --i;
            cnt += g.size() - i;
        }
        return cnt;
    } //从大往小找，从下往上找
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int head = matrix[0][0], tail = matrix[n - 1][n - 1], mid;
        while(head <= tail) {
            mid = ((head ^ tail) >> 1) + (head & tail); //按位比较，分为两种，一种同时为1，一种不同时为1。
//同时为1时，进位之后退位等于原来，不同时为一时直接剪掉。
            int a = bs_min(matrix, mid);
            int b = bs_max(matrix, mid);
            int c = n * n - a - b;
            if(k <= a + c && k > a) return mid;
            if(a + c < k) head = mid + 1;
            else tail = mid - 1;
        }
      return -1;   
    }
};
