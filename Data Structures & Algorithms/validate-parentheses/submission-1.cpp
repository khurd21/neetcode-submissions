class Solution {
public:
    bool isValid(string s) {
        const unordered_map<char, char> match{
            { '(', ')' },
            { '[', ']' },
            { '{', '}' },
        };
        std::stack<char> stack;
        for (const auto c : s) {
            if (match.count(c)) {
                stack.push(c);
                continue;
            }
            if (stack.empty() || match.at(stack.top()) != c) {
                return false;
            }
            stack.pop();
        }
        return stack.empty();
    }
};
