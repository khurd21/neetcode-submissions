class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> set;
        std::size_t left{};
        std::size_t right{};
        int answer{};
        for (const auto c : s) {
            while (set.count(c)) {
                set.erase(s.at(left));
                ++left;
            }
            set.insert(c);
            answer = std::max(answer, static_cast<int>(set.size()));
        }
        return answer;
    }
};
