class Solution {
public:

    void backtrack(vector<int>& nums, int index,
                   vector<int>& current,
                   vector<vector<int>>& ans) {

        // Add the current subset to the answer
        ans.push_back(current);

        // Try every element from index onwards
        for (int i = index; i < nums.size(); i++) {

            // Include nums[i]
            current.push_back(nums[i]);

            // Recursively generate remaining subsets
            backtrack(nums, i + 1, current, ans);

            // Remove nums[i] (backtracking)
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        backtrack(nums, 0, current, ans);

        return ans;
    }
};
