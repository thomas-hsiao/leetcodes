/*
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.

Example 2:

Input: s = "110"
Output: true

 

Constraints:

    1 <= s.length <= 100
    s[i]​​​​ is either '0' or '1'.
    s[0] is '1'.

*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {

                int j = i + 1;
                while (j < s.size() && s[j] == '1') {
                    ++j;
                }

                if (j - i >= 1) {
                    ++cnt;
                }

                i = j;
            }

            if (cnt > 1) return false;
        }

        return cnt == 1;
    }
};