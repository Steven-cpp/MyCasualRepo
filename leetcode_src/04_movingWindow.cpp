#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "utils.cpp"
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // Sample: "EASABTC", "ABC" --> "ABTC"
        // 1. 定义窗口
        map<char, int> need, window;
        int left = 0, right = 0;
        int validCh = 0;
        bool shrinked = false;
        vector<string> res;
        for (auto c: t)
            need[c]++;
        while (right < s.length()){
            // 2. 拉伸窗口,直至满足条件
            char tarCh = s[right];
            if (need.count(tarCh) > 0){
                window[tarCh]++;
                if (window[tarCh] == need[tarCh])
                    validCh++;
            }
            right++;
            // 3. 缩小窗口,直至不满足条件
            while (validCh == need.size()){
                tarCh = s[left++];
                shrinked = true;
                if (need.count(tarCh) > 0){
                    window[tarCh]--;
                    if (window[tarCh] < need[tarCh])
                        validCh--;
                }
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

    bool checkInclusion(string s1, string s2) {
        // 判断s2是否包含s1的排列
        // 1. 定义窗口和条件

        // 2. 遍历s2, 判断ch是否为目标字符
        // 2.1 不是目标字符, left++
        // 2.2 是目标字符, 拉伸窗口
            // 3. 如果满足条件, left <- right - s1.length
            //    [判断当前窗口是否是s1的组合] <- 计算量较大
            // 3.1 如果是, 返回 True
            // 3.2 如果不是, left <- 窗口的第二个元素

    }
private:
    const static bool sortBySize(string s1, string s2){
        return s1.length() < s2.length();
    }
};

int main(){
    Solution s;
    cout << "res = " << s.minWindow("bbaa", "aba") << endl;
}