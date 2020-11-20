/*************************************************************************
	> File Name: 194.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年08月17日 星期六 11时06分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

int arr[100005];

int binary_search(int x,int i,int n) {
    int head = i + 1, tail = n - 1;
    while (head <= tail) {
        int mid = (head + tail) >> 1;
        if(arr[mid] == x) return 1;
        if(arr[mid] > x) {
            tail = mid - 1;
        } else {
            head = mid + 1;
        }
    }
    return 0;

}

int main() {
    int n,ans;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> ans;
    for(int i = 0; i < n; i++) {
        int cha = ans - arr[i];
        if(binary_search(cha,i,n)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

