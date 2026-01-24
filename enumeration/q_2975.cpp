/*
There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.

Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).

Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.

Since the answer may be large, return it modulo 109 + 7.

Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

 

Example 1:

Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
Output: 4
Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.

Example 2:

Input: m = 6, n = 7, hFences = [2], vFences = [4]
Output: -1
Explanation: It can be proved that there is no way to create a square field by removing fences.

 

Constraints:

    3 <= m, n <= 10^9
    1 <= hFences.length, vFences.length <= 600
    1 < hFences[i] < m
    1 < vFences[i] < n
    hFences and vFences are unique.


*/

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);
        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);

        std::unordered_set<int> all_len;
        int h_len = hFences.size();
        for (int i = 0; i < h_len - 1; ++i) {
            for (int j = i + 1; j < h_len; ++j) {
                all_len.insert(std::abs(hFences[j] - hFences[i]));
            }
        }

        long max_len = -1;
        int v_len = vFences.size();
        for (int i = 0; i < v_len - 1; ++i) {
            for (int j = i + 1; j < v_len; ++j) {
                int dist = std::abs(vFences[j] - vFences[i]);
                if (all_len.find(dist) != all_len.end()) {
                    max_len = std::max(max_len, (long)dist);
                }
            }
        }

        if (max_len == -1) return -1;

        return (max_len * max_len) % 1'000'000'007;
    }
};