#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findKSubArray(vector<int> arr, int k){
    // 找到和能被k整除的所有子集
    return 0;
}

vector<long long> minimumCost(vector<int> red, vector<int> blue, int blueCost) {
    
    vector<long long> ans = {0};
    int n = red.size();
    vector<vector<long>> dp(n+1, vector<long>(2));
    dp[0][0] = 0;
    dp[0][1] = blueCost;

    for (int i = 1; i <= n; i++){
        // dp[i][0]: 到第i个城市的最少cost(当前不在Blue线)
        // red[i]: 到第(i+1)个城市的开销
        dp[i][0] = min(dp[i-1][0] + red[i-1], dp[i-1][1] + red[i-1]);
        dp[i][1] = min(dp[i-1][0] + blue[i-1] + blueCost, dp[i-1][1] + blue[i-1]);
        ans.push_back(min(dp[i][0], dp[i][1]));
    }
    
    return ans;
}




int main()
{
    vector<int> red = {40, 50, 25, 10, 50};
    vector<int> blue = {30, 15, 20, 11, 15};
    auto res = minimumCost(red, blue, 25);
    cout << "res = [";
    for (auto item: res){
        cout << item << ", ";
    }
    cout << "\b\b]" << endl;
    return 0;
}

