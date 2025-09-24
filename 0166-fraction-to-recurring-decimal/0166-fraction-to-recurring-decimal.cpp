class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        if ((numerator < 0) ^ (denominator < 0)) result.push_back('-');

        long num = labs((long)numerator);
        long den = labs((long)denominator);

        result += to_string(num / den);
        long remainder = num % den;
        if (remainder == 0) return result;

        result.push_back('.');
        unordered_map<long, int> mp;
        while (remainder != 0) {
            if (mp.count(remainder)) {
                result.insert(mp[remainder], "(");
                result.push_back(')');
                return result;
            }
            mp[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / den);
            remainder %= den;
        }
        return result;
    }
};