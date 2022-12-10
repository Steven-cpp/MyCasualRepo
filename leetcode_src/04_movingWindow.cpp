#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.cpp"
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Sample: "EASABTC", "ABC" --> "ABTC"
        // 1. 定义窗口
        int left = 0, right = 0;
        bool shrinked = false;
        vector<string> res;
        while (right < s.length()){
            // 2. 拉伸窗口,直至满足条件
            right++;
            // 3. 缩小窗口,直至不满足条件
            while (containStr(s.substr(left, right - left), t)){
                left++;
                shrinked = true;
            }
            // 4. 保存优化后的结果
            if (shrinked){
                shrinked = false;
                res.push_back(s.substr(left - 1, right - left + 1));
            }
        }
        if (res.size() == 0) return "";
        sort(res.begin(), res.end(), sortBySize);
        return res[0];
    }
private:
    const static bool containStr(string src, string tar){
        int id = 0;
        if (tar.length() == 0) return true;
        if (src.length() < tar.length()) return false;
        if ((id = src.find(tar[0])) == -1) return false;
        else if (tar.length() == 1) return true;
        else {
            src.erase(id, 1);
            return containStr(src, tar.substr(1, tar.length()-1));
        }
    }
    const static bool sortBySize(string s1, string s2){
        return s1.length() < s2.length();
    }
};

int main(){
    Solution s;
    cout << "res = " << s.minWindow("bbaa", "aba") << endl;
}