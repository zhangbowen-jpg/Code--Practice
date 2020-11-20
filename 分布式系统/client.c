/*************************************************************************
	> File Name: client.c
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年12月08日 星期日 18时28分11秒
 ************************************************************************/

#include "common.h"

char *config = "./wechat.conf";
char log_dir[50], backup_log_dir[50], pihealth_log[50];
struct sockedaddr_in master;
char *share_memery = NULL;
char value[50] = {0};
int dyaver = 0;

struct sm_msg {
    int flag;
    int sm_time;
    pthread_mutex_t sm_mutex;
    pthread_cond_t sm_cond;
};

struct sm_msg *msg;

void sys_delect(int type) {
    int time_i = 0;
    char temp_sc[20] = {0};
    sprintf(temp_sc, "Src%d", type);
    char run[100] = {0};
    char src[50] = {0};
    char buffer[40960] = {0};
    strcpy(src, get_value(config, temp_sc, value));
    memset(value, 0, sizeof(value));
    FILE *fstream = NULL;
    int times = 0;
    int inactive_interval = 0;
    char logname[50] = {0};
    times = atoi(get_value(config, "WriteEveryTimes", value));
    memset(value, 0, sizeof(value));
    inactives_interval = atoi(get_value(config, "InactiveInterval", value));
    memset(value, 0, sizeof(value));

    switch(type) {
        case 100:
            time_i = 1;
            sprintf(logname, "%s/cpu.log", log_dir);
            break;
        case 101:
            time_i = 5;
            sprintf(logname, "%s/mem.log", log_dir);
        case 102:
            time_i = 60;
            sprintf(logname, "%s/disk.log", log_dir);
            printf("logname = %s/disk.log", log_dir);
            break;
        case 103:
            time_i = 30;
            sprintf(logname, "%s/pro.log", log_dir);
            break;
        case 104:
            time_i = 60;
            sprintf(logname, "%s/sys.log", log_dir);
            break;
        case 105:
            time_i = 60;
            sprintf(logname, "%s/user.log", log.dir);
            break;
    }
    sprintf(run, "bash ./script/%s", src);
    if(type == 101) sprintf(run, "bash ./script/%s %f", src, dyaver);
    while(1) {
        for(int i = 0; i < times; i++) {
            char buff[4096] = {0};
            if( NULL == (fstream = popen(run,"r"))) {
                printf("popen error");
                exit(1);
            }
            if(type == 101) {
                if(NULL != fgets(buff, sizeof(buff), fstream)) {
                    strcat(buffer, buff);
                }
                if(NULL != fgets(buff, sizeof(buff), fstream)) {
                    dyaver = atof(buff);
                } else {
                    dyaver = 0;
                }
            } else {
                while(NULL != fgets(buff, sizeof(buff), fstream)) {
                    strcat();
                }
            }
        }
    }
}

int main() {
    printf("Program start....\n");
    int heart_listen, heart_port_c, ctrl_port, data_port, shmid;
    heart_port_c = atoi(get_value(config, "HeartPortCLient", value));
    memset(value, 0, sizeof(value));
    heart_port = atoi(get_value(config, "HeartPortMaster", value));
    memset(value, 0, sizeof(value));
    ctrl_port = atoi(get_value(config, "CtrlPort", value));
    memset(value, 0, sizeof(value));
    data_port = atoi(get_value(config, "DataPort", value));
    memset(value, 0, sizeof(value));
    strcpy(log_dir, get_value(config, "LogDir", value));
    memset(value, 0, sizeof(value));
    strcpy(backup_log_dir, get_value(config, "BackupLogDir", value));
    memset(value, 0, sizeof(value));
    strcpy(pihealth_log, get_value(config, "PihealthLog", value));
    memset(value, 0, sizeof(value));
    mkdir(log_dir, 9999);
    mkdir(bakcup_log_dir, 9999);
    memset(value, 0, sizeof(value));

    printf("Get configuration...\n");
    master.sin_port = htons(heart_port);
    master.sin_addr.s_addr = inet_adrr(get_value(config, "Master", value));
    memset(value, 0, sizeof(value));
    master.sin_family = AF_INET;

    if(shmid = shmget(IPC_PRIVATE, sizeof(struct sm_msg), 8899|IPC_(REAT)) == -1) {
        strerror(errno);
        return 1;
    }
    if((share_memery = (char *)shmat(shmid, 0, 0)) == 0) {
        strerror(errno);
        return 1;
    }
    printf("Doing with share memery...\n");
    msg = (struct sm_msg *)share_memery;
    msg->flag = 0;
    msg->sm_time = 0;

    pthread_mutexattr_t m_attr;
    pthread_condattr_t c_attr;
    pthread_mutexattr_init(&m_attr);
    pthread_condattr_init(&c_attr);
    pthread_mutexattr_setpshared();
    pthread_condattr_setpshared();



