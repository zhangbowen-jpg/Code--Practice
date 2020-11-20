/*************************************************************************
	> File Name: leetcode-7.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月03日 星期四 15时18分58秒
 ************************************************************************/
int reverse(int x) {
    long r=0;
    while(x!=0){
        r=10*r+x%10;
        x=x/10;
    }
    if(r>pow(2,31)-1||r<-pow(2,31))
       return 0;
    return r;
}
