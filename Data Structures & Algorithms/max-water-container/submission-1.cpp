class Solution {
public:
    int maxArea(const std::vector<int>& heights) {
        auto front{ heights.cbegin() };
        auto back{ std::prev(heights.cend()) };
        auto max{ std::numeric_limits<int>::min() };
        while (front < back) {
            const auto distance{ std::distance(front, back) };
            const auto min{ std::min(*front, *back) };
            max = std::max(static_cast<int>(distance * min), max);
            if (*front < *back) {
                ++front;
            }
            else {
                --back;
            }
        }

        return max;
    }
};
