namespace {

auto validate(char num, auto& cache) {
    if (num == '.') {
        return true;
    }
    if (cache.contains(num)) {
        return false;
    }
    if (num < '1' || num > '9') {
        return false;
    }
    cache.insert(num);
    return true;
}

auto checkColumns(const auto& board) {
    for (int c{}; c < board.size(); ++c) {
        std::unordered_set<char> found;
        for (int i{}; i < board.at(c).size(); ++i) {
            const auto num{ board.at(i).at(c) };
            if (!validate(num, found)) {
                return false;
            }
        }
    }
    return true;
}

auto checkRows(const auto& board) {
    for (const auto& row : board) {
        std::unordered_set<int> found;
        for (const auto num : row) {
            if (!validate(num, found)) {
                return false;
            }
        }
    }
    return true;
}

auto checkSubBoxes(const auto& board) {
    for (int i{}; i < board.size(); i += 3) {
        for (int j{}; j < board.at(i).size(); j += 3) {
            std::unordered_set<int> found;
            for (auto ir{ i }; ir < i + 3; ++ir) {
                for (auto jr{ j }; jr < j + 3; ++jr) {
                    const auto num{ board.at(ir).at(jr) };
                    if (!validate(num, found)) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

}

class Solution {
public:
    static bool isValidSudoku(vector<vector<char>>& board) {
        return checkColumns(board) && checkRows(board) && checkSubBoxes(board);
    }
};
