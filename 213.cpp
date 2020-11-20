/*************************************************************************
	> File Name: 213.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月23日 星期五 14时10分31秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 6

int B[max_n + 5] = {0};
int arr[35];

int main() {
    int n,temp; 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        if(arr[i] >= 90 && arr[i] <= 99) B[2]++;
        else if(arr[i] >= 80 && arr[i] <= 89) B[3]++;
        else if(arr[i] >= 70 && arr[i] <= 79) B[4]++;
        else if(arr[i] >= 60 && arr[i] <= 69) B[5]++;
        else if(arr[i] < 60) B[6]++;
        else B[1]++;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(arr[i] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << endl;
    }
    for(int i = 1; i <= 6; i++) {
        cout << B[i];
        if(i == 6) continue;
        cout << " ";
    } 
    return 0;
    
}

