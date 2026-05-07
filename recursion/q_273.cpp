/*
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

 

Constraints:

    0 <= num <= 2^31 - 1


*/

class Solution {
private:
    const std::string first_19[20] {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", 
                                    "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", 
                                    "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", 
                                    "Nineteen"};
    const std::string two_digits[10] {"", "", "Twenty", "Thirty", "Forty", "Fifty", 
                                        "Sixty", "Seventy", "Eighty", "Ninety"};
    const std::string three_digits[4] {"", "Thousand", "Million", "Billion"};

    std::string d_to_s(int n) {
        if (n == 0) {
            return "";
        } else if (n < 20) {
            return first_19[n] + " ";
        } else if (n < 100) {
            return two_digits[n / 10] + " " + d_to_s(n % 10);
        }

        return first_19[n / 100] + " Hundred " + d_to_s(n % 100);
    }
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        std::string ans = "";
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                ans = d_to_s(num % 1000) + three_digits[i] + " " + ans;
            }

            num /= 1000;
            ++i;
        }

        while (ans.back() == ' ') ans.pop_back();
        return ans;
    }
};