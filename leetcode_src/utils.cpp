#include <vector>
#include <iostream>
using namespace std;

// 实现leetcode的调试工具类，包括:
// 1. vector的打印与输入;
// 2. 

void printList(vector<int> arr){
    cout << "[";
    for (auto i: arr)
        cout << i << ", ";
    cout << "\b\b]" << endl;
}