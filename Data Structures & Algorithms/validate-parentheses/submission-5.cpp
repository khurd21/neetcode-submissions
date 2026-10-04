class Solution {
public:
    bool isValid(const std::string& s) {
        if (s.size() % 2 != 0) {
            return false;
        }

        std::stack<char> st;
        const std::unordered_map<char, char> to_closed = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };
        for (const auto c : s) {
            if (to_closed.contains(c)) {
                st.push(c);
                continue;
            }
            if (st.empty()) {
                return false;
            }
            if (to_closed.at(st.top()) != c) {
                return false;
            }
            st.pop();
        }

        return st.empty();
    }
};
