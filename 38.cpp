/*************************************************************************
	> File Name: 38.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月09日 星期二 15时24分34秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct BigInt{
    BigInt(int x){
        num.push_back(x);
        process_digit();
    }
    BigInt operator+(BigInt &b){
        BigInt c(*this);
        for(int i0;i<b.num.size();i++){
            if(i==c.num.size()) c.num.push_back(0)
        }
    }
    void process_digit(){
        for(int i=0;i<num.size();i++){
            if(num[i]<10)continue;
            if(i+1==num.size()) num.push_back(0)
            num[i+1]+=num[i]/10;
            num[i]%=10;
        }
    }
    vector<int> num;
};
ostream &operator<<(ostream &out,BigInt &b){
    for(int i=b.num.size()-1,i>0,--i){
        out<<b.num[i];
    }
    return out;
}

int main(){
    BigInt a(0),b(1),c(0)；
    int n；
    cin >> n;
    while(n--){
        c=a+b;
        a=b;
        b=c;
    }
    cout<<b<<endl;
    return 0;
}

