#include <vector>
#include <iostream>
//  Just for convenience, better include ".h" only
#include "utils.cpp"
using namespace std;

vector<vector<int>> res;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> route;
        return permute_rec(nums, route);
    }
private:
    vector<vector<int>> permute_rec(vector<int>& nums, vector<int> route) {
        if (nums.size() == 1){
            route.push_back(nums[0]);
            res.push_back(route);
            return res;
        }
        
        for (auto i = nums.begin(); i != nums.end(); i++){
            route.push_back(*i);
            nums.erase(i);
            permute_rec(nums, route);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution s;
    auto lists = s.permute(nums);
    for (auto l: lists){
        printList(l);
    }
}