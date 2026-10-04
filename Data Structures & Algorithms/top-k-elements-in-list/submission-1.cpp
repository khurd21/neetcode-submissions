class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        std::ranges::for_each(nums, [&](const auto num) {
            counts[num] += 1;
        });

        std::multimap<int, int, std::greater<>> frequency;
        std::ranges::for_each(counts, [&](const auto& pair) {
            frequency.insert({pair.second, pair.first});
        });

        std::vector<int> result;
        std::ranges::for_each(frequency, [&](const auto& pair) {
            if (k-- <= 0) {
                return;
            }
            result.push_back(pair.second);
        });
        return result;
    }
};
