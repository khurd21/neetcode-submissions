std::string normalizeStr(const std::string& s) {
    std::string result;
    std::ranges::for_each(s, [&](const auto c) {
        if (std::isalpha(c)) {
            result += std::tolower(c);
        }
        if (std::isdigit(c)) {
            result += c;
        }
    });
    return result;
}

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        std::string normalized{ normalizeStr(s) };
        auto copy{ normalized };
        std::ranges::reverse(copy);
        return copy == normalized;
    }
};
