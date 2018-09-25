//
//  main.cpp
//  Test
//
//  Created by klkgogo on 2018/9/25.
//  Copyright © 2018年 Tencent. All rights reserved.
//

#include <iostream>
using namespace std;

class point {
public:
    int a;
    int b;
    char c[10];
    point(int _a = 0, int _b = 0, char *_c = NULL) {
        a = _a;
        b = _b;
        if (_c)
            strcpy(c, _c);
    }
    friend ostream& operator<<(ostream& out, const point& p);
};

ostream& operator<<(ostream& out, const point& p)
{
    out<<"("<<p.a<<","<<p.b<< " " << p.c <<")";
    return out;
};


template <class T>
class node {
public:
    T data; 
    node<T> *prev;
    node<T> *next;
    
    node(const T& d, node<T> *p = NULL, node<T> *n = NULL) {
        data = d;
        prev = p;
        next = n;
    };
    friend ostream& operator<<(ostream& out, const node<T>& p)
    {
        out<<p.data << " p:"<< &p << " next:"<< p.next << " prev:"<< p.prev <<endl;
        return out;
    };
};


template <class T>
class myList {
public:
    node<T> *head;
    node<T> *tail;
    myList();
    void insert(const T& e, int pos = 0);
    bool del(int pos);
    int find(const T& e);
    void clear();
    friend ostream& operator<<(ostream& out, const myList<T>& list)
    {
        node<T> *p = list.head;
        while (p != NULL) {
            cout<<*p<<endl;
            p = p->next;
        }
        return out;
    };
};

template <class T>
myList<T>::myList() {
    head = NULL;
    tail = NULL;
}
template <class T>
void myList<T>::insert(const T& e, int pos) {
    node<T> * p;
    p = head;
    node<T> *node = new ::node<T>(e);
    if (p == NULL){
        head = node;
        tail = node;
        return;
    }
    if (pos == 0) {
        node->next = head;
        node->prev = NULL;
        head->prev = node;
        head = node;
        return;
    }
    //找到指定位置的前一个元素。
    while(p->next != NULL && pos > 1){
        p = p->next;
    }
    //p 是tail
    if (p->next == NULL) {
        node->prev = p;
        p->next = node;
        tail = node;
    } else {
        node->next = p->next;
        node->prev = p;
        p->next->prev = node;
        p->next = node;
    }
}

template <class T>
bool myList<T>::del(int pos) {
    node<T> * p = head;
    
    if (pos == 0) {
        head = p->next;
        head->prev= NULL;
        delete p;
        return true;
    }
    
    while(p != NULL && pos > 1) {
        p = p->next;
        pos--;
    }
    
    if (pos > 1 || p == NULL)
        return false;
    
    node<T> *node = p->next;
    p->next = node->next;
    if(node->next == NULL)
    {
        tail = p;
    } else {
        node->next->prev = p;
    }
    delete node;
    return true;
}


template <class T>
int myList<T>::find(const T &e) {
    node<T> *p = head;
    int pos = 0;
    while(p != NULL && p->data != e) {
        p = p->next;
        pos++;
    }
    
    if(p == NULL) {
        return -1;
    }
    return pos;
}

template <class T>
void myList<T>::clear() {
    node<T> *p = head;
    while(p != NULL) {
        node<T> *next = p->next;
        delete p;
        p = next;
    }
    head = NULL;
    tail = NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    myList<int> list;
    for (int i = 0; i < 10; i++) {
        list.insert(i);
    }
    list.insert(22, 1);
    list.insert(11, 11);
    list.insert(13, 100);
    cout<<list<<endl;
    
    list.del(1);
    cout<<list<<endl;
    
    list.del(0);
    cout<<list<<endl;
    
    list.del(10);
    cout<<list<<endl;
    
    cout<<list.find(11)<<endl;
    cout<<list.find(8)<<endl;
    cout<<list.find(7)<<endl;
    cout<<list.find(33)<<endl;
    
    list.clear();
    cout<<list<<endl;
    
    return 0;
}
