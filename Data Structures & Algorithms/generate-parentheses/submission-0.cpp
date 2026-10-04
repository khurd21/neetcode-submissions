class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string s;
        generateParens(s, result, 0, 0, n);
        return result;
    }

private:
    void generateParens(std::string& s, std::vector<std::string>& v, int closed, int open, int n) {
        if (open == closed && open == n) {
            v.push_back(s);
            return;
        }

        if (open < n) {
            s += "(";
            generateParens(s, v, closed, open + 1, n);
            s.pop_back();
        }
        if (closed < open) {
            s += ")";
            generateParens(s, v, closed + 1, open, n);
            s.pop_back();
        }
    }
};
