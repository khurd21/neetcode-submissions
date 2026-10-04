class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (const auto c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
                continue;
            }
            if (stack.empty()) {
                return false;
            }
            if (c == ')' && stack.top() != '(') {
                return false;
            }
            if (c == ']' && stack.top() != '[') {
                return false;
            }
            if (c == '}' && stack.top() != '{') {
                return false;
            }
            stack.pop();
        }
        return stack.empty();
    }
};
