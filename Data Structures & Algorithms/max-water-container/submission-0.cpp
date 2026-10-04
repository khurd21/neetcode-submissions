class Solution {
public:
    int maxArea(const std::vector<int>& heights) {
        auto back{ heights.cend() - 1 };
        auto front{ heights.cbegin() };
        int result{};
        while (front < back) {
            const auto quantity{ static_cast<int>(back - front) * std::min(*front, *back) };
            result = std::max(result, quantity);
            *front < *back ? ++front : --back;
        }
        return result;
    }
};
