//
//  main.cpp
//  TestSet
//
//  Created by lingkun kong on 2018/9/22.
//  Copyright © 2018年 lingkun kong. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

bool fncomp (int lhs, int rhs) {return lhs>rhs;}

void testPerson();

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[7] = {4, 3, 6, 8, 9, 2, 1 };  //set不支持重复， multiset支持重复
    set<int> s(a, a + 7);
    set<int>::iterator it;
    it = s.begin();
    while(it != s.end()) {
        cout<<*it++<<" ";
    }
    cout<<endl;
    
    set<int> s2(s);
    cout<<s2.size()<<endl;
    
    
    // 反序排列
    bool(*fn_pt)(int,int) = fncomp;
    set<int, bool(*)(int,int)> s3(fn_pt);
    
    for (int i=1; i<=5; ++i) s3.insert(i*10);
    it = s3.begin();
    while(it != s3.end()) {
        cout<<*it++<<" ";
    }
    cout<<endl;
    std::pair<std::set<int>::iterator,bool> ret;
    ret = s3.insert(20);  //成功失败
    cout<<ret.second<<endl;  //false
    ret = s3.insert(21); //插入成功
    cout<<ret.second<<endl; // true
    
    it = s3.begin();
    while(it != s3.end()) {
        cout<<*it++<<" ";
    }
    cout<<endl;
    
    it=s3.find(20); //找不到反回set::end
    cout<<"find 20:"<<*it<<endl;
    cout<<"is set::end "<< (it == s3.end())<<endl;
    
    it=s3.find(1000); //not find return set::end
    cout<<"find 100:"<<*it<<endl;
    cout<<"is set::end "<< (it == s3.end())<<endl;
    
    s3.erase(s3.find(20));
    
    
    testPerson();
    
    std::cout << "Hello, World!\n";
    return 0;
}

class Person {
public:
    Person(string name, int age) {
        mName = name;
        mAge = age;
    }
public:
    string mName;
    int mAge;
    
};

class ComparePerson {
public:
    bool operator()(const Person &p1, const Person &p2) {
        if (p1.mAge < p2.mAge) {
            return true;
        } else {
            return p1.mName < p2.mName;
        }
    }
};


void testPerson() {
    set<Person, ComparePerson> s;
    s.insert(Person("John", 22));
    s.insert(Person("Peter", 25));
    s.insert(Person("Marry", 18));
    s.insert(Person("Peter", 36));
    
    set<Person>::iterator it;
    
    for (it = s.begin(); it != s.end(); it++) {
        cout<< (*it).mName <<":"<<(*it).mAge<<endl;
    }
    
}
