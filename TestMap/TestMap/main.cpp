//
//  main.cpp
//  TestMap
//
//  Created by lingkun kong on 2018/9/22.
//  Copyright © 2018年 lingkun kong. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<"hello world\n";
    
    //construct
    std::map<char,int> first;
    
    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;
    
    std::map<char,int> second (first.begin(),first.end());
    
    std::map<char,int> third (second);
    
    std::map<char,int,classcomp> fourth;                 // class as Compare
    
    bool(*fn_pt)(char,char) = fncomp;
    std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
    cout<<first.size()<<endl;
    
    //visit
    cout<<first['a']<<endl;
    cout<<first['f']<<endl; //如果没有会新建一个
    
    //iterator
    map<char, int>::iterator it;
    it =  first.begin();
    while(it != first.end()) {
        cout<<(*it).first<< ":"<<(*it).second<<endl;
        it++;
    }
    
    //insert
    std::pair<std::map<char, int>::iterator,bool> ret;
    ret = first.insert (std::pair<char,int>('e',300));
    cout<<ret.second<<endl; //true
    ret = first.insert (std::pair<char,int>('e',400));
    cout<<ret.second<<endl;  //false
    
    it = first.insert (it, std::pair<char,int>('b',300));  //指定位转置插入，
    cout<<(*it).second<<endl;
    
    it = first.begin();
    it = first.insert (it, std::pair<char,int>('g',300));
    cout<<(*it).second<<endl;
    
    it = first.insert(it, std::pair<char, int>('h', 400)); //指定位转置插入，拉果刚好是按顺序插入的位置，可以加快插入速度
    
    it = first.begin();
    while(it != first.end()) {
        cout<<(*it).first<< ":"<<(*it).second<<endl;
        it++;
    }
    
    //可以用来判断，map中有没有此key
   long c =  first.count('a');
    cout<<c<<endl;
    c = first.count('z');
    cout<<c<<endl;
    
  
    
//
    return 0;
}
