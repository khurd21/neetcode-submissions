class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> v;
        std::string s;
        generateParens(v, s, 0, 0, n);
        return v;
    }

private:
    void generateParens(std::vector<std::string>& v, std::string& s, int open, int closed, int n) {
        if (closed == open && open == n) {
            v.push_back(s);
            return;
        }

        if (open < n) {
            s += "(";
            generateParens(v, s, open + 1, closed, n);
            s.pop_back();
        }
        if (closed < open) {
            s += ")";
            generateParens(v, s, open, closed + 1, n);
            s.pop_back();
        }
    }
};
