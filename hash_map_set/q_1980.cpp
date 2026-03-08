/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.

 

Example 1:

Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.

Example 2:

Input: nums = ["00","01"]
Output: "11"
Explanation: "11" does not appear in nums. "10" would also be correct.

Example 3:

Input: nums = ["111","011","001"]
Output: "101"
Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.

 

Constraints:

    n == nums.length
    1 <= n <= 16
    nums[i].length == n
    nums[i] is either '0' or '1'.
    All the strings of nums are unique.

*/

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int b_len = nums[0].size();
        int n = nums.size();
        std::unordered_set<int> nums_set;
        for (int i = 0; i < n; ++i) {
            int val = 0;
            for (int j = 0; j < b_len; ++j) {
                val += (nums[i][j] - '0') * (1 << (b_len - j - 1));
            }

            nums_set.insert(val);
        }

        for (int i = 0; i < (1 << b_len); ++i) {
            if (nums_set.find(i) == nums_set.end()) {

                std::string ans(b_len, '0');
                int j = b_len - 1;
                int val = i;
                while (val > 0) {
                    ans[j] = (val % 2) + '0';
                    val >>= 1;
                    --j;
                }

                return ans;
            }
        }

        return "";
    }
};
