/*************************************************************************
	> File Name: leetcode-110.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月29日 星期二 20时35分04秒
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;

int getDepth(TreeNode *root) {
    if(root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    if(abs(l - r) > 1) return -2;
    return (l > r ? l : r) + 1;   //
}
bool isBalanced(Tree) {
    return getDepth(root) 所有路径>= 0;
}
