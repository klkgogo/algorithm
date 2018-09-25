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
    T *prev;
    T *next;
    
    node(const T& d, T *p = NULL, T *n = NULL) {
        data = d;
        prev = p;
        next = n;
    };
    friend ostream& operator<<(ostream& out, const node<T>& p)
    {
        out<<p.data << " next:"<< p.next << " prev:"<< p.prev <<endl;
        return out;
    };
};


//template <class T>
//class myList {
//public:
//    node<T> *head;
//    node<T> *tail;
////    myList();
////    void insert(T n);
////    void delete(node<T> *p);
//};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    point p(1,2, (char*)"hello");
    cout<<p<<endl;
    node<point> n(p);
    cout<<n<<endl;
    cout<<&p<<endl;
    cout<<&n.data<<endl;
    n.data.a = 0;
    cout<<p<<endl;
    cout<<n<<endl;
    return 0;
}
