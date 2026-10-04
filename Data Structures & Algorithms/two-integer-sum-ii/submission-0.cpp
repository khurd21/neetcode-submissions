class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
        const auto to_index = [&](const auto& itr) {
            return static_cast<int>(itr - numbers.cbegin()) + 1;
        };
        auto front{ numbers.cbegin() };
        auto back{ std::prev(numbers.cend()) };
        while (front != back) {
            const auto sum{ *front + *back };
            if (sum == target) {
                return { to_index(front), to_index(back) };
            }
            else if (sum > target) {
                back = std::prev(back);
            }
            else {
                front = std::next(front);
            }
        }
        return {};
    }
};
