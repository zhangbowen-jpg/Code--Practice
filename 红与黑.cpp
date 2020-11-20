/*************************************************************************
	> File Name: 红与黑.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 18时50分28秒
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define max_n 20

char str[max_n + 5][max_n + 5];
int cnt = 0;
int m, n, sx, sy;

void dfs(int x, int y) {
    if(x < 0 || x >= m || y < 0 || y >= n || str[x][y] == '#') return ;   //判断边界条件
    cnt += 1;
    str[x][y] = '#'; //将走过的格子标记为白色
    dfs(x - 1, y); //四个方向分别遍历
    dfs(x, y + 1);
    dfs(x + 1, y);
    dfs(x, y - 1);
    return ;
}

int main() { 
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> str[i][j];
            if (str[i][j] == '@') sx = i, sy = j;
        }
    }
    dfs(sx, sy);
    cout << cnt << endl;
    return 0;
}
