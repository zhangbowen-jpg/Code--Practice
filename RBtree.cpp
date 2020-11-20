/*************************************************************************
	> File Name: RBtree.cpp
	> Author: zhangbowen
	> Mail: 
	> Created Time: 2020年02月16日 星期日 19时34分24秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define RED 0
#define BLACK 1
#define DOUBLE_BLACK 2

typedef struct Node {
    int key, color; // 0 red, 1 black, 2 double black
    struct Node *lchild, *rchild;
} Node;

Node _NIL, * const NIL = &_NIL;

__attribute__((constructor))  //在主函数之前执行
void init_NIL() {
    NIL->key = 0; //初始化NIL的键值0
    NIL->lchild = NIL->rchild = NIL;
    NIL->color = BLACK; //默认NIL黑色
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NIL;
    p->color = RED;
    return p;
}

int hasRedChild(Node *root) {
    return root->lchild->color == RED || root->rchild->color == RED;
}

Node *left_rotate(Node *root) {  //左旋
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_rotate(Node *root) { //右旋
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!hasRedChild(root)) return root;  //没有冲突，直接返回
    if (root->lchild->color == RED && root->rchild->color == RED) {  //左右都为红色
        if (!hasRedChild(root->lchild) && !hasRedChild(root->rchild)) return root; //没有红色孙子节点，直接返回
        goto insert_end; //改为红色上浮类型
    }
    if (root->lchild->color == RED) { //uncle黑色 , L型
        if (!hasRedChild(root->lchild)) return root;  //不发生冲突，返回
        if (root->lchild->rchild->color == RED) { //LR类型
            root->lchild = left_rotate(root->lchild);  //LR类型多一步左旋
        }
        root = right_rotate(root); //外层LL型直接右旋
    } else {
        if (!hasRedChild(root->rchild)) return root; //这回是R型
        if (root->rchild->lchild->color == RED) { //RL型 多一步右旋
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root); //外层RR型直接左旋
    }
insert_end:
    root->color = RED; //红色上浮
    root->lchild->color = root->rchild->color = BLACK;
    return root;
}

Node *__insert(Node *root, int key) { 
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key > key) root->lchild = __insert(root->lchild, key);
    else root->rchild = __insert(root->rchild, key);
    return insert_maintain(root);
}

Node *insert(Node *root, int key) {
    root = __insert(root, key);
    root->color = BLACK;
    return root;
}

Node *predeccessor(Node *root) { //获得前驱
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != DOUBLE_BLACK && root->rchild->color != DOUBLE_BLACK) return root; //无双重黑，返回
    if (root->rchild->color == DOUBLE_BLACK) { //双重黑在右，brother在左，L型
        if (root->lchild->color == RED) { //特殊情况，brother红色
            root->color = RED;
            root->lchild->color = BLACK;  //根边红，brother变黑
            root = right_rotate(root);  //右旋(brother红色在左)
            root->rchild = erase_maintain(root->rchild); //转化为新brother黑色
            return root;
        }
        if (!hasRedChild(root->lchild)) { //brother两子结点全黑
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        } //根+1，子-1
        if (root->lchild->lchild->color != RED) { //通过另一个点判断子结点的颜色，不可以直接判断，LR型
            root->lchild->rchild->color = BLACK;
            root->lchild->color = RED;
            root->lchild = left_rotate(root->lchild); //左旋，改颜色
        }
        root->lchild->color = root->color;
        root->rchild->color -= 1;
        root = right_rotate(root); //LL型， 改颜色， 大右旋
        root->lchild->color = root->rchild->color = BLACK; //仍然是红色上浮
    } else { 
        if (root->rchild->color == RED) { //brother在右，红色
            root->color = RED;
            root->rchild->color = BLACK;
            root = left_rotate(root); //左旋之后转新brother为黑
            root->lchild = erase_maintain(root->lchild);
            return root;
        }
        if (!hasRedChild(root->rchild)) { //brother两子结点全黑
            root->color += 1;
            root->lchild->color -= 1;
            root->rchild->color -= 1;
            return root;
        }
        if (root->rchild->rchild->color != RED) { //RL型
            root->rchild->lchild->color = BLACK;
            root->rchild->color = RED;
            root->rchild = right_rotate(root->rchild); //右旋，改颜色
        }
        root->rchild->color = root->color;
        root->lchild->color -= 1;
        root = left_rotate(root); //RR型 ， 大左旋
        root->lchild->color = root->rchild->color = BLACK; //红色上浮
    }
    return root;
}

Node *__erase(Node *root, int key) { //AVL
    if (root == NIL) return root;
    if (root->key > key) {
        root->lchild = __erase(root->lchild, key);
    } else if (root->key < key) {
        root->rchild = __erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predeccessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        }
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int key) {
    root = __erase(root, key);
    root->color = BLACK;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) { //中序遍历， 左根右
    if (root == NIL) return ;
    output(root->lchild);
    printf("%d %d %d %d\n", 
        root->key, 
        root->color,
        root->lchild->key, 
        root->rchild->key
    );
    output(root->rchild);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 2: root = erase(root, val); break;
            case 3: output(root); break;
        }
    }
    return 0;
}

