class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size());
        std::stack<std::pair<int, int>> st;
        for (int i{}; i < temperatures.size(); ++i) {
            const auto temperature{ temperatures.at(i) };
            while (!st.empty() && temperature > st.top().second) {
                const auto item{ st.top() };
                st.pop();
                result.at(item.first) = i - item.first;
            }
            st.push({i, temperature});
        }

        return result;
    }
};
