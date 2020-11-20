/*************************************************************************
	> File Name: 215.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 20时32分11秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define max_n 40

struct student {
    int sum;
    string name;
};

bool cmp(student i,student j) {
    return i.sum > j.sum;
}

int main() {
    student stu[45];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].name;
        stu[i].sum = 0;
        for (int j = 0; j < 4; j++) {
            int temp;
            cin >> temp;
            stu[i].sum += temp;
        }
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < 3; i++) {
        cout << stu[i].name << endl;
    }
    return 0;
}

