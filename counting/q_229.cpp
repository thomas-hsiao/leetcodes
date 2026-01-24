/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]

Example 2:

Input: nums = [1]
Output: [1]

Example 3:

Input: nums = [1,2]
Output: [1,2]

 

Constraints:

    1 <= nums.length <= 5 * 10^4
    -10^9 <= nums[i] <= 10^9

*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int m1 = 0;
        int m2 = 1;

        for (int n : nums) {
            if (n == m1) {
                ++cnt1;
            } else if (n == m2) {
                ++cnt2;
            } else if (cnt1 == 0) {
                m1 = n;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                m2 = n;
                cnt2 = 1;
            } else {
                --cnt1;
                --cnt2;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for (int n : nums) {
            if (n == m1) {
                ++cnt1;
            } else if (n == m2) {
                ++cnt2;
            }
        }

        std::vector<int> ans;
        if (cnt1 > nums.size() / 3) {
            ans.push_back(m1);
        }
        if (cnt2 > nums.size() / 3) {
            ans.push_back(m2);
        }

        return ans;
    }
};