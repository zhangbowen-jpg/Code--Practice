/*************************************************************************
	> File Name: binary_tree.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2019年10月30日 星期三 16时34分20秒
 ************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<time.h>

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
}Node;

typedef struct Tree {
    Node *root;
    int n; //节点数
}Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insertNode(Node *root, int val,int *flag) { //在插入结点时使用标记位记录节点数n
    if(root == NULL) {
        *flag = 1;
        return getNewNode(val);
    }
    if(root->val == val) return root;
    if(root->val > val) root->lchild = insertNode(root->lchild, val, flag);
    else root->rchild = insertNode(root->rchild, val, flag);
    return root;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag); //这里是插入节点操作,返回值是地址。
    tree->n += flag;
    return ;
}

void clearNode(Node *node) {
    if(node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void clearTree(Tree *tree) {
    if(tree->root == NULL) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

void outputNode(Node *root) {
    if(root == NULL) return ;
    printf("%d", root->val);
    if(root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
} // 二叉排序树打印

void output(Tree *tree) {
    if(tree == NULL) return ;
    printf("tree(%d) = ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;
}

void in_orderNode(Node *node) {
    if(node == NULL) return ;
    in_orderNode(node->lchild);
    printf("%d ",node->val);
    in_orderNode(node->rchild);
    return ;
}

void in_order(Tree *tree) { //中序遍历
    printf("in_order(%d) = ", tree->n);
    in_orderNode(tree->root);
    printf("\n");
}

void pre_orderNode(Node *node) { //前序遍历
    if(node == NULL) return ;
    printf("%d ",node->val);
    pre_orderNode(node->lchild);
    pre_orderNode(node->rchild);
    return ;
}

void pre_order(Tree *tree) { //前序遍历
    printf("pre_order(%d) = ", tree->n);
    pre_orderNode(tree->root);
    printf("\n");
}

void post_orderNode(Node *node) { //后序遍历
    if(node == NULL) return ;
    post_orderNode(node->lchild);
    post_orderNode(node->rchild);
    printf("%d ",node->val);
    return ;
}

void post_order(Tree *tree) { //后序遍历
    printf("post_order(%d) = ", tree->n);
    post_orderNode(tree->root);
    printf("\n");
}


int main() {
    srand(time(0));
    Tree *tree = getNewTree();
    #define max_op 2019
    for(int i = 0; i < max_op; i++) {
        int val = rand()%100;
        insert(tree, val);
    }
    output(tree);
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clearTree(tree);
    return 0;
}


