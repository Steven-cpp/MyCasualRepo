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
private:
    const static bool sortBySize(string s1, string s2){
        return s1.length() < s2.length();
    }
};

int main(){
    Solution s;
    cout << "res = " << s.minWindow("bbaa", "aba") << endl;
}