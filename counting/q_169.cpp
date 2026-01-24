/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

 

Constraints:

    n == nums.length
    1 <= n <= 5 * 10^4
    -10^9 <= nums[i] <= 10^9

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 0;
        int major = 0;

        for (int n : nums) {
            if (!vote) {
                major = n;
                ++vote;
            } else if (major == n) {
                ++vote;
            } else {
                --vote;
            }
        }

        return major;
    }
};