/*************************************************************************
	> File Name: 201.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月22日 星期四 21时01分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, arr[1005] = {0}, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(!arr[temp]) {
            arr[temp] = 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    int flag = 0;
    for(int i = 0; i <= 1000; i++) {
        if(ans[i]) {
            if(flag == 1) {
                cout << " ";
            }
            cout << i;
            flag = 1;
        }
    }
    return 0;
}

