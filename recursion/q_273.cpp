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
    const std::vector<std::string> first_19{ "", "One", "Two", "Three", "Four", "Five", 
                                            "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", 
                                            "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", 
                                            "Seventeen",  "Eighteen", "Nineteen" };
    const std::vector<std::string> two_digits{"", "", "Twenty", "Thirty", "Forty", "Fifty", 
                                                    "Sixty", "Seventy", "Eighty", "Ninety" };
    const std::vector<std::string> three_digits{ "", "Thousand", "Million", "Billion" };

    std::string recursive(int n) {
        if (n == 0) {
            return "";
        } else if (n < 20) {
            return first_19[n] + " ";
        } else if (n < 100) {
            return two_digits[n / 10] + " " + recursive(n % 10);
        }

        return first_19[n / 100] + " Hundred " + recursive(n % 100);
    }
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }

        std::string ans = "";
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                ans = recursive(num % 1000) + three_digits[i] + " " + ans;
            }

            num /= 1000;
            ++i;
        }
        
        while (ans.back() == ' ') ans.pop_back();
        return ans;
    }
};