namespace {

const std::unordered_map<std::string, std::function<int(int, int)>> m{
    { "+", std::plus<>() },
    { "-", std::minus<>() },
    { "*", std::multiplies<>() },
    { "/", std::divides<>() },
};

}

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> s;
        std::ranges::for_each(tokens, [&](const auto& token) {
            if (m.contains(token)) {
                const auto rhs{ s.top() };
                s.pop();
                const auto lhs{ s.top() };
                s.pop();
                s.push(m.at(token)(lhs, rhs));
                return;
            }
            s.push(std::stoi(token));
        });
        return s.top();
    }
};
