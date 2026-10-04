class Solution {
public:
    int maxProfit(vector<int>& prices) {
            if (prices.size() < 2) {
                return 0;
            }

            int buy{ prices.at(0) };
            int maxProfit{};
            for (const auto price : prices) {
               maxProfit = std::max(maxProfit, price - buy);
               if (price < buy) {
                buy = price;
               }
            }
            return maxProfit;
    }
};
