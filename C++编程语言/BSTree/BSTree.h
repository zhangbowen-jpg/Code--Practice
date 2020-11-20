/*************************************************************************
	> File Name: BSTree.h
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年03月15日 星期日 14时17分31秒
 ************************************************************************/
#ifndef _BSTREE_H
#define _BSTREE_H

#include<memory>
#include<iostream>

namespace haizei {

template<typename T>
class BSNode {
public :
    BSNode(const T &data) : data(data), lchild(nullptr), rchild(nullptr),father() {
        std::cout << "Node constuctor" << std::endl;
    }
    bool operator<(const BSNode<T> &obj) {
        return this->data < obj.data;
    }
    bool operator>(const BSNode<T> &obj) {
        return obj.data < this->data;
    }
    bool operator!=(const BSNode<T> &obj) {
        return (this->data < obj.data) || (obj.data < this->data);
    }
    bool operator==(const BSNode<T> &obj) {
        return (*this != obj);
    }

    std::weak_ptr<BSNode<T> > father;
    std::shared_ptr<BSNode<T> > lchild, rchild;
    ~BSNode() {
        std::cout << "destructor" << std::endl;
    }
    T data;
};

template<typename T>
class BSTree_helper {
public :
    static std::shared_ptr<BSNode<T> > get_next(std::shared_ptr<BSNode<T> > p) {
        if(p->rchild != nullptr) {
            p = p->rchild;
            while(p->lchild != nullptr) p = p->lchild; 
            return p;
        }
        while(p->father.lock() != nullptr && p->father.lock()->rchild == p) p = p->father.lock();
        if(p->father.lock() == nullptr) return p;
        return p->father.lock();
    }
};

template<typename T>
class BSTree_iterator {
    using helper = BSTree_helper<T>;
public :
    BSTree_iterator() : node(nullptr) {}
    BSTree_iterator(std::shared_ptr<BSNode<T> > node) : node(node) {}
    BSTree_iterator<T> &operator++() {
        node = helper::get_next(node);
        return *this;
    }
    BSTree_iterator<T> operator++(int) {
        BSTree_iterator iter(*this);
        node = helper::get_next(node);

        return iter;
    }
    
    bool operator==(const BSTree_iterator<T> &iter) {
        return this->node == iter.node;
    }
    
    bool operator!=(const BSTree_iterator<T> &iter) {
        return this->node != iter.node;
    }
    
    T &operator*() {
        return node->data;
    }

private :
    std::shared_ptr<BSNode<T> > node; //当前节点
};

template<typename T>
struct BSTree {
public :
    typedef BSTree_iterator<T> iterator;
    BSTree() : root(std::make_shared<BSNode<T> >(T())) {} //构造头节点
    void insert(const T &data) {
        std::shared_ptr<BSNode<T> > p = this->root;
        std::shared_ptr<BSNode<T> > new_node = std::make_shared<BSNode<T> >(data);
        if(p->lchild == nullptr) {
            p->lchild = new_node; //新建一个节点并传入
            //make_shared就是构造一个对象
            new_node->father = p;
            return ;
        }
        p = p->lchild;
        while(*p != *new_node) {
            if (*p > *new_node) {
                if(p->lchild == nullptr) {
                    p->lchild = new_node;
                    new_node->father = p;
                    break;
                }
                p = p->lchild;
            } else {
                if(p->rchild == nullptr) {
                    p->rchild = new_node;
                    new_node->father = p;
                    break;
                }
                p = p->rchild;
            }
        }
        return ;
    }
    void erase(const T &data) {
        
    }
    iterator begin() {
        if(root->lchild == nullptr) return iterator(root);
        return iterator(root->lchild);
    }
    iterator end() {
        return iterator(root);
    }

private :
    std::shared_ptr<BSNode<T> > root;
    //虚拟头节点
};


};
#endif
