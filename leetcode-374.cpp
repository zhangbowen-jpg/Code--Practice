/*************************************************************************
	> File Name: leetcode-374.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 15时15分45秒
 ************************************************************************/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int head = 1, tail = n, mid;
        while (head <= tail) {
            mid = head + ((tail - head) >> 1);
            int ret = guess(mid);
            if (ret == 0) return mid;
            if (ret < 0) tail = mid - 1;
            else head = mid + 1;
        }
        return -1;
    }
};
