class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used) {
        // If current permutation has all elements
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Try every number
        for (int i = 0; i < nums.size(); i++) {

            // Skip if this number is already used
            if (used[i])
                continue;

            // Choose
            current.push_back(nums[i]);
            used[i] = true;

            // Explore
            backtrack(nums, current, used);

            // Undo choice (backtrack)
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, used);

        return ans;
    }
};