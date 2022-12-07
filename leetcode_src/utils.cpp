#include <vector>
#include <iostream>
#include <queue>
#include "structs.h"
using namespace std;

// 实现leetcode的调试工具类，包括:
// 1. vector的打印与输入;
// 2. 根据列表生成二叉树

void printList(vector<int> arr){
    cout << "[";
    for (auto i: arr)
        cout << i << ", ";
    cout << "\b\b]" << endl;
}

TreeNode* genBinTree(vector<int> arr){
    // 根据层序遍历列表 返回所对应二叉树的根 -999代表null
    const int NUM_NULL = -999;
    if (arr.size() == 0 || arr[0] == NUM_NULL){
        cout << "ERROR: The input binTree is Null";
        return nullptr;
    }
    size_t nodeId = 0;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[nodeId++]);
    q.push(root);
    while (!q.empty() && nodeId < arr.size())
    {
        auto cur = q.front();
        q.pop();
        cur->left = new TreeNode(arr[nodeId++]);
        cur->right = new TreeNode(arr[nodeId++]);
        q.push(cur->left);
        q.push(cur->right);
    }
    return root;
}