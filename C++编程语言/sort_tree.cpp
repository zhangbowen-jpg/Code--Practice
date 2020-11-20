/*************************************************************************
	> File Name: sort_tree.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月14日 星期六 18时30分21秒
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

template<typename T> 
class Node {
public :
    Node() = default;
    Node(T t) : value(t), lchild(nullptr), rchild(nullptr) {} //先指向空地址

    T value;
    Node<T> *lchild; 
    Node<T> *rchild;
    Node<T> *parent;
};

template<typename T>
class Tree {
public :
    Tree():root(nullptr) {};
    Node<T>* find(T key);  //查找方法
    Node<T>* pre(Node<T> *x);   //前驱
    void insert(T* arr, int x, int y);
    void erase(T* arr, int x, int y);
    void erase(T key);   
    void preOrder();      //先序遍历，测试用
    void destory();
    void insert(T key);
    ~Tree() {
        destory(root);
    };
private :     //内部使用(外部传值，内部递归)
    Node<T>* root;
    Node<T>* find(Node<T>* &p, T key);
    void erase(Node<T>* p, T key);
    void preOrder(Node<T>* p);
    void destory(Node<T>* &p);
};


template<typename T> 
void Tree<T>::insert(T x) {
    Node<T>* pparent = nullptr;
    Node<T>* pnode = root;
    while(pnode != nullptr) { //找插入位置
        pparent = pnode;
        if(x > pnode->value) pnode = pnode->rchild; //大右小左
        else if(x < pnode->value) pnode = pnode->lchild;
        else break;
    }
    pnode = new Node<T>(x);
    if(pparent == nullptr) root = pnode; //空树?
    else {
        if(x > pparent->value) pparent->rchild = pnode;
        else pparent->lchild = pnode;
    }
    pnode->parent = pparent;  
};

template<typename T>
void Tree<T>::insert(T* arr, int x, int y) {
    for(int i = x - 1; i < y; i++) {
        insert(*(arr + i));
    }
};


template<typename T>
Node<T>* Tree<T>::find(T t) {
    Node<T>* pnode = root;
    while(pnode != nullptr) {
        cout << "->" << pnode->value << endl;   //打印查找顺序
        if(t == pnode->value) return pnode;
        if(t > pnode->value) pnode = pnode->rchild;
        else pnode = pnode->lchild;
    }
    return nullptr;
};

template<typename T>
void Tree<T>::erase(T* arr, int x, int y) {
    for(int i = x - 1; i < y; i++) {
        erase(*(arr + i));
    }
}

template<typename T>
void Tree<T>::erase(T t) {
    erase(root, t);
};

template<typename T>
void Tree<T>::erase(Node<T>* pnode, T t) {
    if(pnode != nullptr) {
        if(pnode->value == t) {
            Node<T>* ptmp = nullptr;
            if(pnode->lchild == nullptr || pnode->rchild == nullptr) ptmp = pnode; //一个或没有孩子
            else ptmp = pre(pnode);  //删除前驱
            Node<T>* pchild = nullptr;
            if(ptmp->lchild != nullptr) pchild = ptmp->lchild; //判断左右孩子
            else pchild = ptmp->rchild;
            if(pchild != nullptr) pchild->parent = ptmp->parent; //连接
            if(ptmp->parent == nullptr) root = pchild; //根
            else if(ptmp->parent->lchild == ptmp) ptmp->parent->lchild = pchild;
            else ptmp->parent->rchild = pchild;
            if(pnode->value != ptmp->value) pnode->value = ptmp->value;
            delete ptmp;
        }
        else if(t > pnode->value) erase(pnode->rchild, t);
        else erase(pnode->lchild, t);
    }
};

template<typename T> 
Node<T>* Tree<T>::pre(Node<T>* pnode) {
    if(pnode->lchild != nullptr) { //有左子树，左孩子为前驱
        pnode = pnode->lchild;
        while(pnode->rchild != nullptr) {
            pnode = pnode->rchild;
        }
        return pnode;
    }
    Node<T>* pparent = pnode->parent;
    while(pparent != nullptr && pparent->lchild == pnode) {
        pnode = pparent;
        pparent = pparent->parent;
    }
    return pparent;
}

template<typename T>
void Tree<T>::preOrder() {
    preOrder(root);
};

template<typename T> 
void Tree<T>::preOrder(Node<T>* p) {
    if(p != nullptr) {
        cout << p->value << endl;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
};

template<typename T>
void Tree<T>::destory(Node<T>* &p) {
    if(p != nullptr) {
        if(p->lchild != nullptr) destory(p->lchild);
        if(p->rchild != nullptr) destory(p->rchild);
        delete p; 
    }
};



int main() {
    Tree<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(5);
    tree.insert(8);
    tree.insert(9);
    tree.insert(7);
    cout << "先序遍历: " << endl;
    tree.preOrder();
    cout << endl;
    Node<int> *p;
    p = tree.find(5);  
    cout << endl;
    tree.erase(5);
    tree.erase(1);
    cout << "删除1和5之后的先序遍历: " << endl;
    tree.preOrder();
    cout << endl;
    Tree<double> tree1;
    tree1.insert(3.2);
    tree1.insert(1.8);
    tree1.insert(2.0);
    tree1.insert(4.3);
    tree1.insert(5.5);
    tree1.insert(8.9);
    tree1.insert(9.1);
    tree1.insert(7.5);
    cout << "先序遍历: " << endl;
    tree1.preOrder();
    cout << endl;
    tree1.erase(5.5);
    tree1.erase(1.8);
    cout << "删除1.8和5.5之后的先序遍历: " << endl;
    tree1.preOrder();
    cout << endl; 
    Tree<int> tree2;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    tree2.insert(arr, 2, 8);
    tree2.preOrder();
    cout << endl; 
    Tree<double> tree3;
    double arr2[10] = {6.5,7.6,8.5,9.1,10.2,5.5,4.4,3.1,2.8,1.9};
    tree3.insert(arr2, 2, 8);
    tree3.preOrder();
    cout << endl;
    tree3.erase(arr2, 2, 5);
    tree3.preOrder();
    return 0;
}



