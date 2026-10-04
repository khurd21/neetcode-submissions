class Solution {
public:
    bool checkInclusion(const std::string& s1, const std::string& s2) {
        if (s2.size() < s1.size()) {
            return false;
        }

        std::unordered_map<char, int> counts1;
        for (const auto c : s1) {
            counts1[c] += 1;
        }

        std::unordered_map<char, int> counts2;
        for (int i{}; i < s1.size() - 1; ++i) {
            counts2[s2.at(i)] += 1;
        }

        int left{};
        int right( s1.size() - 1 );
        while (right < s2.size()) {
            counts2[s2.at(right)] += 1;
            if (counts1 == counts2) {
                return true;
            }
            counts2[s2.at(left)] -= 1;
            if (counts2.at(s2.at(left)) == 0) {
                counts2.erase(s2.at(left));
            }
            ++right;
            ++left;
        }

        return false;
    }
};
