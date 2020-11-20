/*************************************************************************
	> File Name: leetcode-38.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年11月03日 星期日 14时32分47秒
 ************************************************************************/
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string ret = "", str = countAndSay(n - 1);
        char tmp[10];
        int cnt = 1; // cnt ,i为位数
        for(int i = 1, j = 0; str[i]; i++) {
            if(str[i] == str[j]) cnt += 1;
            else {
                sprintf(tmp, "%d%c", cnt, str[j]);
                ret += tmp;
                cnt = 1, j = i; //更新下个字符位置
            }
        }
        sprintf(tmp, "%d%c", cnt, str[str.size() - 1]);
        ret += tmp;
        return ret;
    } //肯定不会出现四个连着的1或2...
};

