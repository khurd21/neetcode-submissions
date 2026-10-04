class Solution {
public:
    int characterReplacement(const std::string &s, int k) {
        std::unordered_map<char, int> counts;
        int left{};
        int right{};
        int result{};
        while (left < s.size() && right < s.size()) {
            counts[s.at(right)] += 1;
            ++right;
            if (updateResult(counts, right - left, k, result)) {
                continue;
            }

            while (left < right) {
                counts.at(s.at(left)) -= 1;
                ++left;
                if (updateResult(counts, right - left, k, result)) {
                    break;
                }
            }
        }
        return result;
    }

private:
    bool updateResult(const std::unordered_map<char, int>& map, int substrLen, int k, int& result) {
        const auto dominantLetter{ getDominantLetter(map) };
        const auto numDiffCharacters{ substrLen - dominantLetter.second };
        if (numDiffCharacters <= k) {
            result = std::max(result, substrLen);
            return true;
        }
        return false;
    }

    std::pair<char, int> getDominantLetter(const std::unordered_map<char,int>& map) {
        char letter{};
        int quantity{};
        for (const auto& pair : map) {
            if (pair.second > quantity) {
                letter = pair.first;
                quantity = pair.second;
            }
        }
        return std::make_pair(letter, quantity);
    }
};
