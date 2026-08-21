class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Store unique elements of nums1
        unordered_set<int> set1(nums1.begin(), nums1.end());

        // Store the intersection
        unordered_set<int> result;

        // Check each element of nums2
        for (int num : nums2) {
            if (set1.count(num)) {
                result.insert(num);
            }
        }

        // Convert set to vector
        return vector<int>(result.begin(), result.end());
    }
};