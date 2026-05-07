/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

 

Constraints:

    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
    s contains only lowercase English letters and spaces ' '.
    s does not contain any leading or trailing spaces.
    All the words in s are separated by a single space.


*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::vector<std::string> words;
        std::stringstream ss(s);
        std::string w;
        while (ss >> w) {
            words.push_back(w);
        }

        if (pattern.size() != words.size()) return false;

        std::unordered_map<char, std::string> c_to_w;
        std::unordered_map<std::string, char> w_to_c;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            std::string w = words[i];

            if (c_to_w.count(c) && c_to_w[c] != w) return false;

            if (w_to_c.count(w) && w_to_c[w] != c) return false;

            c_to_w[c] = w;
            w_to_c[w] = c;
        }

        return true;
    }
};