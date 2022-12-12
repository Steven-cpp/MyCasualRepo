#include "base.h"
#include <array>
using namespace std;

class DynamicProg {
public:
    /*
     * Perform one transaction, and get the maximum profit.
     * 
     * Try to resolve this problem with dynamic programming, by defining states as:
     *   - dp[i][0][1]: On `i`th day, NOT hold stock, at most 1 chance to transact before this day, the maximum profit
     *   - dp[i][1][0]: On `i`th day, hold stock, 0 chance to transact, the maximum profit
     * 
     * @param[in] prices[n]: price of the stock in `n` days
     */
    int maxProfit(vector<int>& prices) {
        // 1. define and initialize dp
        int ndays = prices.size();
        vector<vector<vector<int>>> dp(ndays, vector<vector<int>>(2, vector<int>(2)));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        // 2. define state transfer equation
        for (int i = 1; i < ndays; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return 0;
    }
};

int main(){
    return 0;
}