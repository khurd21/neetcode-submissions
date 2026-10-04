class Solution {
public:

    std::string encode(const std::vector<std::string>& strs) {
        std::string result;
        for (const auto& str : strs) {
            result += std::to_string(str.size()) + "#" + str;
        }
        return result;
    }

    std::vector<std::string> decode(const std::string& s) {
        std::size_t index{};
        std::vector<std::string> result;
        while (index < s.size()) {
            const auto length = getNextSize(s, index);
            result.push_back(s.substr(index, length));
            index += length;
        }
        return result;
    }

private:
    std::size_t getNextSize(const std::string& s, std::size_t& index) {
        std::size_t size{};
        while (index < s.size() && std::isdigit(s.at(index))) {
            size *= 10;
            size += static_cast<std::size_t>(s.at(index) - '0');
            ++index;
        }
        ++index;
        return size;
    }
};
