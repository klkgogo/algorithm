//
//  main.cpp
//  TestVector
//
//  Created by klkgogo on 2018/9/21.
//  Copyright © 2018年 Tencent. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v = vector<int>();
    
    vector<int> v2 = vector<int>(10, 0);
    vector<int>::iterator it = v2.begin();
    for (int i = 0; i < v2.size(); i++) {
        *(it + i)  = i;
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 10);
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    v.insert(v.begin() + 1, 33);
    v.erase(v.begin() + 1);
    for (int i = 0; i < 10; i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    v.clear();

    
    //反向迭代，rbegin指向最后一个元素，rit++向前移一个元素。
    vector<int>::reverse_iterator rit = v2.rbegin();
    for (int i = 0; i < v2.size(); i++) {
        *(rit + i)  = i;
    }
    
    for (int i = 0; i < v2.size(); i++) {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    
    int a[10] = {3, 4, 5, 6, 9, 7, 2, 1, 8, 0};
    vector<int> v3 = vector<int>(a, a+10);
    //正向排序
    sort(v3.begin(), v3.end());
    for (int i = 0; i < v3.size(); i++) {
        cout<<v3[i]<<" ";
    }
    cout<<endl;
    
    //反向排序
    sort(v3.rbegin(), v3.rend());
    for (int i = 0; i < v3.size(); i++) {
        cout<<v3[i]<<" ";
    }
    cout<<endl;
    
    
 
    return 0;
}
