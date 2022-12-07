#include <iostream>
#include <queue>
#include "structs.h"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                auto cur = q.front();
                if (cur == nullptr)
                    continue;
                q.pop();
                if (cur->left == nullptr && cur->right == nullptr)
                    return depth;
                q.push(cur->left);
                q.push(cur->right);
            }
            depth++;
        }
        return depth;
    }
};

int main(){
    
}