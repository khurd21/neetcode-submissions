class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> s(nums.cbegin(), nums.cend());
        return s.size() != nums.size();
    }
};