class Solution {
public:
    int evalRPN(const std::vector<std::string>& tokens) {
        std::stack<int> s;
        for (const auto& token : tokens) {
            if (token == "+") {
                const auto pair{ getTokens(s) };
                const auto left{ pair.first };
                const auto right{ pair.second };
                s.push(left + right);
            }
            else if (token == "-") {
                const auto pair{ getTokens(s) };
                const auto left{ pair.first };
                const auto right{ pair.second };
                s.push(left - right);
            }
            else if (token == "*") {
                const auto pair{ getTokens(s) };
                const auto left{ pair.first };
                const auto right{ pair.second };
                s.push(left * right);
            }
            else if (token == "/") {
                const auto pair{ getTokens(s) };
                const auto left{ pair.first };
                const auto right{ pair.second };
                s.push(left / right);
            }
            else {
                s.push(std::stoi(token));
            }
        }
        return s.top();
    }

private:
    std::pair<int, int> getTokens(std::stack<int>& s) {
        const auto right{ s.top() };
        s.pop();
        const auto left{ s.top() };
        s.pop();
        return { left, right };
    }
};
