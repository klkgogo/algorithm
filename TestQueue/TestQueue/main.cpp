//
//  main.cpp
//  TestQueue
//
//  Created by lingkun kong on 2018/9/22.
//  Copyright © 2018年 lingkun kong. All rights reserved.
//

#include <iostream>
#include <queue>
#include <list>
#include <deque>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::deque<int> mydeck (3,100);        // deque with 3 elements
    std::list<int> mylist (2,200);         // list with 2 elements
    
    std::queue<int> first;                 // empty queue
    std::queue<int> second (mydeck);       // queue initialized to copy of deque
    
    std::queue<int,std::list<int> > third; // empty queue with list as underlying container
    std::queue<int,std::list<int> > fourth (mylist);
    
    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of second: " << second.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';

    first.push(1);
    first.push(2);
    first.push(3); //入队
    
    cout<<first.front()<<endl; //访问第一个元素
    cout<<first.back()<<endl; //访问最后一个元素
    first.pop(); // 出队
    cout<<first.front()<<endl;
    
    while(!first.empty()) {
        cout<<" "<<first.front();
        first.pop();
    }
    
    
    return 0;
}
