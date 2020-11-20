/*************************************************************************
	> File Name: 131.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年07月25日 星期四 13时50分33秒
 ************************************************************************/

#include<stdio.h>
int main(){
    int n,m;
    int lnum=10001,hnum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
		if((m<=lnum)&&(m>=hnum)){
		    lnum=m;
			hnum=m;
		}
		else if(m<=lnum){
		    lnum=m;
		}
		else if(m>=hnum){
		    hnum=m;
		}
		else{
		    continue;
		}
    }
    printf("%d",hnum-lnum);
}
