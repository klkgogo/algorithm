//
//  main.cpp
//  TestList
//
//  Created by lingkun kong on 2018/9/22.
//  Copyright © 2018年 lingkun kong. All rights reserved.
//

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    list<int> l;
    for (int i = 0; i < 10; i++) {
        l.push_back(i);
    }
    list<int>::iterator i;   //list 的iterator只支持++ --操作。
    for ( i = l.begin(); i != l.end(); i++) {
        cout<<*i<< " ";
    }
    cout<<endl;
    i = l.begin();
    i = i++;
    cout<<*i<<endl;
    cout<<endl;
    
    list<int> l2 = l;

    for ( i = l2.begin(); i != l2.end(); i++) {
        cout<<*i<< " ";
    }
    cout<<endl;
    
    list<int> l3(l2.begin(), l2.end());
    for ( i = l3.begin(); i != l3.end(); i++) {
        cout<<*i<< " ";
    }
    cout<<endl;
    l3.pop_back();
    for ( i = l3.begin(); i != l3.end(); i++) {
        cout<<*i<< " ";
    }
    cout<<endl;
    
    l3.push_front(10);
    for ( i = l3.begin(); i != l3.end(); i++) {
        cout<<*i<< " ";
    }
    cout<<endl;
    
    i = l3.begin();
    advance(i, 6);
    l3.erase(i);
    for ( i = l3.begin(); i != l3.end(); i++) {
        cout<<*i<< " ";
    }
    cout<<endl;
    
    i = l3.begin();
    advance(i, 6);
    l3.insert(i, 5);
    for ( i = l3.begin(); i != l3.end(); i++) {
        cout<<*i<< " ";
    }
    cout<<endl;
    
    
    l3.sort();
    for ( i = l3.begin(); i != l3.end(); i++) {
        cout<<*i<< " ";
    }
    cout<<endl;
    
    
    return 0;
}
