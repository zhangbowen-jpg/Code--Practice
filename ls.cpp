/*************************************************************************
	> File Name: ls.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年09月19日 星期四 23时02分18秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<termios.h>
#include<algorithm>
#include<math.h>
using namespace std;

bool cmp(string a,string b){ 
    return a < b;
}

int main(int argc, char **argv){
// dirent.h 库中包含两个结构体 __dirstream 和 dirent
    //struct __dirstream typedef struct __dirstream DIR
    struct winsize size;
    ioctl(STDIN_FILENO,TIOCGWINSZ,&size);
    DIR *dir;
    int len,cols = 1;
    char str[1000];
    string res[1000];
    struct dirent *rent;
    if(argc == 1){
    dir = opendir(".");
    }
    else dir = opendir(argv[1]);
    int cnt = 0;
    while((rent = readdir(dir))) {
        strcpy(str, rent -> d_name);
        if(str[0] == '.') 
            continue;
        if(str[1] == '.')
            continue;
        if(!str)
            continue;
        //printf("%s",str);
        res[cnt++] = str;
    }
    sort(res, res+cnt, cmp);
    for(int i = 0; i < cnt; i++){
        if(len < strlen(res[i].c_str())) len = strlen(res[i].c_str());
    } 
    len += 2;
    for(int i = 10; i >= 1; i--) {
        if(len * i + 2 > size.ws_col) continue;
        else {
            cols = i;
            break;
        }
    }
    for(int i = 0; i < cnt; i++) {
        cout << res[i];
        for(int j = 1; j <= size.ws_col / cols - strlen(res[i].c_str()); j++) { // 计算间隔，然后用间隔减去字符串
            printf(" ");
        }
        if((i+1) % cols == 0) puts("");
    }
    puts("");
    closedir(dir);
    return 0;
    //先获取宽度，然后快排，然后计算几个文件会超宽度，然后分段。
} 

