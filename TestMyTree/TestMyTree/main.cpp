//
//  main.cpp
//  TestMyTree
//
//  Created by lingkun kong on 2018/9/25.
//  Copyright © 2018年 lingkun kong. All rights reserved.
//

#include <iostream>
using namespace std;

template <class T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    
    TreeNode(const T& d, TreeNode<T> *l = NULL, TreeNode<T> *r = NULL){
        data = d;
        left = l;
        right = r;
    }
    
    TreeNode<T> * insert(const T&d);
    void del(const T&d);
    void print();
};

template <class T>
TreeNode<T> * TreeNode<T>::insert(const T &d) {
    if (data >= d){
        if (this->left) {
          this->left->insert(d);
        } else {
            TreeNode<T> *node = new TreeNode<T>(d);
            this->left = node;
        }
    } else {
        if (this->right) {
            this->right->insert(d);
        } else {
            TreeNode<T> *node = new TreeNode<T>(d);
            this->right = node;
        }
    }
    return this;
}

template <class T>
void  TreeNode<T>::print() {
    if (this->left) {
        this->left->print();
    }
    cout<<this->data<<endl;
    if (this->right) {
        this->right->print();
    }
}

template <class T>
class Tree {
private:
    TreeNode<T> *root;
public:
    Tree() {root = NULL;};
    void insert(const T& d){
        if (root == NULL) {
            TreeNode<T> *node = new TreeNode<T>(d);
            root = node;
            return;
        }
        root->insert(d);
    }
    
    void print() {
        if (root) {
            root->print();
        }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    Tree<int> tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(6);
    tree.insert(4);
    tree.print();
    std::cout << "Hello, World!\n";
    return 0;
}
