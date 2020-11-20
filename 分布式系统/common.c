/*************************************************************************
	> File Name: common.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年12月08日 星期日 18时16分31秒
 ************************************************************************/
#include "head.h"

char *get_value(char *path, char *key, char *ans) {
    FILE *fp = NULL;
    ssize_t read;
    size_t len;
    char *line = NULL;
    char *substr = NULL;

    if(key == NULL || ans == NULL || path == NULL) {
        printf("Error in argument\n");
        return NULL;
    }

    if((fp = fopen(path, "r")) == NULL) {
        perror("fopen");
        return NULL;
    }
    while((read = getline(&line, &len, fp)) != -1) {
                if((substr = strstr(line, key)) == NULL)
                    continue;
                else {
                    if(substr[strlen(key)] == '=') {
                        strncpy(ans, substr + strlen(key) + 1, read - strlen(key) - 1);
                        *(ans + strlen(ans) - 1) = '\0';
                        break;
                    }
                }
        }
            free(line);
            fclose(fp);

        if(substr == NULL) {
                return NULL;
        }

        return ans;
}




