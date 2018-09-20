//
//  main.cpp
//  TestString
//
//  Created by lingkun kong on 2018/9/20.
//  Copyright © 2018年 lingkun kong. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "hello";
    string s1("hi");
    string s2 = s1;
    string s3(s2);
    string s4 = s.substr(3); // 3 to end
    cout<<"s4 "<<s4<<endl;
    string s5 = s.substr(1, 4);
    cout<<"s5 "<<s5<<endl;
    
    cout<<s[1]<<endl;
    
    reverse(s.begin(), s.end());
    std::cout << s << endl;
    
    string str="to be question";
    string str2="the ";
    string str3="or not to be";
    
    str.insert(6, str2);
    cout<<"str "<<str<<endl;
    
    string ret = str.insert(6,str3,3,4);
    cout<<"str "<<str<<endl;
    cout<<"ret "<<ret<<endl;
    
    string::iterator it;
    it = str.insert(str.begin() + 2, ':');
    cout<<str<<endl;
    cout<<*it<<endl;
    cout<<it[0]<<endl;
    cout<<*(it + 2)<<endl;
    
    str.insert(it + 1, s.rbegin(), s.rend());
    cout<<str<<endl;
    
    cout<<*(s.rbegin() + 1)<<endl;
    cout<<*(s.rend() - 2)<<endl;
    
    

    return 0;
}
