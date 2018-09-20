//
//  main.cpp
//  TestSort
//
//  Created by lingkun kong on 2018/9/20.
//  Copyright © 2018年 lingkun kong. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
bool bigger(int i, int j) {
    return i > j;
}

struct point {
    int x;
    int y;
};

bool pointCmp(point p1, point p2) {
    return p1.x < p2.x;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10] = {3, 4, 5, 6, 9, 7, 2, 1, 8, 0};
    sort(a, a + 10);
    cout<<sizeof(a) / sizeof(int)<<endl;
    for (int i = 0; i < 10; i ++) {
        cout<<a[i] << " " ;
    }
    cout<<endl;
    
    sort(a, a + 10, bigger);
    for (int i = 0; i < 10; i ++) {
        cout<<a[i] << " " ;
    }
    cout<<endl;
    point p1 ={3, 2};
    point p2 ={1, 4};
    point p3 ={5, 2};
    point p4 ={1, 7};
    point p5 ={8, 2};
    point p6 ={9, 4};
    
    point p[6] = {p1, p2, p3, p4, p5, p6};
    sort(p, p + 6, pointCmp);
    
    for (int i = 0; i < 6; i ++) {
        cout<<p[i].x  << " " << p[i].y <<endl ;
    }

    return 0;
}
