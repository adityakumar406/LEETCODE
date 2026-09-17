class Solution {
public:

    void backtrack(vector<int>& nums, int index,
                   vector<int>& current,
                   vector<vector<int>>& ans) {

        // Store the current subset
        ans.push_back(current);

        // Try choosing each element
        for (int i = index; i < nums.size(); i++) {

            // Skip duplicate elements at the same level
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            // Choose the element
            current.push_back(nums[i]);

            // Explore further
            backtrack(nums, i + 1, current, ans);

            // Undo the choice
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        // Sort so duplicate elements are together
        sort(nums.begin(), nums.end());

        // Start backtracking
        backtrack(nums, 0, current, ans);

        return ans;
    }
};