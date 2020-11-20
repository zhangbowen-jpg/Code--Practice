/*************************************************************************
	> File Name: 122.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 20时18分32秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main() {
    int t,h,m,s;
    char day;
    scanf("%d", &t);
    if(t<43200) {
        h = t/3600;
        m = (t%3600)/60;
        s = t%60;
        printf("%.2d:%.2d:%.2d am", h, m, s);
    }
    else if((t>=43200)&&(t<=46800)) {
        h = t/3600;
        m = (t%3600)/60;
        s = t%60;
        printf("%.2d:%.2d:%.2d midnoon", h, m, s);
    }
    else {
        h = (t-43200)/3600;
        m = ((t-43200)%3600)/60;
        s = (t-43200)%60;
        printf("%.2d:%.2d:%.2d pm", h, m, s);
    }
    return 0;
}

