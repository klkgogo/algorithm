//
//  main.cpp
//  TestStack
//
//  Created by lingkun kong on 2018/9/22.
//  Copyright © 2018年 lingkun kong. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    stack<int> s;
    for (int i = 0; i < 10; i++) s.push(i);
    cout<<s.size()<<endl;
    
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    
    while (!s.empty())
    {
        std::cout << ' ' << s.top();
        s.pop();
    }
    
    
    vector<int> v = vector<int>(10, 2);
    stack<int, vector<int>> s2(v); //从一个动态数组创建stack
    cout<<endl<<"s2 size: "<<s2.size()<<endl;
    while (!s2.empty())
    {
        std::cout << ' ' << s2.top();
        s2.pop();
    }
    
    
    

    return 0;
}
