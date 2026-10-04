class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }

        int left{};
        int right( height.size() - 1 );
        int leftMax{ height.at(left) };
        int rightMax{ height.at(right) };
        int result{};
        while (left < right) {
            if (leftMax < rightMax) {
                ++left;
                leftMax = std::max(leftMax, height.at(left));
                result += leftMax - height.at(left);
            }
            else {
                --right;
                rightMax = std::max(rightMax, height.at(right));
                result += rightMax - height.at(right);
            }
        }
        return result;
    }
};
