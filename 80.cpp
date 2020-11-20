/*************************************************************************
	> File Name: 80.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年01月15日 星期三 11时48分19秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 505
#define ERROR 0
#define OK 1

typedef struct Node {
    int x, y;
    int dis;
} Node;
 
typedef struct Graph {
    char mat[MAX_N][MAX_N];
    int vis[MAX_N][MAX_N];
    int n, m;
} Graph;

typedef struct Queue {
    Node *data;
    int head, tail, len;
} Queue;

void init_queue(Queue *q, int n) {
    q->data = (Node *)malloc(n * sizeof(Node));
    q->head = 0;
    q->tail = 0;
    q->len = n;
}

int empty_queue(Queue *q) {
    return q->head >= q->tail;
}

void clear_queue(Queue *q) {
    free(q->data);
    free(q);
}

Node front_queue(Queue *q) {
    return q->data[q->head];
}

int push_queue(Queue *q, Node n) {
    if (q->tail >= q->len) {
        return ERROR;
    }
    q->data[(q->tail)++] = n;
    return OK;
}

int pop_queue(Queue *q) {
    if (empty_queue(q)) {
        return ERROR;
    }
    ++(q->head);
    return OK;
}

void init_graph(Graph *g, int n, int m) {
    g->n = n;
    g->m = m;
    memset(g->mat, 0, sizeof(g->mat));
    memset(g->vis, 0, sizeof(g->vis));
}

int bfs(Graph *g) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, g->n * g->m);
    Node now, temp;
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->m; j++) {
            if (g->mat[i][j] != 's') continue;
            g->vis[i][j] = 1;
            now.x = i, now.y = j, now.dis = 0;
            push_queue(q, now);
            break;
        }
    }
    int k_1[4][2] = {
        1, 0, 0, 1,
        -1, 0, 0, -1,
    };
    int indx, indy;
    int flag = 1, ans = -1;
    while (!empty_queue(q) && flag) {
        now = front_queue(q);
        pop_queue(q);
        for (int i = 0; i < 4; i++) {
            indx = now.x + k_1[i][0];
            indy = now.y + k_1[i][1];
            if (indx < 0 || indx >= g->n || indy < 0 || indy >= g->m) {
                continue;
            }
            if (g->vis[indx][indy]) continue;
            if (g->mat[indx][indy] == '#') continue;
            if (g->mat[indx][indy] == 'g') {
                flag = 0;
                ans = now.dis + 1;
                break;
            }
            g->vis[indx][indy] = 1;
            temp.x = indx;
            temp.y = indy;
            temp.dis = now.dis + 1;
            push_queue(q, temp);
        }
    }
    clear_queue(q);
    return ans;
}

int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
        Graph *g = (Graph *)malloc(sizeof(Graph));
        init_graph(g, n, m);
        for (int i = 0; i < n; i++) {
            scanf("%s", g->mat[i]);
        }
        k = bfs(g);
        if(k == -1) printf("No\n");
        else printf("%d\n", k);
        free(g);
    return 0;
}

