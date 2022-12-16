#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1. define two pointers `start`, `end`
        int n = nums.size();
        int start = 0, end = n - 1;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        // 2. iterate over `end`
        for (; end > 1 && nums[end] >= 0; end--){
            // 3.  iterate over `start`
            for (start = 0; start < end - 1 && nums[start] <= 0; start++){
                // 3.1 sum > 0, need small value, set `mid = start + 1`
                int curSum = nums[start] + nums[end];
                if (curSum > 0){
                    // 4.  iterate over `mid`
                    for (int mid = start + 1; mid < end; mid++){
                        int sum3 = curSum + nums[mid];
                        // 4.1 sum > 0, this path has dead
                        if (sum3 > 0) {
                            start = end - 1;
                            break;
                        }
                        // 4.2 sum == 0, add result
                        if (sum3 == 0) {
                            vector<int> res_item = {nums[start], nums[mid], nums[end]};
                            res.push_back(res_item);
                        }
                    }
                    // 4.3 sum < 0, st++ (do nothing is fine)
                }
                
                // 3.2 sum <= 0, need bigger value, set `mid = end - 1`
                else {
                    for (int mid = end - 1; mid > start; mid--){
                        int sum3 = curSum + nums[mid];
                        if (sum3 < 0) break;
                        if (sum3 == 0) {
                            vector<int> res_item = {nums[start], nums[mid], nums[end]};
                            res.push_back(res_item);
                            break;
                        }
                    }
                }
            }
        }
        set<vector<int>> resDif(res.begin(), res.end());
        res.assign(resDif.begin(), resDif.end());
        return res;     
    }
};
 
int main(int argc, char* argv[]) {
    Solution s;
    vector<int> vals = {-2,0,1,1,2};
    auto res = s.threeSum(vals);
    cout << res.size() << endl;
    return 0;
}