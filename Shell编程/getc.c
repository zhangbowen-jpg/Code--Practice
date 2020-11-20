/*************************************************************************
	> File Name: getc.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月26日 星期六 19时01分39秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>


int get_value(char *path, char *key, char *ans) {
    FILE *fp = NULL;
    ssize_t read;
    size_t len;
    char *line = NULL;
    char *substr = NULL;

    if(key == NULL || ans == NULL || path == NULL) {
        printf("Error in arguement\n");
        return -1;
    }

    if ((fp = fopen(path, "r")) == NULL) {
        perror("fopen");
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        if((substr = strstr(line, key)) == NULL) continue;
        else {
            if(substr[strlen(key)] == '=') {
                strncpy(ans, substr + strlen(key) + 1, read - strlen(key) - 1);
                *(ans + strlen(ans) - 1) = '\0';
                break;
            }
        }
    }
    
    if (substr == NULL) {
        free(line);
        fclose(fp);
        return -1;
    }
    
    free(line);
    fclose(fp);

    return 0;
}

int main() {
    char buff[50] = {0};
    get_value("./wechat.conf", "server", buff);
    printf("server = %s\n", buff);
    memset(buff, 0, 50);
    get_value("./wechat.conf", "name", buff);
    printf("server = %s\n", buff);
    memset(buff, 0, 50);
    get_value("./wechat.conf", "port", buff);
    printf("server = %s\n", buff);
    memset(buff, 0, 50);
    return 0;
}

