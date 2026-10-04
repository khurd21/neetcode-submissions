class Solution {
public:

    std::string encode(const std::vector<std::string>& strs) {
        std::string result;
        std::ranges::for_each(strs, [&](const auto& s) {
            result += std::format("{}.{}", s.size(), s);
        });
        return result;
    }

    std::vector<std::string> decode(std::string s) {
        // 0.0.0. -> "" "" ""
        // 0.1.a2.ab0. "" "a" "ab" ""
        std::string number_as_str;
        std::optional<int> size;
        std::string decoded;
        std::vector<std::string> result;
        const auto check = [&] {
            if (size.has_value() && size.value() == 0) {
                result.push_back(std::move(decoded));
                size = std::nullopt;
                decoded = {};
                number_as_str = {};
            }
        };
        std::ranges::for_each(s, [&](const auto c) {
            check();
            if (!size.has_value() && std::isdigit(c)) {
                number_as_str += c;
            }
            else if (!size.has_value() && c == '.') {
                size = std::stoi(number_as_str);
                number_as_str = {};
            }
            else if (size.has_value()) {
                size.value() -= 1;
                decoded += c;
            }
        });
        check();
        return result;
    }
};
