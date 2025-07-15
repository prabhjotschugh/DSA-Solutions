#include <cctype>
#include <string>
#include <unordered_set>

class Solution {
public:
    bool isValid(const std::string& word) {
        if (word.size() < 3) return false;

        static const std::unordered_set<char> vowel{
            'a','e','i','o','u','A','E','I','O','U'};
        int v = 0, c = 0;

        for (char ch : word) {
            if (std::isdigit(static_cast<unsigned char>(ch))) continue;

            if (std::isalpha(static_cast<unsigned char>(ch))) {
                vowel.count(ch) ? ++v : ++c;
            } else {
                return false;               
            }
        }
        return v > 0 && c > 0;
    }
};