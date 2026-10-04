class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> m;
        std::ranges::for_each(strs, [&](const auto& s) {
            auto copy{ s };
            std::ranges::sort(copy);
            m[copy].push_back(s);
        });

        std::vector<std::vector<std::string>> result;
        std::ranges::for_each(m, [&](auto& kv) {
            result.push_back(std::move(kv.second));
        });
        return result;
    }
};
