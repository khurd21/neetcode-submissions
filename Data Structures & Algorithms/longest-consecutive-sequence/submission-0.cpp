class Solution {
public:
    int longestConsecutive(const std::vector<int>& nums) {
        int result{};
        std::unordered_set<int> s{ nums.cbegin(), nums.cend() };
        std::ranges::for_each(s, [&](auto num) {
            if (s.contains(num - 1)) {
                return;
            }

            int count{ 1 };
            while (s.contains(++num)) {
                ++count;
            }
            result = std::max(result, count);
        });

        return result;
    }
};
