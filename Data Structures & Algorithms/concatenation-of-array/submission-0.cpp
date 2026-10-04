class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int> nums) {
        nums.insert(nums.end(), nums.cbegin(), nums.cend());
        return nums;
    }
};