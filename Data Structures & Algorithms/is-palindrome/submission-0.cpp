#include <cctype>
#include <string>
class Solution {
public:
    bool isPalindrome(string s) {
        // isalnum(char) return true if the character is an alphabet letter or a number
        // tolower(char) converts uppercase to lowercase
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
