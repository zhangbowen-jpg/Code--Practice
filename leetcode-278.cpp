/*************************************************************************
	> File Name: leetcode-278.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 15时03分17秒
 ************************************************************************/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int head = 0, tail = n, mid;
        while(head < tail) {
            int mid = head + (tail - head) / 2;
            if(!isBadVersion(mid - 1) && isBadVersion(mid)) return mid;
            else if(!isBadVersion(mid)) head = mid + 1;
            else  tail = mid;
        }
        if(isBadVersion(head) && !isBadVersion(head - 1)) return head;
        return -1;
    }
};
