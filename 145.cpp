/*************************************************************************
	> File Name: 145.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月27日 星期六 15时07分26秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
int main() {
    int i, n, len, j;
    scanf("%d\n", &n);
    char str[101], longest_name[101];
    len = 0;
    for (i = 0; i < n; ++i) {
            j = 0;
        while (scanf("%c", &str[j])) {
            if (str[j++] == '\n') {
                str[j] = '\0';
                break;
            }
        }
        if (strlen(str) > len) {
            strcpy(longest_name, str);
            len = strlen(str);
        }
    }
    printf("%s\n", longest_name);
    return 0;
}
