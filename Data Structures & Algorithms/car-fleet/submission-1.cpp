class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position.at(i), speed.at(i)});
        }
        std::sort(pair.begin(), pair.end(), std::greater<std::pair<int, int>>());
        std::vector<double> stack;
        for (const auto& p : pair) {
            stack.push_back(static_cast<double>(target - p.first) / p.second);
            if (stack.size() >= 2 && stack.back() <= stack.at(stack.size() - 2)) {
                stack.pop_back();
            }
        }
        return stack.size();
    }
};;
