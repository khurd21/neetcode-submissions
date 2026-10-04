class Solution {
public:
    int characterReplacement(string s, int k) {
        std::unordered_map<char, int> counts;
        int left{};
        int right{};
        int result{};
        while (left < s.size() && right < s.size()) {
            counts[s.at(right)] += 1;
            ++right;
            const auto dominantLetter{ getDominantLetter(counts) };
            const auto numDiffCharacters{ (right - left) - dominantLetter.second };
            if (numDiffCharacters <= k) {
                result = std::max(result, (right - left));
            }
            else while (left < right) {
                counts.at(s.at(left)) -= 1;
                ++left;
                const auto dominantLetter{ getDominantLetter(counts) };
                const auto numDiffCharacters{ (right - left) - dominantLetter.second };
                if (numDiffCharacters <= k) {
                    result = std::max(result, right - left);
                    break;
                }
            }
        }
        return result;
    }

private:
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
