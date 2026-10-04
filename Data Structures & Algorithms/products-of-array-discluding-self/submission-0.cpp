class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int> nums) {
        const auto exclude_zero = [](const auto total, const auto current) {
            return total * (current == 0 ? 1 : current);
        };
        const auto sum{ std::accumulate(nums.cbegin(), nums.cend(), 1, std::multiplies<>()) };
        const auto sum_excluding_zeroes{ std::accumulate(nums.cbegin(), nums.cend(), 1, exclude_zero) };
        const auto num_zeroes{ std::ranges::count(nums, 0) };
        std::ranges::for_each(nums, [&](auto& num) {
            if (num_zeroes > 1) {
                num = 0;
            }
            else if (num == 0) {
                num = sum_excluding_zeroes;
            }
            else {
                num = sum / num;
            }
        });
        return nums;
    }
};
