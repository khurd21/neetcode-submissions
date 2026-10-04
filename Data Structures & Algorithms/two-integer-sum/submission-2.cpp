class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, std::vector<int>> m;
        for (int i{}; i < nums.size(); ++i) {
            m[nums.at(i)].push_back(i);
        }

        for (auto num : nums) {
            const auto complement{ target - num };
            if (!m.contains(complement)) {
                continue;
            }
            if (complement == num && m.at(num).size() <= 1) {
                continue;
            }
            if (complement == num) {
                return m.at(complement);
            }
            return { m.at(num).at(0), m.at(complement).at(0) };
        }

        return {};
    }
};
