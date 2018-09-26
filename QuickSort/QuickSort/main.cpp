//
//  main.cpp
//  QuickSort
//
//  Created by klkgogo on 2018/9/20.
//  Copyright © 2018年 Tencent. All rights reserved.
//

#include <iostream>
using namespace std;

void sort(int *array, int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    freopen("/Users/lingkunkong/Desktop/data.txt", "r", stdin);
    int n;
    cin>>n;
    int *array =(int *) malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i ++) {
        cin>>array[i];
    }
    sort(array , n);
    for (int i = 0; i < n; i ++) {
        cout<<array[i]<<" ";
    }
    if (array) free(array);
    return 0;
}

void sort(int *array, int n) {
    int l = 0;
    int r = n - 1;
    if (n < 2) return;
    int key = array[0];
    while (l < r) {
        while (array[r] > key && l < r) r--;
        if (l == r) break;
        int tmp = array[l];
        array[l] = array[r];
        array[r] = tmp;
        l++;
        
        while (array[l] < key && l < r) l++;
        if(l == r)break;
        tmp = array[l];
        array[l] = array[r];
        array[r] = tmp;
        r--;
        
    }
    sort(array, l);
    sort(array + l + 1, n - l - 1);
    
}
