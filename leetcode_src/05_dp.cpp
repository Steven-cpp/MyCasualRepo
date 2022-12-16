#include "base.h"
#include <array>
using namespace std;

class DynamicProg {
public:
    /*
     * Perform one transaction, and get the maximum profit.
     * 
     * Try to resolve this problem with dynamic programming, by defining states as:
     *   - dp[i][1][0]: On `i`th day, at most 1 chance to transact before this day, NOT hold stock, the maximum profit
     *   - dp[i][0][1]: On `i`th day, 0 chance to transact, hold stock, the maximum profit
     *   - dp[i][0][0]: On `i`th day, 0 chance to transact, NOT hold stock, the maximum profit
     * 
     * @param[in] prices[n]: price of the stock in `n` days
     */
    int maxProfit(vector<int>& prices) {
        // 1. define and initialize states `dp`
        int ndays = prices.size();
        vector<vector<vector<int>>> dp(ndays, vector<vector<int>>(2, vector<int>(2)));
        dp[0][1][1] = -prices[0];
        dp[0][1][0] = 0;

        // 2. define state transfer equation
        for (int i = 1; i < ndays; i++){
            dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);
            dp[i][1][1] = max(dp[i-1][1][1], -prices[i]);
        }
        return dp[ndays-1][1][0];
    }
};

int main(){
    DynamicProg dp;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "maxProfit = " << dp.maxProfit(prices) << endl;
}