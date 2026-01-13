/*
Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

 

Constraints:

    1 <= nums.length <= 10^5
    0 <= nums[i] <= 10^9


*/

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int i = 0; i < n; ++i) {
            min_val = std::min(min_val, nums[i]);
            max_val = std::max(max_val, nums[i]);
        }

        if (min_val == max_val) return 0;

        int width = std::max(1, (max_val - min_val + (n -2 )) / (n - 1));
        int buckets = (max_val - min_val) / width + 1;
        std::vector<int> bucket_min(buckets, INT_MAX);
        std::vector<int> bucket_max(buckets, INT_MIN);
        std::vector<int> used(buckets);

        for (int v : nums) {
            int i = (v - min_val) / width;
            used[i] = true;
            bucket_min[i] = std::min(bucket_min[i], v);
            bucket_max[i] = std::max(bucket_max[i], v);
        }

        int ans = 0;
        int prev_max = min_val;
        bool prev_set;
        for (int i = 0; i < buckets; ++i) {
            if (!used[i]) continue;

            if (prev_set) ans = std::max(ans, bucket_min[i] - prev_max);
            prev_max = bucket_max[i];
            prev_set = true;
        }

        return ans;
    }
};